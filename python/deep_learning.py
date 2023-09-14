import convert_bin as cb
import db_input_kifu as dik
from sql_setting import *
from sqlalchemy import Row, Select, select
import pandas as pd
from typing import List
from enum import IntEnum
import numpy as np
import tensorflow as tf
import matplotlib.pyplot as plt
from cshogi import Board
from cshogi.usi import Engine
import copy
import random
from datetime import datetime, timedelta

class LearnData(IntEnum):
    BOARD = 1
    MOVE = 2
    OUTPUT = 3

class ModelType(IntEnum):
    PROBABILITY_WIN = 1
    PRUNE = 2
    MOVE = 3

def getLearnData(limit: int = 1000, type: ModelType = ModelType.PROBABILITY_WIN) -> List[Row]:
    query: Select[Any]
    if type == ModelType.PROBABILITY_WIN:
        parent = select(dik.Node).subquery("p")
        query = select(
            parent.c.board,
            dik.Node.move,
            (dik.Node.drawCount / dik.Node.throughCount).label("probabilityOfDraw"),
            (dik.Node.firstWinCount / dik.Node.throughCount).label("probabilityOfFirstWin"),
            (dik.Node.secondWinCount / dik.Node.throughCount).label("probabilityOfSecondWin")
        ).join(
            parent,
            dik.Node.parentId == parent.c.ID
        ).limit(limit)
    elif type == ModelType.PRUNE:
        query = select(
            dik.Node.board,
            (dik.Node.drawCount / dik.Node.throughCount).label("probabilityOfDraw"),
            (dik.Node.firstWinCount / dik.Node.throughCount).label("probabilityOfFirstWin"),
            (dik.Node.secondWinCount / dik.Node.throughCount).label("probabilityOfSecondWin")
        ).order_by(dik.Node.turnNumber).limit(limit)
    elif type == ModelType.MOVE:
        parent = select(dik.Node).subquery("p")
        query = select(
            parent.c.board,
            dik.Node.move,
        ).join(
            parent,
            dik.Node.parentId == parent.c.ID
        ).limit(limit)
    results = list(session.execute(query))
    return results

def convertToDataFrame(data: List[Row]) -> pd.DataFrame:
    return pd.DataFrame(data)

def selectionLearnData(data: pd.DataFrame, type: LearnData) -> pd.DataFrame:
    length = len(data)
    if type == LearnData.BOARD:
        nparray = np.zeros((length, 615), dtype= float)
        for index in range(length):
            nparray[index] = cb.convertForBoard(data['board'][index])
        return pd.DataFrame(nparray)
    elif type == LearnData.MOVE:
        nparray = np.zeros((length, 32), dtype= float)
        for index in range(length):
            nparray[index] = cb.convertForMove(data['move'][index])
        return pd.DataFrame(nparray)
    else:
        result = data[[
            'probabilityOfDraw',
            'probabilityOfFirstWin',
            'probabilityOfSecondWin'
        ]]
        result['probabilityOfDraw'] = result['probabilityOfDraw'].astype(float)
        result['probabilityOfFirstWin'] = result['probabilityOfFirstWin'].astype(float)
        result['probabilityOfSecondWin'] = result['probabilityOfSecondWin'].astype(float)
        return result
    
def createModel(type: ModelType = ModelType.PROBABILITY_WIN) -> tf.keras.Model:
    if type == ModelType.PROBABILITY_WIN:
        m_input_board = tf.keras.Input(shape=615)
        m_input_move = tf.keras.Input(shape=32)
        m_inputs = tf.keras.layers.concatenate([m_input_board, m_input_move])
        m_hide1 = tf.keras.layers.Dense(615, activation="relu")(m_inputs)
        m_hide2 = tf.keras.layers.Dense(128, activation="relu")(m_hide1)
        m_output = tf.keras.layers.Dense(3, activation="softmax", name="output")(m_hide2)
        model = tf.keras.Model(inputs= [m_input_board, m_input_move], outputs= m_output)
    elif type == ModelType.PRUNE:
        m_input = tf.keras.Input(shape=615)
        m_hide1 = tf.keras.layers.Dense(32, activation="relu")(m_input)
        m_hide2 = tf.keras.layers.Dense(8, activation="relu")(m_hide1)
        m_output = tf.keras.layers.Dense(3, activation="softmax", name="output")(m_hide2)
        model = tf.keras.Model(inputs= m_input, outputs= m_output)
    elif type == ModelType.MOVE:
        m_input = tf.keras.Input(shape=615)
        m_hide1 = tf.keras.layers.Dense(615, activation="relu")(m_input)
        m_hide2 = tf.keras.layers.Dense(256, activation="relu")(m_hide1)
        m_output = tf.keras.layers.Dense(32, activation="relu", name="output")(m_hide2)
        model = tf.keras.Model(inputs= m_input, outputs= m_output)
    return model

def compileModel(model: tf.keras.Model):
    model.compile(loss='mean_squared_error', optimizer='sgd', metrics=['mae', 'acc'])

def inputModel(path: str) -> tf.keras.Model:
    return tf.keras.models.load_model(path)

def learning(model: tf.keras.Model, epochs: int, path: str, input, output):
    history = model.fit(input, output, epochs=epochs)
    model.save(path)
    return history

def printLearnData(history):
    fig = plt.figure(figsize = (20, 16), facecolor= 'lightblue')
    ax1 = fig.add_subplot(2, 2, 1)
    ax2 = fig.add_subplot(2, 2, 2)

    ax1.plot(history.history['loss'], label='loss')
    ax1.set_xlabel('Epoch')
    ax1.set_ylabel('Loss')
    ax1.legend(loc='upper right')

    ax2.plot(history.history['acc'], label='output_accuracy')
    ax2.plot(history.history['mae'], label='output_mae')
    ax2.set_xlabel('Epoch')
    ax2.set_ylabel('Accuracy')
    ax2.legend(loc='lower right')

def predict(model: tf.keras.Model, input):
    return model.predict(input, verbose=0)

# ランダムに手を指し続ける
def ramdomMove(board: Board, secondfor: int) -> int:
    endtime = datetime.now() + timedelta(seconds=secondfor)
    moves = list(board.legal_moves)
    boards = []
    for move in moves:
        test_board = copy.copy(board)
        test_board.push(move)
        boards.append(test_board)

    indexs = [i for i in moves]
    results = pd.DataFrame(0.0, columns=['draw', 'first', 'second', 'total', 'winning percentage'], index=[indexs])
    count = 0
    while True:
        selected = random.randint(0, len(moves) - 1)
        copiedBoard = copy.copy(boards[selected])
        result = dik.fight(copiedBoard, False)
        targetColumn = ''
        if result == dik.Winner.DRAW:
            targetColumn = 'draw'
        elif result == dik.Winner.FIRST:
            targetColumn = 'first'
        else:
            targetColumn = 'second'
        results.loc[moves[selected], targetColumn] += 1.0
        results.loc[moves[selected], 'total'] += 1.0
        count += 1
        if datetime.now() > endtime:
            break
    wins = results.loc[:, 'second'] if board.turn else results.loc[:, 'first']
    for index in results.index.values:
        results.loc[index[0], 'winning percentage'] = wins[index[0]] / results.loc[index[0], 'total']
    return results.loc[:,'winning percentage'].idxmax()[0]

def loadEngine(path: str) -> Engine:
    return Engine(path)

def useEngine(board: Board, engine: Engine, msecondFor: int = 1000) -> int:
    engine.isready()
    engine.position(sfen=board.sfen())
    bestmove = engine.go(byoyomi=msecondFor)[0]
    return board.move_from_usi(bestmove)