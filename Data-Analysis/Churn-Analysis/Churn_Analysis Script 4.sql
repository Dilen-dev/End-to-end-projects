create view vw_ChurnData as
	select * from prod_churn where Customer_Status in ('Churned','stayed');
    
create view vw_JoinData as 
	select * from prod_churn where Customer_Status = 'Joined';