* In hackerearth use the Marialdb syntax instead of SQL syntax.


* https://leetcode.com/problems/capital-gainloss/submissions/
 SELECT stock_name,SUM(price*IF(operation="Buy",-1,1)) as capital_gain_loss from Stocks group by stock_name
 
 SELECT stock_name, SUM(CASE WHEN operation='Buy' THEN -1*price 
 WHEN operation = 'Sell' THEN price END) AS capital_gain_loss
 FROM Stocks
 GROUP BY stock_name;




* Coalesce will return the first non null
* dual is a fake database with one row
SELECT COALESCE((SELECT Distinct Salary as SecondHighestSalary from Employee where 1 order by Salary Desc Limit 1,1),null) as SecondHighestSalary from dual


* select round(3.555,2) from dual  //it will round the value upto 2 decimal places


* https://leetcode.com/problems/running-total-for-different-genders/   
Cumalative sum query

SELECT gender,day,sum(score_points) OVER(partition by gender order by day) as total from Scores Group by gender,day Order by gender,day
