#pragma once
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H

namespace sdds {
	//
	class LabelMaker {
		Label* labels;
		int  m_noOfLabels;
		//
	public:
		//constructor
		LabelMaker(int noOfLabels);
		//destructor
		~LabelMaker();
		//other
		void readLabels() const;
		void printLabels() const;
		
	};
}

#endif
