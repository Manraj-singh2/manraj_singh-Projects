// Final Project Milestone 4
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Manraj Singh               Date:30/07/2024                 Reason
// 
/////////////////////////////////////////////////////////////////

#ifndef SENECA_BOOK_H__
#define SENECA_BOOK_H__
#include <iostream>
#include "Publication.h"

namespace sdds {

	class Book: public Publication {

		char* m_author;
	
	public:

		Book();
		virtual ~Book();

		Book(const Book&);
		Book& operator=(const Book&);

		virtual char type()const;
		virtual std::ostream& write(std::ostream&)const;
		virtual std::istream& read(std::istream& istr);
		virtual void set(int);
		virtual operator bool() const;
	};
}


#endif