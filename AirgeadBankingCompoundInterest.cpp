//============================================================================
// Name        : AirgeadBankingCompoundInterest.cpp
// Author      : Rhianna Avery
// Version     : 2020.04.11.1
// Copyright   : Rhianna Avery 2020
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CompoundInterest.h"
using namespace std;

int main() {
	char userEntry = 'R';
	CompoundInterest compoundInterest;
	// Navigation Menu and Initiation //
	while (userEntry != 'Q') {
		compoundInterest.SetInterestVariables();
		cout << "Enter (C)ontinue, (R)e-enter, or (Q)uit:" << endl;
		cin >> userEntry;
		if (userEntry == 'C'){
			compoundInterest.LoadBalances();
		} else if ((userEntry != 'R') && (userEntry != 'Q')) {
			cout << "Please enter a valid response and try again." << endl;
		}
	}

	return 0;
}
