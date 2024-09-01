#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_CARINVENTORY_H
#define SDDS_CARINVENTORY_H
#include "string.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
namespace sdds
{

	class CarInventory {

		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		//
		void resetInfo();
		//
		//

	public:
		CarInventory();
		//
		CarInventory(const char* type, const char* brand, const char* model);
		//CarInventory(char* type, char* brand, char* model);
		CarInventory(const char* type, const char* brand, const char* model, int year, int code , double price);
		//
		~CarInventory();
		//
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		//
		void printInfo() const;
		//
		bool isValid() const;
		//
		bool isSimilarTo(const CarInventory& car) const;
		//
		
	};
	int find_similar(CarInventory car[], const int num_cars);
}
#endif
//
////
//void CarInventory::resetInfo()
//{
//	delete[] m_type;
//	m_type = nullptr;
//	delete[] m_brand;
//	m_brand = nullptr;
//	delete[] m_model;
//	m_model = nullptr;
//	m_year = 0;
//	m_code = 0;
//	m_price = 0;
//
//};
////
//CarInventory::CarInventory() {
//	resetInfo();
//}
//
////CarInventory(char* type, char* brand, char* model);
//CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0)
//{
//	if (type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0) {
//		m_type = new char[strlen(type) + 1];
//		strcpy(m_type, type);
//
//		m_brand = new char[strlen(brand) + 1];
//		strcpy(m_brand, brand);
//
//		m_model = new char[strlen(model) + 1];
//		strcpy(m_model, model);
//
//		m_year = year;
//		m_code = code;
//		m_price = price;
//	}
//	else {
//		// If validation fails, set default values
//		resetInfo();
//	}
//}
// //
//CarInventory::~CarInventory() {
//
//	delete[] m_type;
//	delete[] m_brand;
//	delete[] m_model;
//}
//
//
//CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) 
//{
//	resetInfo();
//	if (type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0) {
//		m_type = new char[strlen(type) + 1];
//		strcpy(m_type, type);
//
//		m_brand = new char[strlen(brand) + 1];
//		strcpy(m_brand, brand);
//
//		m_model = new char[strlen(model) + 1];
//		strcpy(m_model, model);
//
//		m_year = year;
//		m_code = code;
//		m_price = price;
//	}
//	return *this;
//
//
//}
////
//void CarInventory::printInfo() const
//{
//
//	cout << "Order" << endl;
//
//}
//bool CarInventory::isValid() const
//{
//	if (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0)
//	{
//
//		return true;
//	}
//
//	return false;
//}
////
//bool CarInventory::isSimilarTo(const CarInventory& car) const 
//{
//
//	if (m_type && m_brand && m_model && m_year &&car.m_type && car.m_brand && car.m_model && car.m_year) 
//	{
//
//		if (car.m_type == m_type && car.m_brand == m_brand && car.m_model == m_model && car.m_model == m_model) 
//		{
//			return true;
//		}
//		return false;
//	}
//	else 
//	{
//		return false;
//	}
//
//}
////
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


