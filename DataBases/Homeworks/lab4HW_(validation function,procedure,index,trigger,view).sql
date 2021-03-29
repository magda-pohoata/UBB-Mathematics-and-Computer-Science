create database lab4HW
go
use lab4HW
go


--1. implement a stored procedure for the INSERT operation on a table;
--the procedure’s parameters should describe the entities / relationships
--in the table; the procedure should use at least 2 user-defined functions
--to validate certain parameters;


--checks if the variable is a positive number
create or alter function checkInt(@no int)
returns bit as
begin
	declare @n bit
	if @no>=0 
		set @n=1
	else
		set @n=0
	return @n
end
go 

--checks if the variable contains at least one character
create or alter function checkVarchar(@sname varchar(50))
returns bit as
begin
	declare @b bit
	if @sname LIKE '[a-z]%' OR @sname like '[A-Z]%'
		set @b=1
	else
		set @b=0
	return @b
end
go


create or alter procedure addStores @stid int, @sname varchar(50), @no int,@cat varchar(50),@size int
as
begin

if dbo.checkInt(@stid)=1 and dbo.checkVarchar(@sname)=1
	begin
		insert into Stores(stid,sname,no_employees,category,size) values (@stid, @sname, @no, @cat, @size)
		print 'values added'
		select * from Stores
	end
else
	begin
		print 'the parameters are not correct, try again'
		select * from Stores
	end
end
go


exec addStores @stid=1,@sname='Auchan',@no=35,@cat='supermarket',@size=600
go
select * from Stores
go
delete from Stores where Stores.stid=1
go


create or alter function checkInt1(@stid int)
returns int as
begin
	declare @no int
	if exists (select S.stid from Stores S where S.stid=@stid) 
		set @no=1
	else
		set @no=0
	return @no
end
go 

create or alter function checkVarchar1(@material varchar(50))
returns bit as
begin
	declare @b bit
	if @material LIKE '[a-z]%' or @material like '[A-Z]%'
		set @b=1
	else
		set @b=0
	return @b
end
go

create or alter procedure addClothes @cid int, @material varchar(50),@color varchar(50),@season varchar(50),@stid int
as
begin

if dbo.checkInt1(@stid)=1 and dbo.checkVarchar1(@material)=1
	begin
		insert into Clothes(cid,material,color,season,stid) values (@cid,@material,@color,@season,@stid);
		print 'values added'
		select * from Clothes
	end
else
	begin
		print 'the parameters are not correct, try again'
		select * from Clothes
	end
end
go

exec addClothes 7,'a','b','c',222
go

delete from Clothes where cid=7
select * from Clothes
select * from ClothesCopy
go

select * from Logs
go



--2. create a view that operates on at least 4 tables; write a SELECT on the view returning information that
--is useful to a potential user; 

--select the names of the directors of the malls where Maria Lazar is the manager of a store
create or alter view oneView
as
select M.mname,D.dname
from Manager M,Stores S,StoresInMalls SM,Malls Ms,Directors D where M.maid=S.stid
and S.stid=SM.stid
and SM.mid=Ms.mid
and D.did=Ms.mid
and M.mname='Maria Lazar'
go

select * from oneView
go


--3. implement a trigger for a table, for INSERT, UPDATE, and DELETE; the trigger will introduce the
--following data in a log table: the date and time of the triggering statement, its type (INSERT / UPDATE
--/ DELETE), the name of the affected table, and the number of added / modified / removed records; 

create table Logs(
TriggerDate date,
TriggerType varchar(50),
NameAffectedTable varchar(50),
NoAMDRows int)

select * from Logs
go

delete from Logs
go

/*
create table ClothesCopy(cid int primary key,
material varchar(50) not null,
color varchar(50),
season varchar(50),
stid int foreign key references Stores(stid)
)
go 
*/

create or alter trigger Add_Clothes ON Clothes for insert as
begin
	/*insert into ClothesCopy(cid, material,color,season,stid)
	select cid, material,color,season,stid
	from inserted
	*/
	 insert into Logs(TriggerDate, TriggerType,NameAffectedTable, NoAMDRows)
	values (GETDATE(), 'INSERT', 'Clothes', @@ROWCOUNT)
	
end
go


create or alter trigger Delete_Clothes ON Clothes for delete as
begin
	/*delete from ClothesCopy where ClothesCopy.cid=cid
	select cid, material,color,season,stid
	from deleted
	*/
	 insert into Logs(TriggerDate, TriggerType,NameAffectedTable, NoAMDRows)
	values (GETDATE(), 'DELETE', 'Clothes', @@ROWCOUNT)
	
end
go

exec addClothes @cid=7,@material='COTTON',@color='BLUE',@season='winter',@stid=555
insert into Clothes(cid,material,color,season,stid) values (8,'COTTON','BLACK','winter',222)
SELECT * FROM Logs
select * from Clothes

delete from Clothes where Clothes.cid=7
delete from Clothes where Clothes.cid=8



/*
create table EmployeesCopy(
eid int primary key,
ename varchar(50) not null,
age int not null,
mid int foreign key references Malls(mid))
go
*/
go

create or alter trigger Update_Employees ON Employees for update as
begin
	/*insert into EmployeesCopy(eid,ename,age,mid)
	select eid,ename,age,mid
	from inserted
	*/
	 insert into Logs(TriggerDate, TriggerType,NameAffectedTable, NoAMDRows)
	values (GETDATE(), 'UPDATE', 'Employees', @@ROWCOUNT)
	
end
go


update Employees
set ename='A'
where ename='Alina Popescu'
go

update Employees
set ename='Alina Popescu'
where ename='A'

select * from Employees

select * from Logs
go



create or alter trigger Add_Employees ON Employees for insert as
begin
	--insert into EmployeesCopy(eid,ename,age,mid)
	--select eid,ename,age,mid
	--from inserted
	 insert into Logs(TriggerDate, TriggerType,NameAffectedTable, NoAMDRows)
	values (GETDATE(), 'INSERT', 'Employees', @@ROWCOUNT)
	
end
go

insert into Employees(eid,ename,age,mid) values(77,'B',30,3)
select * from Logs
select * from EmployeesCopy
go



--4. write a query that contains at least 2 of the following operators in their execution plans:
--• clustered index scan;
--• clustered index seek;
--• nonclustered index scan;
--• nonclustered index seek;
--• key lookup.

if exists (select name from sys.indexes where name=N'NonClusteredIndex1')
	drop index NonClusteredIndex1 on dbo.Clothes;
go

create nonclustered index NonClusteredIndex1 on dbo.Clothes(season);
go

select * from Clothes where season='winter'
go
select * from Clothes order by season
go



if exists (select name from sys.indexes where name=N'NonClusteredIndex2')
	drop index NonClusteredIndex2 on dbo.Manager;
go

create nonclustered index NonClusteredIndex2 on dbo.Manager(mname)
go


--select the name of the manager of the store that sells a specific piece of clothing
select M.mname from Manager M, Stores S,Clothes C
where M.maid=S.stid and S.stid=C.stid and C.cid=3
go