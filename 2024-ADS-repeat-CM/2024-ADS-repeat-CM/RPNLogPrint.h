#include <iostream>
#include "RPNCalculator.h"
#include <string>
#include <fstream>
#include <sstream>


using namespace std;

void writelog() {

	RPNCalculator<int> history;
	ifstream RPNhistory;
	RPNhistory.open("C:\2024-- - ADS-- - Repeat-- - CM\2024 - ADS - repeat - CM\RPNCalculatorTest\RPN.log.csv");

	RPNhistory.open("RPN.log.csv", ios::out);


	string historyline;

	while (getline(RPNhistory, historyline)) {
		string outputnumber;

		stringstream RPNlog(historyline);
		

	}

	RPNhistory.close();


}