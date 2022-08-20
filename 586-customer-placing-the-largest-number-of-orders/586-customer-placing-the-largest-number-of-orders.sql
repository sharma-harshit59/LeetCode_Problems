SELECT
    T.customer_number
FROM
    (SELECT customer_number, COUNT(*) AS cnt
     FROM Orders
     GROUP BY customer_number) T
ORDER BY T.cnt DESC
LIMIT 1;