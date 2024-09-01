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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}


	//TODO: read functions go here
	bool read(char*& E_Name) 
	{
		char Name[128];
		if (fscanf(fptr, "%127[^,\n]\n", Name) == 1) 
		{
			E_Name = new char[strlen(Name) + 1];
			strcpy(E_Name, Name);
			return true;
		}
		return false;
	}
	//
	bool read(int& E_Num)
	{
		if (fscanf(fptr, "%d,", &E_Num) == 1) 
		{
			return true;
		}
		return false;
	}
	//
	bool read(double& E_salary) 
	{
		if (fscanf(fptr, "%lf,", &E_salary) == 1) 
		{
			return true;
		}
		return false;
	}

}