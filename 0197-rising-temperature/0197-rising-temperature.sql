# Write your MySQL query statement below
SELECT A.id FROM Weather A, Weather B 
WHERE A.id <> B.id 
AND datediff(A.recordDate,B.recordDate) = 1
AND A.temperature > B.temperature; 
