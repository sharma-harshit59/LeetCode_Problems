SELECT
    D.name AS Department,
    E.name AS Employee,
    E.salary AS Salary
FROM
    Employee E, Department D,
    (SELECT departmentId AS dept, MAX(salary) AS max_salary
     FROM Employee
     GROUP BY departmentId) T
WHERE
    E.departmentId = D.id AND D.id = T.dept AND
    E.salary = T.max_salary
    