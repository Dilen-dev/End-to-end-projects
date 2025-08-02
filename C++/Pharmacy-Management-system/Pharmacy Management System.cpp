#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;

class medicineType
{
	public:
		void take_order(); //-------to take an order
		void delete_order(); //------to delete the order
		void modify(); //------to modify the order
		void order_list(); //------to display order list
		void daily_summary(); //------to display daily summary
		void exit(); //------To exit the system
		medicineType();
};

medicineType::medicineType()
{
	
}

struct node
{
	int receipt_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
	double amount[10];
	string medicineName[10] = {"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women's Multivate","Marino Tablet","Maxi Cal Tablet","Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;
	
	node *prev;
	node *next;
	node *link;
}*q,*temp;

node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

int main()
{
	system("COLOR 0");
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t    Pharmacy Management System \n";
		cout<<"\t\t=====================================================\n\n";
		cout<<"\t\t------------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Delete  Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order list\t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment\t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale\t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t------------------------------------------------------\n";
		cout<<"Enter Choice: ";
		
		cin>>menu;
		
		switch(menu)
		{
			case 1:
				{
					medicine.take_order();
					break;
				}
			case 2:
				{
					medicine.delete_order();
					system("PAUSE");
					break;
				}
			case 3:
				{
					medicine.modify();
					system("PAUSE");
					break;
				}
			case 4:
				{
					medicine.order_list();
					system("PAUSE");
					break;
				}
			case 5:
				{
					medicine.daily_summary();
					system("PAUSE");
					break;
				}
			case 6:
				{
					medicine.exit();
					goto a;
					break;
				}
			default:
				{
					cout<<"You have entered an incalid input\nre-enter the input\n"<<endl;
					break;
				}
			}
		}while(menu!=6);
		a:
			cout<<"thank you"<<endl;
			system("PAUSE");
			return 0;
	}

void printMedicineList() {
    cout <<"***************************************************************************************\n";
    cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"      \t\tDRUGS NAME"<<"              DRUGS PRICE(M)"<<endl;
    cout <<"***************************************************************************************\n";
    string meds[] = {"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women's Multivate",
                     "Marino Tablet","Maxi Cal Tablet","Amino Zinc Tablet","Burnex",
                     "Fabuloss 5","Royal Propollen"};
    double prices[] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};

    for (int i = 0; i < 10; i++) {
        cout << setfill(' ') << setw(4) << i+1 << "\tOTC\t\t" 
             << setw(24) << left << meds[i] 
             << "M " << fixed << setprecision(2) << prices[i] << endl;
    }
}


void medicineType::take_order()
{
	system("cls");
	int i;
	int choice,quantity,price,None;
	
	cout<<"\nAdd Order Details\n";
	cout<<"___________________________________________\n\n";
	
	node *temp;
	temp = new node;
	printMedicineList();
	cout<<"Type Order no: ";
	cin>>temp->receipt_number;
	cout<<"Enter Customer Name: ";
	cin.ignore(); // flush newline
	getline(cin, temp->customerName);
	cout<<"Enter Date: ";
	cin>>temp->date;
	cout<<"How many Medicine would you like to order:"<<endl;
	cout<<"(Maximum is 10 orders for each transaction) \n";
	cout<<"  " ;
	cin>>temp->x;
	if(temp->x > 10)
	{
		cout<<"The Medicine you order exceeds the maximum amount of order!!";
		system("PAUSE");
	}
	else{
		for (i=0;i<temp->x;i++)
		{
			cout<<"Please enter your selection : "<<endl;
			cin>>temp->menu2[i];
			if (temp->menu2[i] < 1 || temp->menu2[i] > 10)
			{
   				 cout << "Invalid medicine selection!\n";
  				  i--; continue;
			}

			cout<<"Medicine Name: "<<temp->medicineName[temp->menu2[i]-1]<<endl;
			cout<<"How many Medicine do want: ";
			cin>>temp->quantity[i];
			temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
			cout<<"The amount You need to pay is: M"<<temp->amount[i]<<endl;
			system("PAUSE");
			
		}
		cout<<"============================================================================="<<endl;
		cout<<"Order Taken Succesfully"<<endl;
		cout<<"============================================================================="<<endl;
		cout<<"Go to Receipt Menu to Pay the Bill"<<endl;
		cout<<"============================================================================="<<endl;
		system("PAUSE");
		
		temp->next=NULL;
		if(start_ptr!=NULL)
		{
			temp->next=start_ptr;
		}
		start_ptr=temp;
		system("cls");
	}
}

void medicineType::order_list()
{
	int i,num,num2;
	bool found;
	system("cls");
	node *temp;
	
	temp=start_ptr;
	found=false;
	
	cout<<" Enter the Receipt Number to Print the receipt\n";
	cin>>num2;
	cout<<"\n";
	cout<<"============================================================================="<<endl;
	cout<<"\t\tHere is the Order list\n";
	cout<<"============================================================================="<<endl;
	
	if(temp == NULL)
	{
		cout<<"\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if(temp->receipt_number==num2)
		{
			found = true;
		}
		else
		{
			temp= temp->next;
		}
		if(found)
		{
			cout<<"Reciept Number : "<<temp->receipt_number;
			cout<<"\n";
			cout<<"Customer Name: "<<temp->customerName<<endl;
			
			cout<<"Order Date : "<<temp->date<<endl;
			
			cout<<"_________________________________________________________________________"<<endl;
			
			cout<<"============================================================================="<<endl;
			cout<<"|   Medicine Type |   Medicine Name     |    Quantity    |    Total Price  |"<<endl;
			cout<<"============================================================================="<<endl;
			for(i=0;i<temp->x;i++)
			{
				cout<<temp->type<<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t ";
				cout<<temp->quantity[i]<<"\t\t";
				cout<<"M"<<temp->amount[i]<<endl;
				cout<<"_________________________________________________________________________"<<endl;
			}
			
			temp->total = 0;
			for (int j = 0; j < temp->x; j++) {
			    temp->total += temp->amount[j];
			}
			cout<<"Total Bill is : "<<temp->total;
			cout<<"\n";
			cout<<"Type the exact amount you need to pay: ";
			cin>>num;
			
			cout<<"\n";
			cout<<"\n";
			cout<<"Payment Done\nThank You\n";
			cout<<"_________________________________________________________________________\n";
		}
			
	}
}

