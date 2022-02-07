#ifndef INVESTMENTPLAN_H
#define INVESTMENTPLAN_H
#include <vector>
#include <iostream>
#include <iomanip>


class InvestmentPlan {
	//Setting public attributes for the Investment Plan class
public:
	void SetData(int, double, double, double);
	void SetDeposit(double);
	void CalculateInterest();
	void ShowHeader1();
	void ShowHeader2();
	void ShowResults();

	//Setting the private attirbutes for Investment plan class
private:
	void ShowHeader();

	//Sets up and initializes variables used for the Investment Plan
	int numYears = 0;
	double annualInterest = 0;
	double initialAmount = 0;
	double depositAmount = 0;
	std::vector<double> interestList;
	std::vector<double> sumList;
};

#endif