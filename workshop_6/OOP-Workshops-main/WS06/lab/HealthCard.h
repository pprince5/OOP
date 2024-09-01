// Workshop #6:
// Version: 1.0
// File name: main.cpp
// Date: 2021/12/02
// Author: Wail Mardini
// Description:
// This file tests the lab section of your workshop
///////////////////////////////////////////////////
// Name: Prince Prince
// ID: 145685228
// Section: zdd
// Mail: pprince5@myseneca.ca

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H
#include <iostream>

namespace sdds {
    const int MaxNameLength =55;
    class HealthCard {
        char* m_name{};
        long long m_number;
        char m_vCode[3];
        char m_sNumber[10];
        //
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[])const;
        //
        void setEmpty();
        //
        void allocateAndCopy(const char* name);
        //
        void extractChar(std::istream& istr, char ch);
        //
        std::ostream& printIDInfo(std::ostream& ostr)const;
        //
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);

    public:
        //Constructor
        //
        HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});
        //Copy Constructor 
        //
        HealthCard(const HealthCard& hc);
        //
        //Destructor
        ~HealthCard();
        //
        //Overloading
        HealthCard& operator=(const HealthCard& hc);
        //  
        //
        operator bool() const;
        //
        //other
        std::ostream& print(std::ostream& ostr, bool toFile = true)const;
        //
        std::istream& read(std::istream& istr);
    };
    //helper
    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
    //
    std::istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H
