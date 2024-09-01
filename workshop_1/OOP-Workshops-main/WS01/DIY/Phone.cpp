///***********************************************************************
//// OOP244 Workshop #1
//WORKSHOP -1
//NAME: Prince
//SENECA EMAIL: pprince5@myseneca.ca
//STUDENT ID: 145685228
//DATE: September 18,2023
//
//I hereby decalre that i have done the code independently and only copied code that
//was provided by the professor to help with workshops and assignments.
//
//***********************************************************************/
//
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include "Phone.h"
//#include <stdio.h>
//
//using namespace std;
//
//namespace sdds
//{
//	int exit = 0;
//	void phoneDir(const char* programTitle, const char* fileName)
//	{
//		cout << programTitle << " phone direcotry search" << endl;
//		cout << "-------------------------------------------------------" << endl;
//		FILE* file = fopen(fileName, "r"); //store the address of the provided file. 
//		//check if address is null
//		if (file == nullptr)
//		{
//			cout << fileName << " file not found!" << endl;
//			cout << "Thank you for using " << programTitle << " directory." << endl;
//
//		}
//		else
//		{
//			while (exit == 0 ) //exits the loop when exit is true( that is 1).
//			{
//				char partial_Name[51] = { 0 };
//				char searched_name[51] = { 0 };
//				char name[51] = { 0 };
//				char lowerC_Name[51] = { 0 };
//				char number[10] = { 0 };
//				char A_Code[5] = { 0 };
//				char prefix_Code[5] = { 0 };
//				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
//				cout << "> ";
//				cin >> partial_Name;
//				if (strCmp(partial_Name, "!") == 0) //compare entered string with "!"
//				{
//
//					exit = 1;
//				}
//				if (exit != 1) {
//					while (fscanf(file, "%[^\t]\t%s\t%s\t%s\n", name, A_Code, prefix_Code, number) != EOF) //checking if there is data in the file to be read
//					{
//						toLowerCaseAndCopy(lowerC_Name, name); //copies the lower Case name to first variable in the argument.
//						toLowerCaseAndCopy(searched_name, partial_Name); //copies the lower Case partialName to first variable in the argument.
//						if (strStr(lowerC_Name, searched_name)) // return the address of the searchName.
//						{
//							cout << name << ": (" << A_Code << ") " << prefix_Code << "-" << number << endl;
//
//						}
//					}
//				}
//				fclose(file); //closing the file. 
//				file = fopen(fileName, "r"); //reads from the beginning
//			}
//			fclose(file);
//			cout << "Thank you for using " << programTitle << " directory." << endl;
//		}
//	}
//
//
//
//}
//
//

int main() {
	int a = 5;
	int* b = &a;


	printf(" % d, % d", a, b);

	return 0;

}