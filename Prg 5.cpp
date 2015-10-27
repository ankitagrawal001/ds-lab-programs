/**
Lab Program 5
---------------------------------------------------------------------------
Design, develop, and execute a program in C++ based on the
following requirements:
An EMPLOYEE class is to contain the following data members and
member functions:
Data members: Employee_Number (an integer), Employee_Name (a
string of characters), Basic_Salary (an integer) , All_Allowances
(an integer), IT (an integer), Net_Salary (an integer).
Member functions: to read the data of an employee, to calculate
Net_Salary and to print the values of all the data members.
(All_Allowances = 123% of Basic; Income Tax (IT) = 30% of the
gross salary (= basic_Salary _ All_Allowance); Net_Salary =
Basic_Salary + All_Allowances – IT)
----------------------------------------------------------------------------
**/

#include <iostream>
#include <stdlib.h>

using namespace std;

class EMPLOYEE {
	int Employee_Number,Basic_Salary,All_Allowances,IT,Net_Salary;
	char Employee_Name[20];

	public:
		void accept();
		void calc();
		void display();
};

int main()
{
	EMPLOYEE emp[20];
	int n;
	cout<<"Enter Number Of Employees : ";
	cin>>n;
	for(int i=0 ; i < n; i++)
	{
		cout<<"\nEnter Details for Emp : "<<i+1<<"\n";
		emp[i].accept();
	}

	cout<<"\n\nNumber\tName\tBasic\tIT\tNet\tAll Allowances\n\n";
	for(int i=0 ; i < n ; i++)
	{
		emp[i].display();
	}

	return 0;
}

void EMPLOYEE::accept()
{
	cout<<"Number : ";
	cin>>Employee_Number;
	cout<<"Name : ";
	cin>>Employee_Name;
	cout<<"Basic : ";
	cin>>Basic_Salary;
	calc();
}

void EMPLOYEE::calc()
{
	All_Allowances=1.23*Basic_Salary;
	IT=0.3*(Basic_Salary+All_Allowances);
	Net_Salary=Basic_Salary+All_Allowances-IT;
}

void EMPLOYEE::display()
{
	cout<<Employee_Number<<"\t"<<Employee_Name<<"\t"<<Basic_Salary;
	cout<<"\t"<<IT<<"\t"<<Net_Salary<<"\t"<<All_Allowances<<"\n";
}

/**
author- Aman
*/
