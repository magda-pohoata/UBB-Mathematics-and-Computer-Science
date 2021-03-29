use lab3HW
go

create or alter procedure edit_1
as
begin
alter table Employees
add nationality varchar(50)
print 'New column "nationality" added'
end
go

exec edit_1
go
select * from Employees
go

create or alter procedure unedit_1
as
begin
alter table Employees
drop column nationality
print 'The new column "Nationality" deleted'
end
go

exec unedit_1
go
select * from Employees
go

create or alter procedure edit_2
as
begin
alter table Employees
add constraint pk_Employees Primary Key(eid)
print 'The primary key added'
end
go

exec edit_2
go
select * from Employees
go

create or alter procedure unedit_2
as
begin
alter table Employees
drop constraint pk_Employees
print 'The primary key deleted'
end
go

exec unedit_2
go
select * from Employees
go

create or alter procedure edit_3
as
begin
alter table Employees
add constraint fk_EmployeesStores foreign key (stid) references Stores(stid)
print 'Foreign key added'
end
go

exec edit_3
go
select * from Employees
go

create or alter procedure unedit_3
as
begin
alter table Employees
drop constraint fk_EmployeesStores
print 'The foreign key deleted'
end
go

exec unedit_3
go
select * from Employees
go

create or alter procedure edit_4
as
begin
create table Managers(
maid int foreign key references Stores(stid),
mname varchar(50) not null,
age int not null,
constraint PrimaryKey_ManagersStores primary key(maid))
insert into Managers(maid,mname,age) values (111,'Maria Lazar',35),(222,'Bogdan Lazar',40),(333,'Mircea Lazar',39),(444,'Bianca Lazar',44)
print 'The new table "Managers" added'
end
go

exec edit_4
go
select * from Managers
go

create or alter procedure unedit_4
as
begin
drop table Managers
print 'The new table "Managers" deleted'
end
go

exec unedit_4
go
select * from Employees
go


create table currentVersion(current_version int)
insert into currentVersion(current_version) values(0)
go

create table versionTable(
id int primary key,
doing varchar(50) not null,
undoing varchar(50) not null)
go

insert into versionTable(id,doing,undoing) values (1,'exec edit_1','exec unedit_1'),
												  (2,'exec edit_2','exec unedit_2'),
												  (3,'exec edit_3','exec unedit_3'),
												  (4,'exec edit_4','exec unedit_4');
go



create or alter procedure main @version int 
as
begin
if((@version>=0) and (@version<(select count(*)from versionTable)))
begin
	while (select current_version from currentVersion) != @version
	begin
		if(select current_version from currentVersion)> @version
			begin

			declare @statement as nvarchar(200)=(select v.undoing from versionTable v, currentVersion c where c.current_version=v.id);
			execute sp_executesql @statement;
			update currentVersion set current_version=current_version-1;

			end
		else
			begin
		 
			update currentVersion set current_version=current_version+1;
			declare @anotherStatement as nvarchar(200)=(select v.doing from versionTable v, currentVersion c where c.current_version=v.id);
			execute sp_executesql @anotherStatement;
		
			end
	end
end
else
	begin
	print 'Version not available, please try again'
	end
end
go



exec main 10
go



select * from Managers
go
select * from Employees
go

update currentVersion set current_version=0
go
select current_version from currentVersion
go





create table Stores(
stid int primary key,
sname varchar(50) not null,
no_employees int not null,
category varchar(50),
size int not null
)

create table Employees(
eid int not null,
ename varchar(50) not null,
age int not null,
stid int)
go

insert into Employees(eid,ename,age,stid) values (11,'Ana Popescu',23,222)
insert into Employees(eid,ename,age,stid) values (22,'Vasile Popescu',31,111)
insert into Employees(eid,ename,age,stid) values (33,'Ion Popescu',25,333)
insert into Employees(eid,ename,age,stid) values (44,'Alisa Popescu', 25,222)
insert into Employees(eid,ename,age,stid) values (55,'Mihai Popescu',30,333)
insert into Employees(eid,ename,age,stid) values (66,'Alina Popescu',30,333)


insert into Stores(stid,sname,no_employees,category,size) values (111,'Auchan',35,'supermarket',600)
insert into Stores(stid,sname,no_employees,category,size) values (222,'H&M',22,NULL,250)
insert into Stores(stid,sname,no_employees,category,size) values (333,'Carrefour',34,'supermarket',450)
insert into Stores(stid,sname,no_employees,category,size) values (444,'Pull&bear',20,NULL,250)
insert into Stores(stid,sname,no_employees,category,size) values (555,'Bershka',26,NULL,230)
insert into Stores(stid,sname,no_employees,category,size) values (666,'Bloom',3,'flower shop',100)