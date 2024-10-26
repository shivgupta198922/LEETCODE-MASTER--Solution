# Write your MySQL query statement below
select name from Customer where ifnull(referee_id,1)<>2;