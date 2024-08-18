#pragma once
#include <iostream>
#include <iterator>
#include <sstream>
#include <map>
#include "MenuOptions.h"
#include "RPNCalculator.h"



using namespace std;

struct OptionsData {

	MenuOptions menuOption;
	double value;
	string valueMessage;
};

// colour code https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a  date accessed 15/08/24  line 24-32 

struct Colours {

const string BLKB = "\u001B[0;30m";
const string REDB = "\u001B[0;31m";
const string GRNB = "\u001B[0;32m";
const string YELB = "\u001B[0;33m";
const string BLUB = "\u001B[0;34m";
const string MAGB = "\u001B[0;35m";
const string CYNB = "\u001B[0;36m";
const string WHTB = "\u001B[0;37m";
const string reset = "\u001B[0m";

};

class App {



private:
	map <string, MenuOptions> menuoOptionsMap;
	OptionsData optionsData;
	RPNCalculator<double>* calc;
	Colours colours;
	void printMenu();
	void calculatorOperation();
	void welcomeMessage();
	void setMenuOption();
	bool isNumber(const string& s);
	void setValue();


public: 
	App(const string& filePath);
	void startUp();

};
