/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File: Graduate.h
// Version 1.0
// Date: 11/20/2022
// Author: Razi Iqbal
// Description: This program demonstrates the concept of Polymorphism
// using an example of Student and Graduate.
//
// Revision History
// -----------------------------------------------------------
// Name  prince          Date  23/11/2023          Reason
// Fardad          2023-11-02       review
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Email: pprince5@myseneca.ca
// Id: 145685228
// Section: ZDD
#ifndef _GRADUATE_H
#define _GRADUATE_H

#include "Student.h"
namespace sdds {
	class Graduate : public Student
	{
		char* supervisor;
		char* title;

	public:
		Graduate();
		Graduate(const char* name, int age, const char* title, const char* supervisor);
		//rule of three
		Graduate(const Graduate& obj);
		Graduate& operator=(const Graduate& obj);
		virtual ~Graduate();
		//
		//
		void display();

	};
}
#endif