/***********************************************************************
// OOP244 Workshop # 10
// Version 1.0
// Date: 2023/11/25
// Author: Fardad Soleimanloo
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name Prince        Date 1/12/2023        Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Student ID: 145685228
// Mail: pprince5@myseneca.ca
// section: zdd
#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
   class Displayable {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
   };
   std::ostream& operator<<(std::ostream& os, const Displayable& c);
}
#endif // !SDDS_READWRITE_H_

