/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Prince                Date 13-october-2023           Reason
***********************************************************************/
//Student id: 145685228
// Mail: pprince5@myseneca.ca
// Section: zdd
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

	void Flight::emptyPlane() {
		m_passengers = 0;
		m_fuel = 0;
		strcpy(m_title, "EmptyPlane");
	}

	// New Flight
	Flight::Flight() {
		emptyPlane();
	}
	Flight::Flight(int passengers, double fuel, const char* title) {
		emptyPlane();
		if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
			fuel <= FuelTankCapacity) {
			m_passengers = passengers;
			m_fuel = fuel;
			strcpy(m_title, title);
		}
	}
	//
	Flight::operator bool() const
	{

		return m_passengers > 0 && (m_fuel >= m_passengers*600);

	}
	//
	Flight::operator int() const {
		return this->m_passengers;

	}
	//
	Flight::operator double() const {
		return this->m_fuel;

	}
	//
	Flight::operator const char* () const {

		return this->m_title;
	}
	//
	bool Flight::operator~() const {
		return (m_passengers == 0);
	}
	//
	Flight& Flight::operator=(Flight& flight) {


		if (this == &flight) //checks if the argument and current object are same or not
		{
			return *this;
		}
		else
		{
			this->m_passengers = flight.m_passengers;
			this->m_fuel = flight.m_fuel;
			strcpy(this->m_title, flight.m_title);

			flight.emptyPlane();
			/* flight.m_passengers = 0;
			 flight.m_fuel = 0.0;
			 strcpy(flight.m_title, "");*/
			return *this;
		}


	}
	//
	Flight& Flight::operator=(int num_pass) {

		if (num_pass > 0 && num_pass <= Boen747Capacity)
		{

			this->m_passengers = num_pass;

		}
		return *this;
	}
	//
	Flight& Flight::operator=(double fuel) {

		if (fuel > 0 && fuel < FuelTankCapacity) {
			this->m_fuel = fuel;
		}
		return *this;
	}
	//
	Flight& Flight::operator+=(double add_fuel) {
		if (add_fuel > 0) {

			this->m_fuel += add_fuel;
		}
		if (m_fuel > FuelTankCapacity)
		{

			m_fuel = FuelTankCapacity;
		}
		return *this;

	}
	//
	Flight& Flight::operator+=(int add_passenger) {

		if (add_passenger > 0)
		{

			this->m_passengers += add_passenger;
		}
		if (this->m_passengers > Boen747Capacity)
		{
			this->m_passengers = Boen747Capacity;
		}


		return*this;
	}
	//
	Flight& Flight::operator-=(double reduce_fuel) {

		if (reduce_fuel > 0)
		{

			this->m_fuel -= reduce_fuel;
		}
		if (this->m_fuel < 0)
		{
			this->m_fuel = 0;
		}

		return*this;
	}
	//
	Flight& Flight::operator-=(int reduce_passenger) {

		if (reduce_passenger > 0)
		{

			this->m_passengers -= reduce_passenger;
		}
		if (this->m_passengers < 0)
		{

			this->m_passengers = 0;
		}

		return *this;
	}
	//
	//
	Flight& Flight::operator<<(Flight& right_flight) {

		if (this == &right_flight)
		{
			return *this;
		}

		if (*this && right_flight) {

			int totalPassengers;
			totalPassengers = m_passengers + right_flight.m_passengers;
			if (totalPassengers > Boen747Capacity) //checking if total passengers is more than the max capacity
			{
				m_passengers = Boen747Capacity;
				right_flight.m_passengers = (totalPassengers - Boen747Capacity);

			}
			else
			{
				m_passengers = totalPassengers;
				right_flight.m_passengers = 0;


			}

		}
		return *this;


	}
	//
	Flight& Flight::operator>>(Flight& right_flight) {


		right_flight << *this;
		return *this;

	}
	//
	int Flight::operator+(const Flight& flight){

		int sum;
		if (*this && flight) {
			sum = this->m_passengers + (int)flight;
			return sum;
		}
		return 0;
	}
	int operator+=(int& left, const Flight& right) {

		left += (int)right;

		return left;
	}


	std::ostream& Flight::display() const {

		if (*this) 
		{
			cout << " Flight  |  Ready to Depart";
			cout << " ";
			cout.width(10);
			cout << std::string(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		else if (~*this) 
		{
			cout << " Flight  |  Empty Plane    ";
		}
		else {
			cout << " Flight  |  Low Fuel       ";
			cout << " ";
			cout.width(10);
			cout << (const char*)(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		return cout;
	}

}