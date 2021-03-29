use StoresMalls
go

select * from Malls

--update data 1/2
-- "<"
update Malls
set no_employees=350
where no_stores<50


select * from Employees

--update data 2/2
-- LIKE, AND, IN
update Employees
set ename='A'
where ename like 'A%' and mid in(1,2)

--delete data1/2
--BETWEEN, ">="
-- OR in the where clause
delete from Employees
where (age between 20 and 25) or (age>=31)


--INNER JOIN
--INTERSECT
--EXISTS that introduce a subquery in the where clause
--AND in the where clause
--ORDER BY 1/2
select ename
from Employees E inner join Malls M on M.mid=E.mid
intersect
select ename
from Employees E where E.age<30 and exists (select * from Employees E where E.age is not NULL)
order by ename


--LEFT JOIN
--UNION
--IN that introduce a subquery in the where clause
--ORDER BY DESC
select ename
from Employees E left join Malls M on M.mid=E.mid
union
select ename
from Employees E where E.age in (select E.age from Employees E where E.age>35)
order by ename desc


select * from Directors


--AVG
select Avg(D.salary) as AverageSalary
from Directors D


--AVG
--COUNT
--GROUP BY + HAVING + subquery in HAVING
select D.dname,D.salary,(select AVG(D.salary) from Directors D) as AverageSalary,(select COUNT(D.dname) from Directors D where D.salary<(select AVG(D.salary) from Directors D)) as EmployeesCounted
from Directors D 
group by D.dname,D.salary
having D.salary<(select AVG(D.salary) from Directors D)


--DELETE
--NULL
delete from Stores
where category is null

select * from Stores

--MIN
--GROUP BY + HAVING + subquery in HAVING
select s.sname,s.no_employees,(select MIN(s.no_employees) from Stores s) as MinNoEmployees
from Stores s
group by s.sname,s.no_employees
having s.no_employees>(select Min(s.no_employees) from Stores s)


select * from Clothes

--DISTINCT
select distinct C.stid,C.material
from Clothes C
where C.material='cotton'


--TOP
--ORDER BY DESC
select top 2 C.cid, C.stid, C.season
from Clothes C
where C.season='winter'
order by C.cid desc


--1 query with a subquery in the FROM clause
--1 query with EXCEPT
--1 query with RIGHT JOIN
select A.mname, A.age
from (select M.mname,M.age 
      from Manager M right join Stores S on M.maid=S.stid 
	  except 
	  select M.mname,M.age from Manager M where M.age<40) A


--FULL JOIN joining 3 tables
--GROUP BY + HAVING
select C.cid,C.material,S.sname,M.mname
from Clothes C full join Stores S on C.stid=S.stid
               full join Manager M on C.stid=M.maid
group by C.cid,C.material,S.sname,M.mname
having C.material!='leather'
