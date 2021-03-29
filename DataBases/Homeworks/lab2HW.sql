create database StoresMalls
go
use StoresMalls
go

create table Malls(
mid int primary key,
mname varchar(50) not null,
city varchar(50) not null,
no_employees int not null,
no_stores int not null,
size int not null)

insert into Malls(mid,mname,city,no_employees,no_stores,size) values (1,'Iulius Mall','Suceava',200,30,4000),(2,'Vivo','Cluj Napoca',300,50,5000),(3,'Palas','Iasi',300,40,5000)

select * from Malls

create table Employees(
eid int primary key,
ename varchar(50) not null,
age int not null,
mid int foreign key references Malls(mid)
on delete cascade)


insert into Employees(eid,ename,age,mid) values (11,'Ana Popescu',23,2)
insert into Employees(eid,ename,age,mid) values (22,'Vasile Popescu',31,1)
insert into Employees(eid,ename,age,mid) values (33,'Ion Popescu',25,3)
insert into Employees(eid,ename,age,mid) values (44,'Alisa Popescu', 25,2)
insert into Employees(eid,ename,age,mid) values (55,'Mihai Popescu',30,3)
insert into Employees(eid,ename,age,mid) values (66,'Alina Popescu',30,3)


create table Directors(
did int foreign key references Malls(mid),
dname varchar(50) not null,
age int not null,
salary int not null,
constraint PrimaryKey_DirectorsMalls primary key(did)
)

select * from Directors

insert into Directors(did,dname,age,salary) values (1,'Maria Popovici',35,5300),(2,'Marcel Popovici',40,5600),(3,'Rebeca Popovici',33, 4500)

delete from Directors

create table Stores(
stid int primary key,
sname varchar(50) not null,
no_employees int not null,
category varchar(50),
size int not null
)

insert into Stores(stid,sname,no_employees,category,size) values (111,'Auchan',35,'supermarket',600)
insert into Stores(stid,sname,no_employees,category,size) values (222,'H&M',22,NULL,250)
insert into Stores(stid,sname,no_employees,category,size) values (333,'Carrefour',34,'supermarket',450)
insert into Stores(stid,sname,no_employees,category,size) values (444,'Pull&bear',20,NULL,250)
insert into Stores(stid,sname,no_employees,category,size) values (555,'Bershka',26,NULL,230)
insert into Stores(stid,sname,no_employees,category,size) values (666,'Bloom',3,'flower shop',100)


create table Clothes(
cid int primary key,
material varchar(50) not null,
color varchar(50),
season varchar(50),
stid int foreign key references Stores(stid)
)

insert into Clothes(cid,material,color,season,stid) values (1,'cotton','blue','summer',222)
insert into Clothes(cid,material,color,season,stid) values (2,'leather','brown','autumn',444)
insert into Clothes(cid,material,color,season,stid) values (3,'cotton','yellow','summer',444)
insert into Clothes(cid,material,color,season,stid) values (4,'cotton','red','winter',222)
insert into Clothes(cid,material,color,season,stid) values (5,'leather','black','winter',555)
insert into Clothes(cid,material,color,season,stid) values (6,'leather','blue','winter',555)


create table Manager(
maid int foreign key references Stores(stid),
mname varchar(50) not null,
age int not null,
constraint PrimaryKey_ManagersStores primary key(maid)
)

insert into Manager(maid,mname,age) values (111,'Maria Lazar',35),(222,'Bogdan Lazar',40),(333,'Mircea Lazar',39),(444,'Bianca Lazar',44)

select * from Manager

create table StoresInMalls(
mid int foreign key references Malls(mid)
on delete cascade,
stid int foreign key references Stores(stid)
on delete cascade,
constraint PrimaryKey_MallsStores primary key(mid,stid)
)

insert into StoresInMalls(mid,stid) values (1,111)
insert into StoresInMalls(mid,stid) values (1,222)
insert into StoresInMalls(mid,stid) values (2,111)
insert into StoresInMalls(mid,stid) values (3,333)
insert into StoresInMalls(mid,stid) values (3,444)
insert into StoresInMalls(mid,stid) values (1,555)
insert into StoresInMalls(mid,stid) values (2,666)
insert into StoresInMalls(mid,stid) values (3,666)

select * from StoresInMalls
