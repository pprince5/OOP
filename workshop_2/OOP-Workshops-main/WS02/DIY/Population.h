/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
//  Full Name : Prince Prince
//	Email : pprince5@myseneca.ca
//  Student ID# : 145685228
//	Section : OOP244 ZBB
//	Authenticity Declaration :
//I hereby decalre that i have done the code independently and only copied code that
//was provided by the professor to help with workshops and assignments.
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
   struct Population {
       char* postalCode;
       int population;
   };

   // returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);

   void sort();
   //
   int T_populationPopulation();
   //
   bool getPostalCode(char* postal_code_prefix);
   //
   bool load(Population& record);
   //
   bool load(const char* filename);
   //
   bool load(const char* filename, const char* partial_postal_code_prefix);
   //

   void display(const int count, const Population& record);
   //
   void display();
   //
   void deallocateMemory();
}
#endif // SDDS_POPULATION_H_