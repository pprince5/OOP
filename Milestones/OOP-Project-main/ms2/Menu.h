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
#ifndef MENU_H
#define MENU_H

namespace sdds {

    class Menu {
    private:
        char* menuContent;
        unsigned int numOptions;

    public:
        // constructor
        Menu(const char* content);
        //destructor
        ~Menu();
        //
        //
        Menu(const Menu& other) = delete;
        Menu& operator=(const Menu& other) = delete;
        //
        //
        unsigned int run();
    };
}

#endif // MENU_H