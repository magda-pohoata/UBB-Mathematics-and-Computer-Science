create database Pavilions
go
use Pavilions
go

create table Architects(
architect_name varchar(50) primary key,
nationality varchar(50) not null,
year_of_birth int not null,
gender varchar(50) not null,
status_of_living varchar(50) not null,
no_pavilions int not null)

select * from Architects

insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Ana Ferreira','Portuguese',1987,'female','alive',1)   --Inbetween pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Pedro Ribeiro','Portuguese',1987,'male','alive',1)   --Inbetween pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Ludwig Mies van der Rohe','German',1886,'male','dead',1)   --Barcelona pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Lilly Reich','German',1885,'female','dead',1)  --Barcelona pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Kjetil Traedal Thorsen','Norwegian',1958,'male','alive',2) --Tverrfjellhytta pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Sverre Fehn','Norwegian',1924,'male','dead',1)  --Nordic pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Zaha Hadid','British',1950,'female','dead',2)  --Burnham pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Runwu Fang','Chinese',1982,'male','alive',1)   --Screen pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('James Shen','Chinese',1985,'male','alive',2)   --Container stack pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Marlon Blackwell','American',1956,'male','alive',1)  --The Ruth Lilly Visitors pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Hsinming Fung','Chinese',1964,'female','alive',3)  --The wild beast pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Gong Dong','Chinese',1972,'male','alive',2)  --Riverside Park pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Joana Gomes','Portuguese',1986,'female','alive',1)  --Luum temple
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Evgeny Reshetov','Russian',1988,'male','alive',1)  --Living room pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Valerie Schweitzer','American',1980,'female','alive',1)  --Outside-in pavilion
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Sami Rintala','Finnish',1969,'male','alive',4)  --Corte del forte dance pavilion, Into the Landscape pavilion, Seljord Watch Tower
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Romeo Cuc','Romanian',1987,'male','alive',1)  --The Romanian pavilion Mnemonics
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Christo Vladimirov Javacheff','Bulgarian',1935,'male','dead',5)  --The Floating Piers
insert into Architects(architect_name,nationality,year_of_birth,gender,status_of_living,no_pavilions) values ('Jacques Herzog','Swiss',1950,'male','alive',6)  --2012 Serpentine pavilion



create table Materials(
type_of_material varchar(50) primary key,
state_of_material varchar(50) not null,
durability_of_material varchar(50) not null)

select * from Materials

insert into Materials(type_of_material,state_of_material,durability_of_material) values ('wood','natural','medium')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('glass','processed','medium')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('bamboo','natural','low')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('steel','processed','high')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('ceramics','pocessed','low')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('plastic','artificial','medium')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('stone','natural','high')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('cloth','processed','low')
insert into Materials(type_of_material,state_of_material,durability_of_material) values ('concrete','processed','high')



create table Countries(
name_of_country varchar(50) primary key,
population_of_country int not null,
dimension_of_country int not null,
continent varchar(50) not null)

select * from Countries

insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('China',1400,10000,'Asia')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Portugal',11,92,'Europe')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Spain',47,505,'Europe')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Norway',5,385,'Europe')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Italy',60,301,'Europe')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('United States of America',328,9800,'North America')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Mexico',126,1900,'North America')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Russia',145,17000,'Europe')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('England',56,130,'Europe')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('France',67,643,'Europe')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Brazil',211,8500,'South America')
insert into Countries(name_of_country,population_of_country,dimension_of_country,continent) values ('Denmark',6,43,'Europe')


create table President(
name_of_country varchar(50) foreign key references Countries(name_of_country),
name_of_president varchar(50) not null,
constraint PrimaryKey_CountryPresident primary key (name_of_country))

select * from President

