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
#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"
namespace sdds {
	class AidMan {
		//
		char* filename;
		Menu mainMenu;
		//
		//
	public:
		//constructor
		AidMan(const char* fileName);
		//destructor
		~AidMan();
		//
		//
		AidMan(const AidMan&) = delete;
		AidMan& operator=(const AidMan) = delete;
		//
		//
		void run();

	private:
		unsigned int menu();
	};
}

#endif