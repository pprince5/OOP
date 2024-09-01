/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare overloaded read function prototypes
   bool read(FILE* file_pointer, char*& name) {
       char buffer[128];
       if (fscanf(file_pointer, "%127[^\n]\n", buffer) == 1) {
           // Allocate dynamic memory for the name and copy it
           name = strdup(buffer);
           return true;
       }
       return false;
   }

}

#endif // !SDDS_FILE_H_