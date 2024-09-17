#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstring>
#include <limits>

using namespace std;
#include "Menu.h"
namespace sdds {

	MenuItem::MenuItem() {
		m_item = nullptr;
	}

	MenuItem::MenuItem(const char* value) {
		if (value != nullptr) {

			m_item = new char[strlen(value) + 1];
			strcpy(m_item, value);
		}
		else
		{
			m_item = nullptr;
		}
		
	}

	MenuItem::~MenuItem()
	{
		if (m_item != nullptr)
		{
			delete[] m_item;
			m_item = nullptr;
		}
	}

	MenuItem::operator bool() const {

		if (m_item != nullptr)
		{
			return true;
		}
		return false;
	}

	MenuItem::operator const char* () const {

		return m_item;

	}

	ostream& MenuItem::display(std::ostream& out) {

		if (m_item != nullptr)
		{
			out << m_item;
		}

		return out;
	}

	Menu::Menu() {
		m_counter = 0;
	}

	Menu::Menu(const char* title) : m_title(title) {};

	Menu::~Menu() {
		int i = 0;
		for (i = 0; i < MAX_MENU_ITEMS; i++)
		{
			delete m_items[i];
			m_items[i] = nullptr;
		}
	}

	ostream& Menu::displayTitle(std::ostream& out) {

		if (m_title != nullptr) {
			m_title.display(out);
		}
		return out;
	}
	ostream& Menu::displayMenu(std::ostream& out) {

		if (m_title != nullptr) {

			displayTitle(out); 
			std::cout << std::endl;

		}

		 int i;
		for (i = 0; i < m_counter; i++)
		{
			out.width(2);
			out.setf(ios::right);
			out.fill(' ');
			out << i + 1 << "- ";
			out.unsetf(ios::right);
			m_items[i]->display(out);
			out << std::endl;
		}
		out << " 0- Exit" << std::endl;
		out << "> ";

		return out;
	}

	int getInput(int min, int max, const char* prompt) {
		int userInput;
		bool success = false;
		while (success == false)
		{
			cin >> userInput;
			if (!cin || userInput < min || userInput > max)
			{
				std::cout << prompt;
				cin.clear();
				cin.ignore(1000, '\n');
				success = false;
			}
			else
			{
				success = true;
			}

		}
		return userInput;
	}


	int Menu::run() {

		
		displayMenu(std::cout);
		int selection;
		std::cin >> selection;
		while (std::cin.fail() || selection < 0 || selection > m_counter) {
			std::cin.clear();
			std::cin.ignore(80, '\n');
			std::cout << "Invalid Selection, try again: ";
			std::cin >> selection;
		}
		return selection;
	}

	int Menu::operator~(){
		return run();
	}

	Menu& Menu::operator<<(const char* menuitemConent) {
		
		if (m_counter < MAX_MENU_ITEMS)
		{
			m_items[m_counter] = new MenuItem(menuitemConent);
			m_counter++;
		}

		
		return*this;
	}

	Menu::operator int()
	{
		return m_counter;
	}

	Menu::operator unsigned int()
	{
		return m_counter;
	}

	Menu::operator bool() {

		if (m_counter)
		{
			return true;
		}

		return false;

	}

	std::ostream& operator<<(std::ostream& cout, Menu& menu)
	{
		return menu.displayTitle(cout);
	}

	const char* Menu::operator[]( int index) const
	{
		if (index > m_counter)
		{
			return m_items[index %= m_counter]->m_item;
		}
		else
		{
			return m_items[index]->m_item;
		}
	}

}