SELECT
    P.firstName, P.lastName, A.city, A.state
FROM
    Person P, Address A
WHERE
    P.personId = A.personId

UNION

SELECT
    firstName, lastName, NULL AS city, NULL AS state
FROM
    Person
WHERE
    personId NOT IN (SELECT DISTINCT(personId) FROM Address);