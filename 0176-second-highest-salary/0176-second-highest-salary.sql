select max(salary) as SecondHighestSalary
from employee
where salary<(select max(salary) as sal
from employee)
order by salary desc
limit 1