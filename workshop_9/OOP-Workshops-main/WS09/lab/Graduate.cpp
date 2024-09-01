/***********************************************************************
// OOP244 Workshop # 9: tester program
//
// File: Graduate.cpp
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
#include "iostream"
#include "Graduate.h"
using namespace std;
namespace sdds {
	Graduate::Graduate():Student()
	{
		supervisor = nullptr;
		title = nullptr;


	}
	Graduate::Graduate(const char* name, int age, const char* title, const char* supervisor) :Student(name, age)
	{
		this->supervisor = new char[strlen(supervisor) + 1];
		strcpy(this->supervisor, supervisor);

		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);

	}
	Graduate::Graduate(const Graduate& obj):Student(obj)
	{
		if (obj.title != nullptr) {
			title = new char[strlen(obj.title) + 1];
			strcpy(title, obj.title);
		}

		if (obj.supervisor != nullptr) {
			supervisor = new char[strlen(obj.supervisor) + 1];
			strcpy(supervisor, obj.supervisor);
		}
	}
	Graduate& Graduate::operator=(const Graduate& obj)
	{
	
		if (this != &obj)
		{
			Student::operator=(obj);
			delete[] title;
			title = nullptr;
			if (obj.title != nullptr) {
				title = new char[strlen(obj.title) + 1];
				strcpy(title, obj.title);
			}

			delete[] supervisor;
			supervisor = nullptr;
			if (obj.supervisor != nullptr) {
				supervisor = new char[strlen(obj.supervisor) + 1];
				strcpy(supervisor, obj.supervisor);
			}
		}
		return *this;

	}
	Graduate::~Graduate()
	{
		delete[] supervisor;
		delete[] title;
		
	}
	//
	//
	void Graduate::display()
	{
		Student::display();
		cout << "Thesis Title: " << title;
		cout << "\nSupervisor: " << supervisor;
		cout << "\n---------------------------------------------\n";

	}
}





