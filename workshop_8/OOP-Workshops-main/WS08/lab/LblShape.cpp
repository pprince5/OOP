#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "LblShape.h"
#include "Shape.h"
using namespace std;
namespace sdds {

	const char* Lblshape::label() const
	{
		return m_label;
	};
	//
	//
	Lblshape::Lblshape()
	{
		if (this->m_label != nullptr) {
			m_label = nullptr;
		}

	};
	Lblshape::Lblshape(const char* string)
	{
		delete[] this->m_label;
		m_label = nullptr;
		m_label = new char[strlen(string) + 1];
		strcpy(m_label, string);
	};
	Lblshape::~Lblshape()
	{
		delete[] m_label;
		m_label = nullptr;
	};
	void Lblshape::getspecs(std::istream& is)
	{
		char buffer[100];
		is.get(buffer, 100, ',');
		is.ignore();
		//
		delete[] this->m_label;
		m_label = new char[strlen(buffer) + 1];
		strcpy(m_label, buffer);

	};

}