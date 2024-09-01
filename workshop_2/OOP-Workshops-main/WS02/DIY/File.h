/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
//  Full Name : Prince Prince
//	Email : pprince5@myseneca.ca
//  Student ID# : 145685228
//	Section : OOP244 ZBB
//	Authenticity Declaration :
//I hereby decalre that i have done the code independently and only copied code that
//was provided by the professor to help with workshops and assignments.

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#define MAX_POSTAL_CODE_LEN 3
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes
	int noOfRecords(const char* postalCodePrefix);
	//
	bool read(char*& postalCode);
	//
	bool read(int& population);
	//
	bool read(char*& postalCode, const char* partial_postal_code_prefix);
}
#endif