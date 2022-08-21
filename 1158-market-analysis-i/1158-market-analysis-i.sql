SELECT
    A.user_id AS buyer_id,
    A.join_date AS join_date,
    B.orders AS orders_in_2019
FROM
    Users A,
    (SELECT buyer_id, COUNT(*) AS orders
     FROM Orders
     WHERE order_date LIKE '2019%'
     GROUP BY buyer_id) B
WHERE
    A.user_id = B.buyer_id
    
UNION

SELECT
    user_id AS buyer_id, join_date, 0 AS orders_in_2019
FROM
    Users
WHERE
    user_id NOT IN (SELECT DISTINCT(buyer_id)
                    FROM Orders
                    WHERE order_date LIKE '2019%');
