// Final Project Milestone 3
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Manraj Singh              Date:01/07/2024                Reason
// 
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Streamable.h"

namespace sdds {

	std::ostream& operator << (std::ostream& os, const Streamable& st) {

		if (st) {
			st.write(os);
		}

		return os;
	}

	Streamable::~Streamable() {

	}

	std::istream& operator >> (std::istream& is, Streamable& st) {

		st.read(is);

		return is;

	}

}
