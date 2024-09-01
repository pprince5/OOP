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

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include "File.h"
#include "Population.h"

namespace sdds {
	FILE* fptr;
	bool openFile(const char filename[])
    {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() 
    {
		int num_records = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) 
        {
			num_records += (ch == '\n');
		}
		rewind(fptr);
		return num_records;
	}
	void closeFile() 
    {
		if (fptr) fclose(fptr);
	}


	//TODO: read functions go here
	int noOfRecords(const char* postalCodePrefix) // number of records according to  postal code provided
    {
		int num_records = 0;
		char postalCode[MAX_POSTAL_CODE_LEN + 1];
		int population;
		while (fscanf(fptr, "%3s,%d\n", postalCode, &population) == 2) 
        {
			if (startsWith(postalCode, postalCodePrefix)) 
            {
				num_records++;
			}
		}
		rewind(fptr);
		return num_records;
	}
    //
    bool read(char*& postalCode)
    {
        char temp[MAX_POSTAL_CODE_LEN + 1];
        bool successful = fscanf(fptr, "%3s,", temp) == 1;
        if (successful)
        {
            postalCode = new char[strlen(temp) + 1];
            strcpy(postalCode, temp);
        }
        return successful;
    }
    //
    bool read(int& population)
    {
        return fscanf(fptr, "%d\n", &population) == 1;
    }
    //
    bool read(char*& postalCode, const char* partial_postal_code_prefix)
    {
        char temp[MAX_POSTAL_CODE_LEN + 1];
        bool successful = fscanf(fptr, "%3s,", temp) == 1;
        if (successful)
        {
            if (startsWith(temp, partial_postal_code_prefix))
            {
                postalCode = new char[strlen(temp) + 1];
                strcpy(postalCode, temp);
            }
            else
            {
                successful = false;
            }
        }
        return successful;
    }

}