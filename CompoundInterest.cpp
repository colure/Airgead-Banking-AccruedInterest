/*
 * CompoundInterest.cpp
 *
 *  Created on: Apr 11, 2020
 *      Author: rhiannaavery
 */

#include <iostream>
#include <iomanip>

#include "CompoundInterest.h"
using namespace std;

CompoundInterest::CompoundInterest() {
	//initialize variables
	initialInvestment = 0.0;
	monthlyDeposit  = 0.0;
	annualInterest = 0;
	numYears = 0;
	numMonths = 0;
}

//assigning the values of input into variables
void CompoundInterest::SetInvestment(string doubleInput) {
	initialInvestment = CompoundInterest::StrToDouble(doubleInput, '$');
}
void CompoundInterest::SetDeposit(string doubleInput) {
	monthlyDeposit = CompoundInterest::StrToDouble(doubleInput, '$');
}
void CompoundInterest::SetInterest(string doubleInput) {
	annualInterest = CompoundInterest::StrToDouble(doubleInput, '%');
}
void CompoundInterest::SetYears(int intInput) {
	numYears = intInput;
}
double CompoundInterest::StrToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

//header for the results
void CompoundInterest::PrintHeader(string contentWithOut) {
	//Only need one function to Complete printing both titles.
	cout << setw(65) << setfill('-') << "" << endl;
	cout << right << setw(60) << setfill(' ') << contentWithOut << endl;
	cout << setw(65) << setfill('-') << "" << endl;
	cout << setw(65) << setfill('-') << "" << endl;
	cout << setw(6) << setfill(' ') << "Year";
	cout << setw(24) << "Year End Balance";
	cout << setw(35) << "Year End Earned Interest";
	cout << endl;
}

void CompoundInterest::PrintValues(vector<Balances> currVect, int i) {
	//Getting the values of interest calculated added up.
	double tempInterestSum = 0;
	for (int j = i; j > (i-12); --j) {
		tempInterestSum = currVect.at(j).interest + tempInterestSum;
	}

	//Printing out the contents after every 12 months.
	cout << setw(6) << setfill(' ') << (currVect.at(i).months / 12);
	cout << setw(12) << "$";
	cout << setw(12) << fixed << setprecision(2) << currVect.at(i).closingAmount;
	cout << setw(25) << "$";
	cout << setw(10) << fixed << setprecision(2) << tempInterestSum;
	cout << endl;
}

//requesting the input from the user sets the base variables for calculating
void CompoundInterest::SetInterestVariables() {
	string doubleInput;
	int intInput;

	cout << setw(65) << setfill('-') << "" << endl;
	cout << setw(27) << setfill('-') << "";
	cout << " Data Input ";
	cout << setw(26) << setfill('-') << "" << endl;
	cout << "Initial Investment:" << endl;
	cin >> doubleInput;
	CompoundInterest::SetInvestment(doubleInput);
	cout << "Monthly Deposit:" << endl;
	cin >> doubleInput;
	CompoundInterest::SetDeposit(doubleInput);
	cout << "Annual Interest:" << endl;
	cin >> doubleInput;
	CompoundInterest::SetInterest(doubleInput);
	cout << "Number of Years:" << endl;
	cin >> intInput;
	CompoundInterest::SetYears(intInput);
}

void CompoundInterest::LoadBalances() {
	vector<Balances> withoutDeposit;
		//setting up a vector containing the monthly balances without deposits
		try {
			numMonths = numYears*12;
			withoutDeposit.resize(numMonths);

			//writing the header!
			CompoundInterest::PrintHeader("Balance and Interest Without Additional Monthly Deposits");
		    // loop to create
		    for (int i = 0; i < numMonths; i++) {
		    	// Create a data structure and add to the collection of balances
		        Balances balance;
		        if (i == 0) {
		        	//for first month only
		        	balance.openingAmount = initialInvestment;
		        } else {
		        	balance.openingAmount = withoutDeposit.at(i-1).closingAmount;
		        }
		        balance.months = i+1;
		        balance.total = balance.openingAmount;
		        balance.interest = (balance.total * ((annualInterest/100.0)/12.0));
		        balance.closingAmount = balance.openingAmount + balance.interest;
		        withoutDeposit.at(i) = balance;
		        if (balance.months % 12 == 0) {
		        	CompoundInterest::PrintValues(withoutDeposit, i);
		        }
		        }
		    cout << endl;
		    cout << endl;
		    } catch(...) {
		        cout << "Something went wrong. :(" << endl;
		    }
	vector<Balances> includingDeposit;
		    //setting up a vector containing the monthly balances with deposits
		    try {
		    	includingDeposit.resize(numMonths);

		    	//writing the header!
		    	CompoundInterest::PrintHeader("Balance and Interest Include Additional Monthly Deposits");

		    	// loop to create
		    	for (int i = 0; i < numMonths; i++) {
		    		// Create a data structure and add to the collection of balances
		    		Balances balance;
		    		if (i == 0) {
		    		//for first month only
		    		balance.openingAmount = initialInvestment;
		    		} else {
		    		balance.openingAmount = includingDeposit.at(i-1).closingAmount;
		    		}
		    		balance.months = i+1;
		    		balance.total = balance.openingAmount + monthlyDeposit;
		    		balance.interest = balance.total * ((annualInterest/100.0)/12.0);
		    		balance.closingAmount = balance.total + balance.interest;
		    		includingDeposit.at(i) = balance;
		    		if (balance.months % 12 == 0) {
		    			CompoundInterest::PrintValues(includingDeposit, i);
		    		}
		    		}
		    } catch(...) {
		    cout << "Something went wrong. :(" << endl;
		    }
}

