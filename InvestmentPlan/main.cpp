/*
Coded by Ron Causey
CS-210
2/1/2022
*/

#include "InvestmentPlan.h"
#include <cctype>
#include <string>

bool continueLoop(std::string prompt); //Using this to continue through the loop or terminate depending on user response.
void dataInput(InvestmentPlan* plan); //Used to grab user input. Will check for exceptions and will set the fields for the InvestmentPlan

int main() {
		std::cout << std::setw(40) << std::right << "************************************" << std::endl;
		std::cout << std::setw(40) << std::right << "*Welcome to the Airgead Banking App*" << std::endl;
		std::cout << std::setw(40) << std::right << "************************************" << std::endl;
		std::cout << std::endl;
		system("pause");
		system("cls");

	InvestmentPlan* plan = new InvestmentPlan;
	bool flag = true;

	while (flag) {
		dataInput(plan);
		plan->ShowHeader1(); 
		plan->CalculateInterest();
		plan->ShowResults();
		plan->SetDeposit(0);
		plan->ShowHeader2();
		plan->CalculateInterest();
		plan->ShowResults();

		flag = continueLoop("Exit? (Y/N) "); //Prompt to see if user would like to continue or exit
		system("cls"); //If they continue the screen will clear to give the user a fresh console to work with
	}
	return 0;
}

bool continueLoop(std::string prompt) {
	bool flag = true;

	std::string userInput;
	std::cout << prompt;
	std::cin >> userInput;

	if (tolower(userInput.at(0)) == 'y') { //When the user enters 'y' this will terminate the program
		flag = false;
	}

	std::cout << std::endl;
	return flag;
}

void dataInput(InvestmentPlan* plan) {
	//Variables we will be using to store the user input data
	int numYears;
	double annualInterest;
	double initialAmount;
	double depositAmount;

	bool flag = true;
	std::string user_continue;

	while (flag) {
		std::cout << std::setw(40) << std::right << "********************************" << std::endl;
		std::cout << std::setw(40) << std::right << "********** Data Input **********" << std::endl;
		std::cout << std::setw(40) << std::right << "********************************" << std::endl;
		std::cout << std::endl;

		//Loop will try and catch exceptions if a user inputs a number outside the desired range.
		try {
			std::cout << "Initial Investment Amount: $" << std::flush;
			std::cin >> initialAmount;
			if (initialAmount < 0) {
				throw std::runtime_error("Starting Amount must greater than 0.");
			}

			std::cout << "Monthly Deposit: $" << std::flush;
			std::cin >> depositAmount;

			if (depositAmount < 0) {
				throw std::runtime_error("Monthly Deposit must be greater than 0.");
			}

			std::cout << "Annual Interest: %" << std::flush;
			std::cin >> annualInterest;

			if (annualInterest < 0) {
				throw std::runtime_error("Annual Interest must be greater than 0.");
			}
			
			std::cout << "Number of years: " << std::flush;
			std::cin >> numYears;

			if (numYears < 1) {
				throw std::runtime_error("Number of Years must be 1 or greater.");
			}

			system("pause"); //Prompts user to press any key to continue
			flag = false; //Leaves the while loop
			system("cls"); /*Clears screenand below will print the user inputs.
						   This will clear out the "press any key to continue" while still letting the user see what they entered*/

			std::cout << std::setw(40) << std::right << "********************************" << std::endl;
			std::cout << std::setw(40) << std::right << "********** Data Input **********" << std::endl;
			std::cout << std::setw(40) << std::right <<"********************************" << std::endl;
			std::cout << "Initial Investment Amount: $" << initialAmount << std::endl;
			std::cout << "Monthly Deposit: $" << depositAmount << std::endl;
			std::cout << "Annual Interest: %" << annualInterest << std::endl;
			std::cout << "Number of years: " << numYears << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}

		catch (std::runtime_error& error) { //If error caught it will display the error message to the user
			std::cout << "Error: " << error.what() << std::endl;
			std::cout << std::endl;
		}
	}
	
	plan->SetData(numYears, annualInterest, initialAmount, depositAmount);
}