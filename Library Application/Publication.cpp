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
#include "Publication.h"
#include <iomanip>
#include <cstring>

namespace sdds {

	Publication::Publication() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;

		m_date = Date();
	}

	Publication::~Publication() {
		delete[] m_title;
	}

	void Publication::set(int member_id)
	{
		if (member_id < 9999 || member_id > 99999)
		{
			m_membership = 0;
		}
		else
		{
			m_membership = member_id;
		}
	}

	void Publication::setRef(int value)
	{
		if (value > -1)
		{
			m_libRef = value;
		}
		else
		{
			m_libRef = -1;
		}
	}

	void Publication::resetDate() {

		m_date = Date();

	}

	char Publication::type()const {
		return 'P';
	}

	bool Publication::onLoan()const {
		if (m_membership != 0) {
			return true;
		}

		return false;
	}

	Date Publication::checkoutDate()const {

		return m_date;

	}

	bool Publication::operator==(const char* title)const {

		return strstr(m_title, title) != nullptr;

	}

	Publication::operator const char* ()const {
		return m_title;
	}

	int Publication::getRef()const {
		return m_libRef;
	}

	bool Publication::conIO(std::ios& io)const {
		return &io == &std::cout || &io == &std::cin;
	}

	std::ostream& Publication::write(std::ostream& os) const
	{
		char oldFill = os.fill();
		if (conIO(os))
		{
			os.setf(std::ios::left);
			os.fill('.');
			os << "| ";
			os.width(SELF_ID_LENGTH);
			os << m_shelfId;

			os << " | ";

			if (strlen(m_title) > SELF_TITLE_WIDTH) {
				os << std::string(m_title, m_title + SELF_TITLE_WIDTH);
			}
			else {
				os.width(SELF_TITLE_WIDTH);
				os << m_title;
			}
			os << " | ";

			if (m_membership != 0)
				os << m_membership;
			else
				os << " N/A ";

			os << " | ";

			if (!m_date.errCode())
				os << m_date;
			else
				os << " N/A ";

			os << " |";

			os.fill(oldFill);
			os.unsetf(std::ios::left);

			return os;
		}
		else
		{
			os << type() << "\t";
			os << m_libRef;
			os << "\t";
			os << m_shelfId;
			os << "\t";
			os << m_title;
			os << "\t";
			os << m_membership;
			os << "\t";
			os << m_date;

			return os;
		}
	}
	std::istream& Publication::read(std::istream& istr) {

		char tmp_title[256]{};
		char tmp_shelfId[SELF_ID_LENGTH + 1]{};
		unsigned int tmp_membership{};
		int tmp_libRef{};
		Date tmp_date{};
		Publication();
		if (conIO(istr))
		{
			std::cout << "Shelf No: ";
			istr.getline(tmp_shelfId, SELF_ID_LENGTH + 1);
			if (strlen(tmp_shelfId) != SELF_ID_LENGTH)
				istr.setstate(std::ios_base::failbit);
			std::cout << "Title: ";
			istr.getline(tmp_title, 256);
			std::cout << "Date: ";
			istr >> tmp_date;
		}
		else
		{
			istr >> tmp_libRef;
			istr.ignore();
			istr.getline(tmp_shelfId, SELF_ID_LENGTH + 1, '\t');
			istr.getline(tmp_title, 256, '\t');
			istr >> tmp_membership;
			istr.ignore();
			istr >> tmp_date;
		}
		if (!tmp_date)
			istr.setstate(std::ios_base::failbit);
		if (!istr.fail())
		{
			m_title = new char[strlen(tmp_title) + 1];
			strcpy(m_title, tmp_title);
			strcpy(m_shelfId, tmp_shelfId);
			m_membership = tmp_membership;
			m_date = tmp_date;
			m_libRef = tmp_libRef;
		}
		return istr;
	}
	

	Publication::operator bool() const {

		if (m_title != nullptr && m_shelfId[0] != '\0') {
			return true;
		}

		return false;

	}



	Publication::Publication(const Publication& Scr)
	{
		if (this != &Scr)
		{
			if (m_title)
			{
				delete[] m_title;
				m_title = nullptr;
			}
			m_title = new char[strlen(Scr.m_title) + 1];
			strcpy(m_title, Scr.m_title);
			strcpy(m_shelfId, Scr.m_shelfId);
			m_membership = Scr.m_membership;
			m_libRef = Scr.m_libRef;
			m_date = Scr.m_date;
		}
	}

	Publication& Publication::operator = (const Publication& other) {

		if (this != &other) {

			m_libRef = other.m_libRef;
			m_membership = other.m_membership;
			m_date = other.m_date;
			m_shelfId[SELF_ID_LENGTH] = '\0';
			strncpy(m_shelfId, other.m_shelfId, SELF_ID_LENGTH);

			delete[] m_title;

			if (other.m_title != nullptr) {

				m_title = new char[strlen(other.m_title) + 1];
				strcpy(m_title, other.m_title);
			}
			else {
				m_title = nullptr;
			}
		}

		return *this;
	}

}