/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: iProduct.cpp
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
#include"iProduct.h"
using namespace std;
namespace sdds
{

	std::ostream& operator<<(std::ostream& os, const iProduct& product)
	{
		product.display(os);
		return os;
	}
	//insertion
	std::istream& operator>>(std::istream& is, iProduct& product)
	{
		product.read(is);
		return is;
	}
}