/***********************************************************************
// Final project Milestone 3
// Module: iProduct and Item
// File: iProduct.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name prince            Date 24/11/2023            Reason
***********************************************************************/
// Id: 145685228
// Mail: pprince5@myseneca.ca
// section: zdd
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