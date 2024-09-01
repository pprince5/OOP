/***********************************************************************
// Final project Milestone 4
// Module: Perishable Test
// File: Utils.h
// Version 1.1
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
// Prince              28-11-4
***********************************************************************/
// ID: 145685228
// mail: pprince5@seneca.ca
// Section:: ZDD
#ifndef _SDDS_UTILS_H
#define _SDDS_UTILIS_H
#include <iostream>
#include <cstring>
namespace sdds {
    //
    const int sdds_testYear = 2023;
    const int sdds_testMon = 12;
    const int sdds_testDay = 9;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*& destination, const char* source);
        //
        //
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);

    };
    extern Utils ut;
}
#endif

