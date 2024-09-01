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
#include "Population.h"
#include "File.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
	bool startsWith(const char* cstring, const char* subString)
	{
		return std::strstr(cstring, subString) == cstring;
	}



	int noOfRec;
	Population* records;

	void sort()// sort the data
	{
		int i, k;
		Population temp;
		for (i = noOfRec - 1; i > 0; i--)
		{
			for (k = 1; k < i + 1; k++)
			{
				if (records[k - 1].population > records[k].population)
				{
					temp = records[k - 1];
					records[k - 1] = records[k];
					records[k] = temp;
				}
			}
		}
	}
	//
	int T_populationPopulation()// calculate total number of population
	{
		int i;
		int T_population = 0;
		for (i = 0; i < noOfRec; i++)
		{
			T_population += records[i].population;
		}
		return T_population;
	}
	//
	bool getPostalCode(char* postal_code_prefix)// gets postal code from user
	{
		cout << "Population Report" << endl;
		cout << "-----------------" << endl;
		cout << "Enter postal code:" << endl << "> ";
		cin >> postal_code_prefix;

		return (strcmp(postal_code_prefix, "!") != 0);
	}

	// load reads one record from the file and loads it into the record argument
	bool load(Population& record)// overload function
	{
		bool readPostalOk = read(record.postalCode);
		bool readPopulationOk = read(record.population);
		return readPostalOk && readPopulationOk;
	}

	bool load(Population& record, const char* partial_postal_code_prefix) // overload function
	{
		bool readPostalOk = read(record.postalCode, partial_postal_code_prefix);
		bool readPopulationOk = read(record.population);
		return readPostalOk && readPopulationOk;
	}

	// load reads all the records from the file and loads them into the dynamically allocated array of postal codes.
	bool load(const char* filename)
	{
		bool ok = false;
		int i;
		if (!openFile(filename))
		{
			cout << "Could not open data file: " << filename << endl;
		}
		else
		{
			noOfRec = noOfRecords();
			records = new Population[noOfRec];
			for (i = 1; i < noOfRec + 1; i++)
			{
				if (!load(records[i - 1]))
				{
					cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
					deallocateMemory();
					return false;
				}
			}
			ok = true;
		}
		closeFile();
		return ok;
	}

	// load reads all the records from the file that start with prefix and loads them into the dynamically allocated array of postal codes.
	bool load(const char* filename, const char* partial_postal_code_prefix)
	{
		int noOfAllRec = 0;
		bool ok = false;
		int prefixedRecordsIndex = 0;
		int allRecordsIndex = 0;
		if (strcmp(partial_postal_code_prefix, "all") == 0)
		{
			return load(filename);
		}
		if (!openFile(filename))
		{
			cout << "Could not open data file: " << filename << endl;
		}
		else
		{
			noOfRec = noOfRecords(partial_postal_code_prefix);
			noOfAllRec = noOfRecords();
			records = new Population[noOfRec];

			while (allRecordsIndex < noOfAllRec && prefixedRecordsIndex < noOfRec)
			{
				if (load(records[prefixedRecordsIndex], partial_postal_code_prefix))
				{
					prefixedRecordsIndex++;
				}
				allRecordsIndex++;
			}
			ok = true;

		}
		closeFile();
		return ok;
	}

	//
	void display(int count, Population& record)
	{
		cout << count + 1 << "- " << record.postalCode << ":  " << record.population << endl;
	}
	//
	void display()
	{
		int i;
		int T_populationPop;
		sort();
		T_populationPop = T_populationPopulation();
		cout << "Postal Code: population" << endl;
		cout << "-------------------------" << endl;

		for (i = 1; i < noOfRec + 1; i++)
		{
			display(i - 1, records[i - 1]);
		}
		cout << "-------------------------" << endl;
		cout << "Population of the listed areas: " << T_populationPop << endl << endl;
	}
	//

	void deallocateMemory()
	{
		int i;
		for (i = 0; i < noOfRec; i++)
		{
			delete[] records[i].postalCode;
		}
		delete[] records;
	}




}