/***********************************************************************
// Final project Milestone 1
// Module: Utils
// File: Utils.h
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Prince           Date 02-Nov-2023           Reason
***********************************************************************/
// ID: 145685228
// Mail: pprince5@myseneca.ca
// Section: ZDD
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

