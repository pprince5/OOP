/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File: Student.h
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
#ifndef _STUDENT_H
#define _STUDENT_H
#include "cstring"
#include <iostream>

namespace sdds {
	class Student
	{
		char* name;
		int age;

	public:
		Student();
		Student(const char* name, int age);
		Student(const Student& obj);
		Student& operator=(const Student& obj);
		virtual ~Student();
		void display();
	};
}
#endif