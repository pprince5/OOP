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
#ifndef SDDS_SELECTION_H_
#define SDDS_SELECTION_H_
#include "Displayable.h"
namespace sdds
{
	template< typename arraytype, typename keytype>
	int* select(arraytype array[], keytype keyvalue, size_t size) 
	{
		int count=0;
		for (size_t i = 0; i < size; i++) 
		{
			if (array[i] == keyvalue) 
			{
				count++;
			}
		}

		int* indices = new int[count + 1];
		int current_index = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == keyvalue)
			{
				indices[current_index] = static_cast<int>(i);
				current_index++;
			}
		}
		indices[current_index] = -1;
		return indices;
	}

	template<typename arraytype>
	void csvDisplaySelection(const char* title, arraytype array[],const int* indices)
	{
		std::cout <<title<<"\n";
		if (indices == nullptr || indices[0] == -1)
		{
			std::cout << "Empty Selection" << std::endl;
		}
		else 
		{
			for (int i = 0; indices[i] != -1; ++i) {
				std::cout << array[indices[i]];
				if (indices[i + 1] != -1) {
					std::cout << ", ";
				}
			}
			std::cout << std::endl;

		}
	}

}; 
#endif

