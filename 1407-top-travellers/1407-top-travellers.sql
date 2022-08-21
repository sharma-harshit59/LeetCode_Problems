SELECT
    A.name AS name,
    B.dist AS travelled_distance
FROM
    Users A,
    (SELECT user_id, SUM(distance) AS dist
     FROM Rides
     GROUP BY user_id) B
WHERE
    A.id = B.user_id

UNION

SELECT
    name, 0 AS travelled_distance
FROM
    Users
WHERE
    id NOT IN (SELECT DISTINCT(user_id)
               FROM Rides)
               
ORDER BY 2 DESC, 1 ASC;
