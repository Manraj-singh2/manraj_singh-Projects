// Final Project Milestone 3
// Date Module
// File	Date.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Manraj Singh               Date:019/07/2024                 Reason
// 
/////////////////////////////////////////////////////////////////

#ifndef SENECA_STREAMABLE_H__
#define SENECA_STREAMABLE_H__
#include <iostream>


namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;

		virtual bool conIO(std::ios&)const = 0;
		virtual operator bool()const = 0;

		virtual ~Streamable();
	};

	std::ostream& operator << (std::ostream&, const Streamable&);
	std::istream& operator >> (std::istream&, Streamable&);

}//seneca


#endif