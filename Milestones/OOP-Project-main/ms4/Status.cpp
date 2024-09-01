/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: Status.cpp
// Version 1.1
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Prince              28-11-4
***********************************************************************/
// ID: 145685228
// mail: pprince5@seneca.ca
// Section:: ZDD
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Status.h"
#include"Utils.h"
using namespace std;
namespace sdds
{
	//constructor
	Status::Status()
	{
		description = nullptr;
		code = 0;
	}
	Status::Status(const char* refDescription)
	{
		code = 0;
		if (refDescription != nullptr)
		{
			ut.alocpy(description, refDescription);
		}
		else
		{
			description = nullptr;
		}

	}
	Status::Status(const Status& obj)
	{
		if (obj.description != nullptr)
		{
			ut.alocpy(description, obj.description);
			code = obj.code;
		}
		else
		{
			delete[] description;
			description = nullptr;
			code = 0;
		}

	}
	Status& Status::clear()
	{
		if (description != nullptr)
		{
			delete[] description;
			description = nullptr;
			code = 0;
		}

		return *this;
	}
	Status& Status::operator = (const char* refDescription)
	{
		if (refDescription != nullptr)
		{
			ut.alocpy(description, refDescription);

		}
		return*this;
	}
	Status& Status::operator=(const int refCode)
	{
		code = refCode;
		return *this;

	}
	Status::operator int() const
	{
		return code;
	}
	Status::operator const char* () const
	{
		return description;
	}
	Status::operator bool() const
	{
		return(description == nullptr);
	}

	std::ostream& Status::printStatus(std::ostream& obj) const
	{
		if (code != 0)
		{
			obj << "ERR#" << code << ": ";
			obj << description;
		}
		else
		{
			obj << description;

		}
		return obj;
	}
	Status::~Status()
	{
		if (description != nullptr)
		{
			delete[] description;
			description = nullptr;
		}

	}
	std::ostream& operator<<(std::ostream& os, const Status& obj)
	{
		if (!obj)
		{
			obj.printStatus(os);
		}
		return os;
	}


}

