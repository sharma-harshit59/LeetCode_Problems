SELECT
    T.customer_id, COUNT(*) AS count_no_trans
FROM
    (SELECT customer_id
     FROM Visits
     WHERE visit_id NOT IN (SELECT DISTINCT(visit_id) FROM Transactions)) T
GROUP BY
    customer_id;