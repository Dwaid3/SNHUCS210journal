#pragma once
#include <string>
#include <stdio.h>

class InvestmentAcc
{

public :
	InvestmentAcc();


	//These will be my public functions for this project
	double calculateBalanceWithMonthlyDeposit(InvestmentAcc* user1);
	double calculateBalanceWithoutMonthlyDeposit(InvestmentAcc* user1);
	void printDetails(InvestmentAcc* user1);
	void printMenuWithoutData();
	void printMenuWithData(InvestmentAcc* user1);
	void getData(InvestmentAcc *user1);

protected :
	double totalYearlyEarnings = 0.0;
	double annualInterest = 0.0;
	double earnings = 0.0;
	double currInvestment = 0.0;
	double initialInvestment = 0.0;
	double deposit = 0.0;
	int years = 0.0;
	double yearEndBalance = 0.0;
	double interestConvereted = 0.0;

};

