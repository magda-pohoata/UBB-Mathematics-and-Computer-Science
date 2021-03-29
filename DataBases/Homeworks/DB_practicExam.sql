create database Practic_Exam
go
use Practic_exam
go

create table Tournaments(
TID int primary key,
TName varchar(50),
startDate date,
endDate date)

insert into Tournaments values(1,'a','1/2/2020','2/3/2020'),(2,'b','1/2/2020','2/3/2020'),(3,'c','1/2/2020','2/3/2020'),(4,'d','1/2/2020','2/3/2020')

create table Courts(
CID int primary key,
TID int foreign key references Tournaments(TID),
CName varchar(50),
capacity int)

insert into Courts values(11, 2,'aa',1200),(12,1,'ab',1222),(13,2,'ar',1223),(14,3,'ae',1224),(15,2,'rr',1234)

create table Players(
PID int primary key,
PName varchar(50),
prize_money int,
no_points_beginning int)

insert into Players values(111,'Simona Halep',1234,290),(112,'asb',1235,111),(113,'rts',3589,100),(114,'ryf',345,100)

create table Matches(
MID int primary key,
CID int foreign key references Courts(CID),
PID1 int foreign key references Players(PID),
PID2 int foreign key references Players(PID),
date_time datetime)

insert into Matches values(222,11,111,112,'1/2/2020 4:15'),(223,12,111,113,'1/2/2020 6:20'),(224,11,113,112,'2/2/2020 1:15')

create table MatchesPlayers(
PID int foreign key references Players(PID),
MID int foreign key references Matches(MID),
prize_money int,
no_points int,
constraint pk_MP primary key (PID,MID))


insert into MatchesPlayers values(111,222,130,13),(111,223,130,13),(112,222,140,10),(112,224,110,10)
go 

--Implement a stored procedure that receives a court, 2 players, a date and time, and adds the corresponding match to the database.
create or alter proc Add_Match @mid int ,@cid int,@pid1 int,@pid2 int ,@dt datetime
as
declare @nr int;
set @nr = 0;
select @nr = count(*) from Matches where MID=@mid
if(@nr<>0) 
	begin
		update Matches
		set CID=@cid,PID1=@pid1,PID2=@pid2,date_time=@dt
		where MID=@mid
	end
else 
	begin
		insert into Matches values (@mid,@cid,@pid1,@pid2,@dt)
	end
go

exec Add_Match 225,13,113,114,'2/3/2020 3:15'

select * from Matches
go

--Implement a function that returns the names of the courts where Simona Halep is scheduled to play at least P matches, where P is a function parameter.	
create or alter function fct_CourtsSimona(@p int)
returns table
as
return
select distinct c.CName, count(*) as MatchesPlay
from Courts c,Matches m, Players p
where c.CID=m.CID and (m.PID1=p.PID or m.PID2=p.PID) and p.PName='Simona Halep'
group by c.CName
having count(*)>=@p
go

select * from fct_CourtsSimona(1)
go



--Create a view that shows the number of matches for every court (court name, total number of matches).
create or alter view NoMatcherCourt
as
select c.CName,count (*) as NoMatches
from Courts c inner join Matches m on c.CID=m.CID
group by c.CName
go

select * from NoMatcherCourt