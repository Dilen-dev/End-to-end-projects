select gender, count(gender) as TotalCount,
count(gender) / (select count(*) from customer_data) as Percentage
from customer_data
group by gender;

select contract, count(contract) as TotalCount,
count(contract) / (select count(*) from customer_data) as Percentage
from customer_data
group by Contract;

select customer_status, count(customer_status) as TotalCount, sum(Total_Revenue) as TotalRev,
sum(Total_Revenue) / (select sum(Total_Revenue) from customer_data) as RevPercentage
from customer_data
group by Customer_Status;

select state, count(state) as TotalCount,
count(state) / (select count(*) from customer_data) as Percentage
from customer_data
group by state
order by Percentage desc;

select distinct internet_type
from customer_data;