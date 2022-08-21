SELECT
    A.stock_name AS stock_name,
    (B.sell_price - A.buy_price) AS capital_gain_loss
FROM
    (SELECT stock_name, SUM(price) AS buy_price
     FROM StockS
     WHERE operation LIKE 'Buy'
     GROUP BY stock_name) A,
    (SELECT stock_name, SUM(price) AS sell_price
     FROM StockS
     WHERE operation LIKE 'Sell'
     GROUP BY stock_name) B
WHERE
    A.stock_name = B.stock_name;