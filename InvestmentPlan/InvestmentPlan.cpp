#include "InvestmentPlan.h"

void InvestmentPlan::SetData(int numYears, double annualInterest, double initialAmount,
	double depositAmount) {
	this->numYears = numYears;
	this->annualInterest = annualInterest;
	this->initialAmount = initialAmount;
	this->depositAmount = depositAmount;
}

void InvestmentPlan::SetDeposit(double deposit) {
	this->depositAmount = deposit;
}

void InvestmentPlan::CalculateInterest() {

	//Setting up the variables we will use to calculate the interest
	int currentMonth;
	int totalMonths;
	double interestAmount;
	double total;
	double monthlyInterest;
	double monthlyDeposit;

	//Initializing the variables
	currentMonth = 1; //Using '1' here for a more accurate output
	totalMonths = numYears * 12;
	total = initialAmount;
	interestAmount = 0;
	monthlyInterest = (annualInterest / 100) / 12;
	monthlyDeposit = depositAmount;
	interestList.clear(); //Purges out our vector
	sumList.clear(); //Purges the vector
	
	while (currentMonth <= totalMonths) { //The loop will iterate through for each month
		total += monthlyDeposit; //Equation to add total amount to the deposit amount
			interestAmount = total * monthlyInterest; //Equation to calcuate gained interest
		interestList.push_back(interestAmount); // Saves interest to end of vector to use later
			total += interestAmount; //Adds on interest to the current total
			sumList.push_back(total); //Saves the total calculated to use later
			currentMonth++; //Has loop continue through to the next month
	}
}

void InvestmentPlan::ShowHeader() { //This is our main header that will show the Year, Year End Balance, and Year End Earned interest columns
	std::cout << std::setw(10) << std::left << "  Year" << std::flush;
	std::cout << std::setw(15) << std::left << "   Year End Balance" << std::flush;
	std::cout << std::setw(10) << std::right << "         Year End Earned Interest" << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
}

void InvestmentPlan::ShowHeader1() { //This is another header which will display above the Year, Balance, and Earned Interest values
	std::cout << "====================================================================" << std::endl;
	std::cout << "      Balance and Interest With Additional Monthly Deposits" << std::endl;
	std::cout << "====================================================================" << std::endl;
	this->ShowHeader();
}

void InvestmentPlan::ShowHeader2() { //This is another header which will display above the Year, Balance, and Earned Interest values
	std::cout << std::endl;
	std::cout << "====================================================================" << std::endl;
	std::cout << "      Balance and Interest Without Additional Monthly Deposits" << std::endl;
	std::cout << "====================================================================" << std::endl;
	this->ShowHeader();
}

void InvestmentPlan::ShowResults() {
	double interestSum = 0;

	for (int i = 1; i <= numYears; i++) {  //This loop will go through the number of years the user inputs, print the year, and the year end balance
		std::cout << std::fixed << std::setprecision(2); //Sets the numbers to display only two decimal places
		std::cout << "   " << std::setw(20) << std::left << i << std::flush;
		std::cout << "$" << std::setw(30) << std::left << sumList.at((i * 12) - 1) << std::flush; //When printed this will also add a '$' in front of the numbers.

		for (int j = (i - 1) * 12; j <= (i * 12) - 1; j++) {
			std::cout << std::fixed << std::setprecision(2);
			interestSum += interestList.at(j);
		}

		std::cout << "$" << std::setw(10) << std::left << interestSum << std::endl; //Similar to the output above, this will print the user end interest with a '$' for better readability
		std::cout << std::endl;
	}
}
