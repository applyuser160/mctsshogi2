import os
from dotenv import load_dotenv
import sqlalchemy as sa
from sqlalchemy.engine.url import URL
from sqlalchemy.orm import *

load_dotenv('../.env')
url = URL.create(
    drivername="mysql",
    username=os.getenv('USER'),
    password=os.getenv('PIN'),
    host=os.getenv('HOST'),
    port=int(os.getenv('PORT')),
    database=os.getenv('DB'),
    query={"charset": "utf8"}
)
ENGINE = sa.create_engine(url, echo=False)
session = scoped_session(
    sessionmaker(
        autocommit=False, 
        autoflush=False, 
        bind=ENGINE
    )
)