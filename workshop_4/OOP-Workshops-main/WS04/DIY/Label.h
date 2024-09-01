#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
namespace sdds {

	class Label {
		char frame[9]{};
		char* m_content;
		//
	public:
		//
		//constructors
		//
		Label();
		//
		Label(const char* frameArg);
		//
		Label(const char* frameArg, const char* content);
		//
		//
		// destructor
		//
		~Label();
		//
		//
		//other fucntions
		//
		std::istream& readLabel();
		//
		std::ostream& printLabel()const;
		//
		Label& text(const char* content);
	};
}

#endif
#pragma once
