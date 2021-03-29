use Pavilions
go



--select the name of the youngest Architect
select A.architect_name
from Architects A
where A.year_of_birth=(select max(year_of_birth) from Architects)

--select the names of the architect who are still alive and designed a pavilion before 2010
select A.architect_name 
from Architects A,Architects_of_pavilions AP,Pavilions P
where P.year_of_construction<2010 and A.status_of_living='alive' and A.architect_name=AP.architect_name and P.name_of_pavilion=AP.name_of_pavilion

--select the precipitation and the average temperature for the pavilions with the location "on ground"
select P.name_of_pavilion,C.annual_precipitation, C.avg_temperature
from Climates C, Pavilions P
where P.location_of_pavilion='on ground' and P.climate=C.climate_zone

--select the name of the architect whose pavilion's state of at least one material is "artificial"
select A.architect_name, P.name_of_pavilion
from Architects A, Materials M, Pavilions P,Materials_of_pavilions MP, Architects_of_pavilions AP
where M.state_of_material='artificial' and MP.type_of_material=M.type_of_material and MP.name_of_pavilion=P.name_of_pavilion and P.name_of_pavilion=AP.name_of_pavilion and A.architect_name=AP.architect_name

--select the name of the pavilion which has at least one material with the durability "low"
select P.name_of_pavilion
from  Materials M, Pavilions P,Materials_of_pavilions MP
where M.durability_of_material='low' and MP.type_of_material=M.type_of_material and MP.name_of_pavilion=P.name_of_pavilion

--select all the pavilions that are 'temporary' and their purpose
select P.name_of_pavilion, P.purpose
from Pavilions P,Durations D
where D.state_of_duration='temporary' and D.pavilion_name=P.name_of_pavilion

--select the name of the pavilions, their materials with their durability and state for the pavilions designed by "Sami Rintala"
select P.name_of_pavilion,M.type_of_material,M.state_of_material,M.durability_of_material
from Pavilions P,Materials M,Materials_of_pavilions MP,Architects A,Architects_of_pavilions AP
where A.architect_name='Sami Rintala' and A.architect_name=AP.architect_name and AP.name_of_pavilion=P.name_of_pavilion and P.name_of_pavilion=MP.name_of_pavilion and MP.type_of_material=M.type_of_material

--count how many pavilion there are in China, the names and their architects
select AP.name_of_pavilion,AP.architect_name,(select count(pav.name_of_pavilion) from Pavilions pav where pav.country='China') as numberOfPavilionsInCountryGiven
from Pavilions P,Architects A, Architects_of_pavilions AP
where P.country='China' and P.name_of_pavilion=AP.name_of_pavilion and AP.architect_name=A.architect_name

--select the names of the pavilions that existed for less than 1 year      //loop cand incerc sa afisez si cele construite in 2020???
select P.name_of_pavilion
from Pavilions P,Durations D
where (P.name_of_pavilion=D.pavilion_name and D.state_of_duration='temporary' and D.period_of_time<12)

--select the name of the architects who designed at least 2 pavilions and the name of the pavilions from our database
select A.architect_name, P.name_of_pavilion, A.no_pavilions
from Architects A,Pavilions P,Architects_of_pavilions AP
where A.no_pavilions>=2 and A.architect_name=AP.architect_name and AP.name_of_pavilion=P.name_of_pavilion
order by A.no_pavilions desc

--select the names of all architects who designed a pavilion before the age of 40
select A.architect_name,(P.year_of_construction-A.year_of_birth) as theAge
from Architects A,Pavilions P,Architects_of_pavilions AP
where P.year_of_construction-A.year_of_birth<40 and A.architect_name=AP.architect_name and AP.name_of_pavilion=P.name_of_pavilion

--count how many male architects we have in our database
select (select count(A.architect_name) from Architects A where A.gender='male') as MaleArchitects, (select count(A.architect_name) from Architects A) as TotalArchitects, A.architect_name
from Architects A
where A.gender='male'

--count how many pavilions there are in Europe
select P.name_of_pavilion,P.country,(select count(P.name_of_pavilion) from Pavilions P, Countries C where C.continent='Europe' and C.name_of_country=P.country) as CountriesFromContinent
from Pavilions P,Countries C
where C.continent='Europe' and C.name_of_country=P.country
order by P.country

--select all architects, their nationality, their pavilions and the country in which they were designed
select A.architect_name,A.nationality,P.name_of_pavilion,P.country
from Architects A, Pavilions P, Architects_of_pavilions AP
where A.architect_name=AP.architect_name and AP.name_of_pavilion=P.name_of_pavilion
order by A.nationality

--select all Chinese architects
select A.architect_name
from Architects A
where A.nationality='Chinese'