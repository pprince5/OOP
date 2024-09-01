/***********************************************************************
// OOP244 Workshop #1 lab
//
// File  w1p1.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name: Prince Prince    Student ID: 145685228
// Date: 14-09-2023
// Student Email: pprince5@myseneca.ca
// Section:ZDD
// Reason
***********************************************************************/

#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;
int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}
