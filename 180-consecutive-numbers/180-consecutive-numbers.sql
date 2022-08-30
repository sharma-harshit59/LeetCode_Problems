SELECT DISTINCT(num) AS ConsecutiveNums
FROM Logs L1
WHERE (L1.id + 1) IN (SELECT id FROM Logs L2 WHERE L2.num = L1.num) AND
      (L1.id + 2) IN (SELECT id FROM Logs L3 WHERE L3.num = L1.num);