void medicineType::delete_order()
{
	system("cls");
	int i,num,count;
	cout<<"Enter the reciept number you want to delete \n";
	cin>>num;
	node *q;
	node *temp;
	bool found;
	
	if(start_ptr == NULL)
		cerr<<"can not delete from an empty list.\n";
	else
	{
		found = false;
		temp = start_ptr;
		q = start_ptr->next;
		if (start_ptr->receipt_number == num)
		{
	    	node *del = start_ptr;
	    	start_ptr = start_ptr->next;
	    	delete del;
	    	cout << "Receipt deleted successfully\n";
	    	return;
		}

		
		while((!found) && (q != NULL))
		{
			if(q->receipt_number != num)
			{
				temp = q;
				q  = q->next;
			}
			else
			{
				found = true;
			}
		}
		
		if(found)
		{
			temp->next = q->next;
			count--;
			
			if(last == q)
			last = temp;
			delete q;
			cout<<"The reciept is deleted successfully"<<endl;
		}
		else
		{
			cout<<"Item to be deleted is not in the list."<<endl;
		}
	}
}

void medicineType::modify()
{
	system("cls");
	int i,ch,sid;
	bool found;
	found = false;
	temp = start_ptr;
	cout<<"Enter Reciept number to modify: ";
	cin>>sid;
	if(temp==NULL && sid==0)
	{
		cout<<"NO RECORD TO MODIFY...!"<<endl;
	}
	else
	{
		while(temp !=NULL && !found)
		{
			if(temp->receipt_number == sid)
			{
				found = true;
			}
			else
			{
				temp = temp->next;
			}
		}
		if(found)
		{
			cout<<"Change Order Number: ";
			cin>>temp->receipt_number;
			cout<<"Change Customer Name: ";
			cin>>temp->customerName;
			cout<<"Change Date: ";
			cin>>temp->date;
			cout<<"How many New medicine would you like to change: "<<endl;
			cout<<"(Maximum is 10 order for each transaction) \n";
			cout<<"  ";
			cin>>temp->x;
			if(temp->x > 10)
			{
				cout<<"The medicine you ordered exceeds the maximum amount of order !";
				system("PAUSE");
			}
			else{
				for(i=0; i<temp->x; i++)
				{
					cout<<"Please enter your selection to Change: "<<endl;
					cin>> temp->menu2[i];
					cout<<"Change Medicine Name: "<<temp->medicineName[temp->menu2[i]-1]<<endl;
					cout<<"How many New medicine do you want: ";
					cin>> temp->quantity[i];
					temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
					cout<< "The amount you need to pay after modifying is: M"<<temp->amount[i]<<endl;
					system("PAUSE");
				}
				temp =temp->next;
				system("cls");
			}
		cout<<"RECORD MODIFIED...!"<<endl;
		}
		else
		{
			if(temp !=NULL && temp->receipt_number != sid)
			{
				cout<<"Invalid Reciep Number...!"<<endl;
			}
		}
	}	
}


void medicineType::daily_summary()
{
	int i,num;
	system("cls");
	node *temp;
	
	temp = start_ptr;
	
	if(temp == NULL)
	{
		cout<<"\t\tThere is no order to show\n\t\tSo The list is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"============================================================================="<<endl;
		cout<<" \t\tHere is the Daily Summary of All orders \n";
		cout<<"============================================================================="<<endl;
		
		while(temp!=NULL)
		{
			cout<<"Reciept Number : "<<temp->receipt_number;
			cout<<"\n";
			cout<<"Customer Name: "<<temp->customerName<<endl;
			
			cout<<"order Date: "<<temp->date<<endl;
			
			cout<<"_________________________________________________________________________"<<endl;
			
			cout<<"============================================================================="<<endl;
			cout<<"|   Medicine Type |   Medicine Name     |    Quantity    |    Total Price  |"<<endl;
			cout<<"============================================================================="<<endl;
			for(i=0;i<temp->x;i++)
			{
				cout<<temp->type<<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t ";
				cout<<temp->quantity[i]<<"\t\t";
				cout<<"M"<<temp->amount[i]<<endl;
				cout<<"_________________________________________________________________________"<<endl;
			}
			temp->total = 0;
			for (int j = 0; j < temp->x; j++) {
			    temp->total += temp->amount[j];
			}

			cout<<"Total Bill is : "<<temp->total;
			cout<<"\n";
			cout<<"\n";
			cout<<"\n_________________________________________________________________________\n";
			
			temp = temp->next;
		}
	}
}


void medicineType::exit()
{
	cout<<"\nYou choose to exit.\n"<<endl;
}