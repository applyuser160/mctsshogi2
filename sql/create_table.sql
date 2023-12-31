create table [DBNAME].[TABLENAME] (
  ID varchar(100) not null
  , parentID varchar(100) null
  , turnNumber int(10) not null 
  , `move` int(10) not null 
  , `board` varchar(150) not null 
  , throughCount int(10) not null
  , drawCount int(10) not null 
  , firstWinCount int(10) not null 
  , secondWinCount int(10) not null 
  , constraint Node_PKC primary key (ID)
);
create index turnNumber_index on [DBNAME].[TABLENAME](turnNumber);
create index parentID_index on [DBNAME].[TABLENAME](parentID);
create index unique_index on [DBNAME].[TABLENAME](parentID, turnNumber, `move`, `board`);