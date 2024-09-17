// Final Project Milestone 3
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name: Manraj Singh              Date:19/07/2024                Reason
// 
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Book.h"
#include "Streamable.h"
#include "Lib.h"

using namespace std;
namespace sdds {

	
	Book::Book() {

		m_author = nullptr;
	}

	
	Book::Book(const Book& Book) {

		
		if (Book.m_author != nullptr) {

			m_author = new char[strlen(Book.m_author) + 1];
			strcpy(m_author, Book.m_author);
		}
		else {
			m_author = nullptr;
		}
	}

	// The copy assignment
	Book& Book::operator = (const Book& Book) {

		Publication::operator = (Book);

		if (this != &Book) {

			// Delete the existing author Name and make a deep copy of the new one
			delete[] m_author;

			if (Book.m_author != nullptr) {

				m_author = new char[strlen(Book.m_author) + 1];
				strcpy(m_author, Book.m_author);
			}
			else {

				m_author = nullptr;
			}
		}

		return *this;
	}

	
	Book::~Book() {

		delete[] m_author;
	}

	char Book::type() const {

		return 'B';
	}

	ostream& Book::write(ostream& os) const {

		
		Publication::write(os);
		if (Publication::conIO(os)) {
			os << ' ';

			if (strlen(m_author) > SENECA_AUTHOR_WIDTH) {
				for (int i = 0; i < SENECA_AUTHOR_WIDTH; i++) {
					os.fill(' ');
					os << m_author[i];
				}
			}
			else {
				os << setw(SENECA_AUTHOR_WIDTH) << left << m_author << right;
			}
			os << " |";
		}
		else {
			os << '\t' << m_author;
		}
		return os;
	}

	istream& Book::read(istream& istr) {

		
		char tempName[256] = { '\0' };
		
		Publication::read(istr);
		
		delete[] m_author;

		if (conIO(istr) == true) {

			istr.ignore();
			cout << "Author: ";
			istr.getline(tempName, 255);
		}
		else {

			istr.ignore(); 
			istr.get(tempName, 256, '\n');
		}

		
		if (istr) {

			m_author = new char[strlen(tempName) + 1]; 
			strcpy(m_author, tempName); 
			m_author[strlen(tempName)] = '\0'; 
		}
		else {
			m_author = nullptr;
		}
		return istr;
	}

	void Book::set(int member_id) {

		Publication::set(member_id); 
		Publication::resetDate(); 
	}

	Book::operator bool() const {

		bool temp;
		
		if (m_author != nullptr && Publication::operator bool() == true) {

			temp = true;
		}
		else {

			temp = false;
		}
		return temp;
	}

}
