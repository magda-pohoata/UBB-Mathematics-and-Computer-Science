create database StoresInMalls
go
use StoresInMalls
go

create table Malls(
mid int primary key,
mname varchar(50) not null,
city varchar(50) not null,
adress varchar(50),
no_employees int not null,
no_stores int not null,
size int not null)

create table Employees(
eid int primary key,
ename varchar(50) not null,
age int not null,
mid int foreign key references Malls(mid)
on delete cascade)

create table Directors(
did int foreign key references Malls(mid),
dname varchar(50) not null,
age int not null,
salary int not null,
constraint PrimaryKey_DirectorsMalls primary key(did)
)

create table Stores(
stid int primary key,
sname varchar(50) not null,
no_employees int not null,
category varchar(50),
size int not null
)

create table Clothes(
cid int primary key,
material varchar(50) not null,
color varchar(50),
season varchar(50),
stid int foreign key references Stores(stid)
)

create table Manager(
maid int foreign key references Stores(stid),
mname varchar(50) not null,
age int not null,
constraint PrimaryKey_ManagersStores primary key(maid)
)

create table StoresInMalls(
mid int foreign key references Malls(mid)
on delete cascade,
stid int foreign key references Stores(stid)
on delete cascade,
constraint PrimaryKey_MallsStores primary key(mid,stid)
)


