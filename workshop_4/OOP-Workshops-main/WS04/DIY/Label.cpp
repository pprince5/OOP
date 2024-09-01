#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Label.h"
#include <iostream>
#include <iomanip>

using namespace sdds;

Label::Label() {
	strcpy(frame, "+-+|+-+|");
	m_content = nullptr;
}
//
Label::Label(const char* frameArg) {
	if (frameArg == nullptr) {
		strcpy(frame, "+-+|+-+|");
	}
	else {
		strcpy(frame, frameArg);
		m_content = nullptr;
	}
}
//
Label::Label(const char* frameArg, const char* content) {
	if (frameArg == nullptr) {
		strcpy(frame, "+-+|+-+|");
	}
	else {
		strcpy(frame, frameArg);
		m_content = new char[strlen(content) + 1];
		text(content);
	}
}
//
Label::~Label() {
	delete[] m_content;
}
//
std::istream& Label::readLabel() {
	char content[71];

	std::cout << "> ";
	std::cin.clear();
	std::cin.getline(content, 71, '\n');
	text(content);

	return std::cin;
}
//
std::ostream& Label::printLabel() const {
	if (m_content) {
		const int labelSize = strlen(m_content) + 3;

		std::cout << frame[0] 
			<< std::setfill(frame[1])
			<< std::setw(labelSize) 
			<< frame[2] << std::endl
			//
			<< frame[7] << std::setfill(' ') 
			<< std::setw(labelSize)
			<< frame[3] << std::endl
			//
			<< frame[7] << " " 
			<< m_content << " " 
			<< frame[3] << std::endl
			//
			<< frame[7] 
			<< std::setfill(' ')
			<< std::setw(labelSize) 
			<< frame[3] << std::endl
			//
			<< frame[6] 
			<< std::setfill(frame[5])
			<< std::setw(labelSize) 
			<< frame[4];
	}

	return std::cout;
}
//
Label& Label::text(const char* content) {

	delete[] m_content;

	m_content = new char[strlen(content) + 1];
	strcpy(m_content, content);
	return *this;
}