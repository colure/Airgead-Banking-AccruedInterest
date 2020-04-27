/*
 * CompoundInterest.h
 *
 *  Created on: Apr 11, 2020
 *      Author: rhiannaavery
 */

#ifndef COMPOUNDINTEREST_H_
#define COMPOUNDINTEREST_H_

#include <iomanip>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

//structure to hold information about balances
struct Balances {
	int months; // identifier for each item in includingDeposit and withoutDeposit.
	double openingAmount;
	double depositedAmount;
	double total;
	double interest;
	double closingAmount;
};

class CompoundInterest {
public:
	CompoundInterest();
	void SetInterestVariables();
	void LoadBalances();
private:
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numYears;
	int numMonths;
	double StrToDouble(string str, char ch);
	void SetInvestment(string doubleInput);
	void SetDeposit(string doubleInput);
	void SetInterest(string intInput);
	void SetYears(int numYears);
	void PrintHeader(string contentWithOut);
	void PrintValues(vector<Balances> currVect, int i);
};


#endif /* COMPOUNDINTEREST_H_ */
