#include <string>
#include <iostream>
#include "InvestmentAcc.h"
#include <iomanip>


using namespace std;

int main() 
{
	double annualInterest;
	double initialInvestment;
	double deposit;
	int years;
	bool moreInput = true;
	int input;

	

	while (moreInput)
	{
		InvestmentAcc* user1 = new InvestmentAcc;
		user1->printMenuWithoutData();
		user1->getData(user1);
		user1->printMenuWithData(user1);
		user1->printDetails(user1);

		//Branch statements will allow user to keep going if they want to
		cout << "Do you wish to try another entry?\nType 1 for yes or 2 for no.\n";
		cin >> input;
		if (input == 1) 
		{
			delete user1;
			continue;
		}
		else if (input == 2) 
		{
			moreInput = false;
		}
		else 
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input try again: ";
			cin >> input;
		}
	}
}