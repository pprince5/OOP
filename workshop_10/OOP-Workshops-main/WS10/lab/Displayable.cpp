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
#include "Displayable.h"
using namespace std;
namespace sdds {
   ostream& operator<<(ostream& os, const Displayable& c) {
      return c.display(os);
   }
}