/***********************************************************************
// OOP244 Workshop #3 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Cornel Barna, Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                    Date                   Reason
// Prince Prince    September 29,2023
***********************************************************************/
// Section : ZDD
// mail: pprince5@myseneca.ca

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Train.h"
using namespace std;
using namespace sdds;


void Train::initialize()
{
	Train_Name = nullptr;
	Number_passenger = -1;
	departureTime = -1;

}
bool Train::validTime(int value) const
{
	if (value <= MAX_TIME && value >= MIN_TIME)
	{
		int minutes = value % 100;
		if (minutes <= 59)
		{
			return true;

		}

	}
	return false;
}

bool Train::validNoOfPassengers(int value) const
{
	if (value > 0 && value < MAX_NO_OF_PASSENGERS)
	{
		return true;
	}
		return false;


	
}
//
void Train::set(const char* name)
{
	finalize();
	if (name != nullptr && name[0] != '\0')
	{
		Train_Name = new char[strlen(name) + 1];

		strcpy(Train_Name, name);
	}

}
//
void Train::set(int noOfPassengers, int departure)
{
	if (validTime(departure) && validNoOfPassengers(noOfPassengers))
	{
		Number_passenger = noOfPassengers;
		departureTime = departure;
	}
	else
	{
		Number_passenger = -1;
		departureTime = -1;
	}


}
//
void Train::set(const char* name, int noOfPassengers, int departure)
{
	set(name);
	set(noOfPassengers, departure);
}
//
void Train::finalize()
{
	if (Train_Name != nullptr)
	{
		delete[] Train_Name;
		Train_Name = nullptr;

	}

}
//
bool Train::isInvalid() const
{
	if ( Number_passenger == -1 || departureTime == -1 || Train_Name == nullptr)
	{
		return true;
	}
		return false;


}
//
int Train::noOfPassengers() const
{
	return Number_passenger;

}
//
const char* Train::getName() const
{
	return Train_Name;
}
//
int Train::getDepartureTime() const
{
	return departureTime;
}
//
void Train::display() const
{
	if (!(isInvalid()))
	{
		cout << "NAME OF THE TRAIN:    " << Train_Name << endl;
		cout << "NUMBER OF PASSENGERS: " << Number_passenger << endl;
		cout << "DEPARTURE TIME:       " << departureTime << endl;
	}
	else
	{
		cout << "Train in an invalid State!" << endl;
	}

}







