SELECT
    A.email AS Email
FROM
    (SELECT email, COUNT(*) AS no_of_times
     FROM Person
     GROUP BY email) A
WHERE
    A.no_of_times > 1;