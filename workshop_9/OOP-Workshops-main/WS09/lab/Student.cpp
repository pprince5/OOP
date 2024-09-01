/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File: Student.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Student.h"

using namespace std;
namespace sdds {
	Student::Student()
	{
		name = nullptr;
		age = 0;

	}
	Student::Student(const char* name, int age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->age = age;
	}
	Student::Student(const Student& obj)
	{
		if (obj.name != nullptr) {
			name = new char[strlen(obj.name) + 1];
			strcpy(name, obj.name);
		}
		age = obj.age;
	}
	Student& Student::operator=(const Student& obj)
	{
		if (this != &obj)
		{


			delete[] name;
			name = nullptr;
			name = new char[strlen(obj.name) + 1];
			strcpy(name, obj.name);

			age = obj.age;
		}

		return *this;
	}
	Student::~Student()
	{
		delete[] name;
	}

	void Student::display()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
}

