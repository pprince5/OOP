/***********************************************************************
// OOP244 Workshop #4 DIY (part 2): Label tester program
//
// File  labelTester.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name  prince               Date  9-10-2023          Reason
***********************************************************************/
// Student Id: 145685228
// Mail: pprince5@myseneca.ca
// Section: ZDD

#include <iostream>
#include "Label.h"
using namespace std;
using namespace sdds;
int main() {
   Label title;
   Label L("AbCdEfGh");
   cout << ">";
   title.printLabel() << "<" << endl;
   title.text("Enter a label text!");
   title.printLabel() << endl << "> ";
   L.readLabel();
   L.printLabel();
   return 0;
}