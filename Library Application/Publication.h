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

#ifndef SENECA_PUBLICATION_H__
#define SENECA_PUBLICATION_H__
#include <iostream>
#include "Streamable.h"
#include "Date.h"

#define SELF_ID_LENGTH 4
#define SELF_TITLE_WIDTH 30

namespace sdds {

	class Publication:public Streamable {
		char* m_title;
		char m_shelfId[SELF_ID_LENGTH + 1];
		int m_membership;
		int m_libRef;

		Date m_date;

	public:
		Publication();
		~Publication();
		

		Publication(const Publication&);
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();


		virtual char type()const;
		bool onLoan()const;
		Date checkoutDate()const;
		bool operator==(const char* title)const;
		Publication& operator = (const Publication&);
		operator const char* ()const;
		int getRef()const;

		bool conIO(std::ios& io)const;
		
		std::ostream& write(std::ostream& os) const;

		std::istream& read(std::istream& is);

		operator bool() const;


	};


}


#endif