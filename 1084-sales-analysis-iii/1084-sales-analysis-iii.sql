SELECT
    DISTINCT(P.product_id) AS product_id,
    P.product_name AS product_name
FROM
    Product P, Sales S
WHERE
    (P.product_id = S.product_id) AND
    (S.sale_date BETWEEN '2019-01-01' AND '2019-03-31') AND
    P.product_id NOT IN (SELECT DISTINCT(product_id)
                         FROM Sales
                         WHERE sale_date > '2019-03-31' OR sale_date < '2019-01-01');