insert into President(name_of_country,name_of_president) values('China','Xi Jinping')
insert into President(name_of_country,name_of_president) values('Portugal','Marcelo Rebelo de Sousa')
insert into President(name_of_country,name_of_president) values('Spain','Pedro Sánchez')
insert into President(name_of_country,name_of_president) values('Norway','Erna Solberg')
insert into President(name_of_country,name_of_president) values('Italy','Sergio Mattarella')
insert into President(name_of_country,name_of_president) values('United States of America','Joe Biden')
insert into President(name_of_country,name_of_president) values('Mexico','Andres Manuel Lopez Obrador')
insert into President(name_of_country,name_of_president) values('Russia','Vladimir Putin')
insert into President(name_of_country,name_of_president) values('England','Queen Elizabeth II')
insert into President(name_of_country,name_of_president) values('France','Emmanuel Macron')
insert into President(name_of_country,name_of_president) values('Brazil','Jair Bolsonaro')
insert into President(name_of_country,name_of_president) values('Denmark','Mette Frederiksen')


create table Years(
year_id int primary key,
no_of_pavilions int)

select * from Years

insert into Years(year_id,no_of_pavilions) values (2020,20)
insert into Years(year_id,no_of_pavilions) values (2019,30)
insert into Years(year_id,no_of_pavilions) values (2018,37)
insert into Years(year_id,no_of_pavilions) values (2016,33)
insert into Years(year_id,no_of_pavilions) values (2015,31)
insert into Years(year_id,no_of_pavilions) values (2013,33)
insert into Years(year_id,no_of_pavilions) values (2012,31)
insert into Years(year_id,no_of_pavilions) values (2011,35)
insert into Years(year_id,no_of_pavilions) values (2010,36)
insert into Years(year_id,no_of_pavilions) values (2009,40)
insert into Years(year_id,no_of_pavilions) values (2008,38)
insert into Years(year_id,no_of_pavilions) values (1962,20)
insert into Years(year_id,no_of_pavilions) values (1929,15)



create table Climates(
climate_zone varchar(50) primary key,
annual_precipitation int not null,
avg_temperature int not null)

select * from Climates

delete from Climates where climate_zone='a'

insert into Climates(climate_zone,annual_precipitation,avg_temperature) values('meditarranean climate',500,19)
insert into Climates(climate_zone,annual_precipitation,avg_temperature) values('steppe climate',200,13)
insert into Climates(climate_zone,annual_precipitation,avg_temperature) values('subarctic climate',400,7)
insert into Climates(climate_zone,annual_precipitation,avg_temperature) values('humid continental climate',900,18)
insert into Climates(climate_zone,annual_precipitation,avg_temperature) values('tropical savanna climate',1200,25)
insert into Climates(climate_zone,annual_precipitation,avg_temperature) values('temperate oceanic climate',900,17)



create table Pavilions(
name_of_pavilion varchar(50) primary key,
purpose varchar(50) not null,
year_of_construction int foreign key references Years(year_id),
dimension int not null,
location_of_pavilion varchar(50) not null,
landform varchar(50) not null,
country varchar(50) foreign key references Countries(name_of_country),
climate varchar(50) foreign key references Climates(climate_zone))

select * from Pavilions

insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Inbetween pavilion','historic preservation',2020,400,'on ground','plain','Portugal','meditarranean climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Barcelona pavilion','historic movement',1929,900,'on ground','city','Spain','steppe climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Tverrfjellhytta Snohetta pavilion','recreational space',2011,900,'on ground','mountain','Norway','subarctic climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Nordic pavilion','representation of country',1962,600,'on ground','city','Italy','meditarranean climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Burnham pavilions','historic celebration',2009,120,'on ground','city','United States of America','humid continental climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Screen pavilion','recreational space',2020,66,'on ground','lake','China','humid continental climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Container Stack pavilion','recreational space',2015,307,'on ground','city','China','steppe climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('The Ruth Lilly Visitors pavilion','recreational space',2010,1290,'on ground','forest','United States of America','humid continental climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('The wild beast pavilion','concerts',2009,3500,'on ground','city','United States of America','meditarranean climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Riverside Park pavilion','recreational space',2013,175,'on ground','city','China','humid continental climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Luum Temple','recreational space',2019,250,'on ground','forest','Mexico','tropical savanna climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Living Room pavilion','recreational space',2018,185,'on ground','lake','Russia','subarctic climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Outside-in pavilion','recreational space',2020,280,'on ground','city','United States of America','humid continental climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Corte del Forte','recreational space and place to dance',2018,190,'on ground','lake','Italy','meditarranean climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Seljord Watch Tower','recreational space',2008,150,'on ground','lake','Norway','subarctic climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('The Romanian pavilion Mnemonics','representation of country',2018,1000,'on ground','city','Italy','meditarranean climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('The Floating Piers','recreational space',2016,100000,'on water','lake','Italy','meditarranean climate')
insert into Pavilions(name_of_pavilion,purpose,year_of_construction,dimension,location_of_pavilion,landform,country,climate) values ('Serpentine pavilion 2012','recreational space',2012,700,'under ground','city','England','temperate oceanic climate')



create table Durations(
pavilion_name varchar(50) foreign key references Pavilions(name_of_pavilion),
state_of_duration varchar(50) not null,
period_of_time int
constraint PrimaryKey_PavilionsDurations primary key (pavilion_name))

select * from Durations

insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Inbetween pavilion','definitivive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Barcelona pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Tverrfjellhytta Snohetta pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Nordic pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Burnham pavilions','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Screen pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Container Stack pavilion','temporary',3)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('The Ruth Lilly Visitors pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('The Wild Beast pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Riverside Park pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Luum Temple','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Living Room pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Outside-in pavilion','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Corte del Forte','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Seljord Watch Tower','definitive',null)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('The Romanian pavilion Mnemonics','temporary',6)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('The Floating Piers','temporary',3)
insert into Durations(pavilion_name,state_of_duration,period_of_time) values ('Serpentine pavilion 2012','temporary',12)



create table Materials_of_pavilions(
name_of_pavilion varchar(50) foreign key references Pavilions(name_of_pavilion),
type_of_material varchar(50) foreign key references Materials(type_of_material),
constraint PrimaryKey_MaterialsPavilions primary key(name_of_pavilion,type_of_material))

select * from Materials_of_pavilions

insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Inbetween pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Inbetween pavilion','stone')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Barcelona pavilion','stone')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Barcelona pavilion','glass')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Tverrfjellhytta Snohetta pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Tverrfjellhytta Snohetta pavilion','glass')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Nordic pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Burnham pavilions','steel')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Screen pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Container Stack pavilion','plastic')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('The Ruth Lilly Visitors pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('The Wild Beast pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('The Wild Beast pavilion','glass')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Riverside Park pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Luum Temple','bamboo')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Living Room pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Outside-in pavilion','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Corte del Forte','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Seljord Watch Tower','wood')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('The Romanian pavilion Mnemonics','concrete')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('The Floating Piers','plastic')
insert into Materials_of_pavilions(name_of_pavilion,type_of_material) values ('Serpentine pavilion 2012','ceramics')



create table Architects_of_pavilions(
name_of_pavilion varchar(50) foreign key references Pavilions(name_of_pavilion),
architect_name varchar(50) foreign key references Architects(architect_name)
constraint PrimaryKey_ArchitectsPavilions primary key(name_of_pavilion,architect_name))

select * from Architects_of_pavilions

insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Inbetween pavilion','Ana Ferreira')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Inbetween pavilion','Pedro Ribeiro')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Barcelona pavilion','Ludwig Mies van der Rohe')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Barcelona pavilion','Lilly Reich')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Tverrfjellhytta Snohetta pavilion','Kjetil Traedal Thorsen')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Nordic pavilion','Sverre Fehn')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Burnham pavilions','Zaha Hadid')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Screen pavilion','Runwu Fang')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Container Stack pavilion','James Shen')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('The Ruth Lilly Visitors pavilion','Marlon Blackwell')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('The Wild Beast pavilion','Hsinming Fung')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Riverside Park pavilion','Gong Dong')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Luum Temple','Joana Gomes')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Living Room pavilion','Evgeny Reshetov')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Outside-in pavilion','Valerie Schweitzer')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Corte del Forte','Sami Rintala')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Seljord Watch Tower','Sami Rintala')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('The Romanian pavilion Mnemonics','Romeo Cuc')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('The Floating Piers','Christo Vladimirov Javacheff')
insert into Architects_of_pavilions(name_of_pavilion,architect_name) values ('Serpentine pavilion 2012','Jacques Herzog')