/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Prince            Date 15-10-2023           Reason
***********************************************************************/
//Student Id: 145685228
// Mail: pprince5@myseneca.ca
// Section: ZDD
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

    //Already implemented functions
    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) 
    {
        emptyPortfolio();

        if ((type == 'V' || type == 'G' || type == 'I') &&  value >= 0 )
        {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) 
        {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) 
        {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else
        {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    //
    Portfolio::operator double() const
    {
        return this->m_value;
    }
    //
    Portfolio::operator const char* () const
    {
        return this->m_stock;
    }
    //
    Portfolio::operator char() const
    {
        return this->m_type;
    }
    //
    Portfolio::operator bool() const
    {
        if (m_type == 'G' || m_type == 'V' || m_type == 'I') 
        {
            return true;
        }
        return false;
    }
    //
    Portfolio& Portfolio::operator+=(double floatValue)
    {
        if ((m_type == 'G' || m_type == 'V' || m_type == 'I') &&  (floatValue > 0))
        {
            m_value += floatValue;
        }

        return *this;
    }
    //
    Portfolio& Portfolio::operator-=(double floatValue)
    {

        if ((m_type == 'G' || m_type == 'V' || m_type == 'I') && (floatValue > 0))
        {
            m_value -= floatValue;
        }

        return *this;
    }
    //
    bool Portfolio::operator~() const
    {
        if (m_value < 0)
        {
            return true;
        }
        return false;

    }
    //
    Portfolio& Portfolio::operator <<(Portfolio& source)
    {
        if (this != &source && this->validPortfolio() && source.validPortfolio())
        {
            m_value += source.m_value;
            source.m_value = 0;
            source.m_stock[0] = 0;
            source.m_type = 'E';
        }
        return *this;
    }
    //
    Portfolio& Portfolio::operator >>(Portfolio& source)
    {
        if (this != &source && this && source)
        {
            source.m_value += m_value;
            m_value = 0;
            m_stock[0] = 0;
            m_type = 'E';
        }
        return *this;
    }
    //
    double Portfolio::getM_value() const
    {
        return this->m_value;

    }
    //
    double operator+(const Portfolio& obj1, const Portfolio& obj2)
    {
        double Sum;
        Sum = obj1.getM_value() + obj2.getM_value();
        return Sum;
    }
    //
    double operator +=(double& value, const Portfolio& source)
    {
        value += source.getM_value();
        return value;
    }
    //
    bool Portfolio::validPortfolio() const
    {
        bool Valid = false;
        if ( (m_type == 'G' || m_type == 'V' || m_type == 'I') && (m_value >= 0))
        {
            Valid = true;
        }
        return Valid;
    }
}