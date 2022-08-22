SELECT
    U.name AS name,
    T.balance AS balance
FROM
    Users U,
    (SELECT account, SUM(amount) AS balance
     FROM Transactions
     GROUP BY account
     HAVING balance > 10000) T
WHERE
    U.account = T.account;