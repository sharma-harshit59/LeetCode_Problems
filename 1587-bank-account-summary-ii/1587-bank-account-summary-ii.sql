SELECT
    U.name AS name, B.balance AS balance
FROM
    (SELECT T.account, SUM(T.amount) AS balance
     FROM Transactions T
     GROUP BY T.account) B, Users U
WHERE
    B.balance > 10000 AND (B.account = U.account);
