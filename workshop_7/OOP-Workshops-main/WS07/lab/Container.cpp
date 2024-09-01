/***********************************************************************
// OOP244 Workshop #7 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name prince        Date 13-11-2023           Reason
***********************************************************************/
//student ID: 145685228
// Mail: pprince5@myseneca.ca
// Section: zdd
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "Container.h"
namespace sdds
{
	//
	//constructor
	//
	Container::Container(const char* Content, int capacity, int volume)
	{
		if (Content == nullptr || volume > capacity)
		{
			isContainerValid = false;
		}
		else
		{
			strcpy(Description, Content);
			Capacity = capacity;
			contentVolume = volume;
			isContainerValid = true;
		}
	}
	//
	//
	void Container::setEmpty()
	{
		isContainerValid = false;
	}
	//
	//
	//
	int Container::capacity()
	{
		return Capacity;
	}
	int Container::volume()
	{
		return contentVolume;
	}
	//
	//
	int Container::operator+=(int value)
	{
		int	totalVolume = value + contentVolume;
		if (totalVolume <= Capacity)
		{
			contentVolume += value;

		}
		else
		{
			value = Capacity - contentVolume;
			contentVolume += value;
		}
		return value;
	}
	int Container::operator-=(int value)
	{
		if (value < contentVolume)
		{
			contentVolume -= value;
		}
		else
		{
			value = contentVolume;
			contentVolume = 0;
		}
		return value;

	}
	//
	//
	//
	bool Container::validity()
	{
		return isContainerValid;

	}
	//
	//
	void Container::clear(int capacityValue, const char* m_description)
	{
		if (capacityValue >= 0 && m_description != nullptr && strlen(m_description) >= 1)
		{
			this->Capacity = capacityValue;
			strcpy(this->Description, m_description);
			contentVolume = 0;
			isContainerValid = true;
		}
	}
	//
	//
	//
	ostream& Container::print(ostream& os)
	{
		if (isContainerValid)
		{
			os << Description << ": (" << contentVolume << "cc/" << Capacity << ")";

		}
		else
		{
			os << "****: (**cc/***)";
		}
		return os;

	}
	istream& Container::read(istream& is)
	{
		int inputValue;
		int quitLoop = 0;
		if (!isContainerValid)
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
			is.ignore();

		}
		else
		{
			cout << "Add to ";
			print(cout);
			while (quitLoop == 0)
			{
				cout << endl << "> ";
				is >> inputValue;
				if (is.fail())
				{
					cout << "Invalid Integer, retry: ";

				}
				else if (inputValue < 1 || inputValue > 999)
				{
					cout << "Value out of range [1<=val<=999]: ";
				}
				else
				{
					quitLoop = 1;
				}


			}
			inputValue = (*this += inputValue);
			cout << "Added " << inputValue << " CCs" << endl;
		}
		return is;

	}
	//
	//
	//
	ostream& operator<<(ostream& os, Container& obj)
	{
		return obj.print(os);
	}
	istream& operator>>(istream& is, Container& obj)
	{
		return obj.read(is);
	}
}