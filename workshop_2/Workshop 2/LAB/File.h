//*****************************************************************************
//<assessment name: Workshop - #2 (Part - 1)>
//  Full Name : Prince Prince
//	Email : pprince5@myseneca.ca
//  Student ID# : 145685228
//	Section : OOP244 ZBB
//	Authenticity Declaration :
//I hereby decalre that i have done the code independently and only copied code that
//was provided by the professor to help with workshops and assignments.
//* ****************************************************************************

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare overloaded read function prototypes

	bool read(int& E_Num);
	//
	bool read(double& E_salary);
	//
	bool read(char*& E_Name);
}
#endif