SELECT
    A.day AS day, A.emp_id AS emp_id,
    SUM(A.total_time) AS total_time
FROM
    (SELECT event_day AS day, emp_id, (out_time - in_time) AS total_time
     FROM Employees) A
GROUP BY
    1, 2;