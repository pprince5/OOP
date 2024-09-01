#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{

	void CarInventory::resetInfo()
	{
		//delete[] m_type;
		m_type = nullptr;
		//delete[] m_brand;
		m_brand = nullptr;
		//delete[] m_model;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0.0;

	};
	//
	CarInventory::CarInventory() 
	{
		resetInfo();
	}
	//
	CarInventory::CarInventory(const char* type, const char* brand, const char* model)
	{
		resetInfo();
		m_type = new char[strlen(type) + 1];
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];
		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		m_year = 2022;
		m_code = 100;
		m_price = 1.0;

	}
	//
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year , int code, double price )
	{
		resetInfo();

		resetInfo();
		m_type = new char[strlen(type) + 1];
		m_brand = new char[strlen(brand) + 1];
		m_model = new char[strlen(model) + 1];
		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		//checking the default conditions
		m_year = (year >= 1990) ? year : 2022;
		m_code = (code >= 100 && code <= 999) ? code : 100;
		if (price > 0)
		{
			m_price = price;
		}
		else
		{
			m_price = 1.0;
		}
	}
	//
	CarInventory::~CarInventory() {

		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}


	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price)
	{
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;

		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);

		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);

		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);

		m_year = year;
		m_code = code;
		m_price = price;

		return *this;


	}
	//
	void CarInventory::printInfo() const
	{

		cout.setf(ios::left); //setting format to left alignment
		cout << "| ";
		cout.width(10);

		cout << m_type;
		cout << " | ";

		cout.width(16);
		cout << m_brand;

		cout << " | ";
		cout.width(16);
		cout << m_model;

		cout << " | ";
		cout.unsetf(ios::left);
		cout.width(4);
		cout.setf(ios::right);
		cout << m_year;

		cout << " | ";
		cout.width(4);
		cout << m_code;

		cout << " | ";
		cout.width(9);

		cout.precision(2);
		cout.setf(ios::fixed);
		cout << m_price;
		cout.unsetf(ios::right);
		cout << " |" << "\n";

	}
	bool CarInventory::isValid() const
	{
		if (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0)
		{

			return true;
		}

		return false;
	}
	//
	bool CarInventory::isSimilarTo(const CarInventory& car) const
	{

		if (m_type && m_brand && m_model && m_year && car.m_type && car.m_brand && car.m_model && car.m_year)
		{

			if (strcmp(m_type, car.m_type) == 0 && (strcmp(m_brand, car.m_brand) == 0) && (strcmp(m_model, car.m_model) == 0 && m_year == car.m_year))
			{
				return true;
			}
			return false;
		}
		else
		{
			return false;
		}

	}
	//
	int find_similar(CarInventory car[], const int num_cars)
	{
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isValid() && car[j].isValid() && car[i].isSimilarTo(car[j])) {
					return i;
				}
			}
		}
		return -1;
	}
}
//int CarInventory::find_similar(CarInventory car[], const int num_cars)
//{
//	for (int i = 0; i < num_cars; i++) {
//		for (int j = i + 1; j < num_cars; j++) {
//			if (car[i].isSimilarTo(car[j])) {
//				return i;
//			}
//		}
//	}
//
//}