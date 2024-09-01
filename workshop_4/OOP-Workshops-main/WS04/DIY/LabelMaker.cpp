#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
#include <cstring>

using namespace sdds;

LabelMaker::LabelMaker(int noOfLabels) {
	m_noOfLabels = noOfLabels;
	labels = new Label[m_noOfLabels];
}
//
void LabelMaker::readLabels() const {
	std::cout << "Enter " << m_noOfLabels << " labels:" << std::endl;
	for (int i = 0; i < m_noOfLabels; i++) {
		std::cout << "Enter label number " << i + 1 << std::endl;
		labels[i].readLabel();
	}
}
//
void LabelMaker::printLabels() const {
	for (int i = 0; i < m_noOfLabels; i++) {
		labels[i].printLabel();
		std::cout << std::endl;
	}
}
//
LabelMaker::~LabelMaker() {
	delete[] labels;
}