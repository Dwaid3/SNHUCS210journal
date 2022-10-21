#include "InvestmentAcc.h"
#include <string>
#include <iostream>
#include <stdio.h> 
#include <limits>
#include <iomanip>

using namespace std;

//This is the default contructor for the investment class
InvestmentAcc::InvestmentAcc() {
	double earnings = 0.0;
	double currInvestment = 0.0;
	double initialInvestment = 0.0;
	double deposit = 0.0;
	int years = 0;
	double yearEndBalance = 0;
	double annualInterest = 0.0;
	double interestConvereted = 0.0;
	double totalYearlyEarnings = 0.0;
}
//These will be the methods for our class.
double InvestmentAcc:: calculateBalanceWithoutMonthlyDeposit(InvestmentAcc* user1) 
{
	user1->currInvestment = initialInvestment;
	//This will be the headers of our columns which are year, year end balance and year end earnings
	cout << endl;
	cout << setw(5) << right << "Year" << setw(25) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest\n";
	cout << string(59, '=');
	cout << endl;

	//This loop will calculate everything while printing the results in a formatted form
	for (int i = 0; i < years; ++i) 
	{
		//These 3 statements will calculate our year end balance, year end earning, then loop through it how ever many years we want
		user1->yearEndBalance = initialInvestment + (initialInvestment * interestConvereted);
		user1->earnings = yearEndBalance - initialInvestment;
		user1->initialInvestment = yearEndBalance;
		
		cout << setw(5) << right << i+1 << setw(25) << right << fixed << setprecision(2) << user1->yearEndBalance << setw(29) << right << user1->earnings << endl;
	}
	cout << string(59, '=') << endl;

	return 0.0;
}

double InvestmentAcc:: calculateBalanceWithMonthlyDeposit(InvestmentAcc* user1) 
{
	currInvestment = initialInvestment;
	//This will be the headers of our columns which are year, year end balance and year end earnings
	cout << endl;
	cout << setw(5) << right << "Year" << setw(25) << right << "Year End Balance" << setw(30) << right << "Year End Earned Interest\n";
	cout << string(59, '=');
	cout << endl;

	//This loop will calculate everything while printing the results in a formatted form
	for (int i = 0; i < years; ++i)
	{
		//This will reset yearly earnings to keep it from stacking every year together
		totalYearlyEarnings = 0.0;
		
		
		//this nest loop will loop for the amount of months per year giving us our totals based on the formula provided by the functional requirements
		for (int j = 0; j < 12; ++j)
		{
			currInvestment += deposit;
			earnings = (currInvestment) * ((interestConvereted) / 12.0);
			currInvestment += earnings;
			totalYearlyEarnings += earnings;
		}
		user1->yearEndBalance = user1->currInvestment;
		
		

		cout << setw(5) << right << i + 1 << setw(25) << right << fixed << setprecision(2) << user1->yearEndBalance << setw(29) << right << user1->totalYearlyEarnings << endl;
	}
	cout << string(59, '=') << endl;

	return 0.0;
}

void InvestmentAcc:: printDetails(InvestmentAcc* user1) 
{
	//This will activate the correct function based on if the user is making monthly deposits
	if (user1->deposit > 0) 
	{
		user1->calculateBalanceWithMonthlyDeposit(user1);
	}
	else 
	{
		user1->calculateBalanceWithoutMonthlyDeposit(user1);
	}
}

void InvestmentAcc::printMenuWithoutData() 
{
	//String functions will print a char x number of times
	cout << string(34, '*') << endl;
	cout << string(11, '*') << " Data Input " << string(11, '*') << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
	system("pause");
	cout << endl;
}


void InvestmentAcc:: printMenuWithData(InvestmentAcc *user1) 
{
	cout << string(34, '*') << endl;
	cout << string(11, '*') << " Data Input " << string(11, '*') << endl;
	cout << fixed;
	cout.precision(2);
	cout << "Initial Investment Amount: $" << user1->initialInvestment << endl;
	cout << "Monthly Deposit: $" << user1->deposit << endl;
	cout.precision(0);
	cout << "Annual Interest: %" << user1->annualInterest << endl;
	cout << "Number of years: " << user1->years << endl;
	system("pause");
}

//This function uses a pointer to update all the users information and also validates all user input prior to assignment
void InvestmentAcc:: getData(InvestmentAcc* user1) 
{
	    cout << string(34, '=' );
		cout << endl;

		cout << "Enter your initial investment: ";
		cin >> user1->initialInvestment;
		while (true) 
		{
			//These if statements will ensure we get proper input from the user
			//If input is not proper will prompt the user for input again
		if (cin.fail() || user1->initialInvestment < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "That was invalid input. Try Again: ";
			cin >> user1->initialInvestment;
		}
		else { break; }
	}

		cout << "\nEnter your monthly deposit: ";
		cin >> user1->deposit;
		while (true) 
		{
			if (cin.fail() || user1->deposit < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "That was invalid input. Try Again: ";
				cin >> user1->deposit;
			}
			else { break; }
		}

		cout << "\nEnter your annual interest: ";
		cin >> user1->annualInterest;
		while (true) 
		{
			if (cin.fail() || user1->annualInterest < 0)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "That was invalid input. Try Again: ";
				cin >> user1->annualInterest;
			}
			else { break; }
		}

		//this will convert our interest for our functions.
		user1->interestConvereted = annualInterest / 100;


			cout << "\nEnter the number of years you're investment will grow: ";
			cin >> user1->years;
			while (true) 
			{
				if (cin.fail() || user1->years < 0)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "That was invalid input. Try Again: ";
					cin >> user1->years;
				}
				else { break; }
			}
			
			cout << endl;
			system("pause");
			cout << endl << endl;

}