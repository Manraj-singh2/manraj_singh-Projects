#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#define MAX_MENU_ITEMS 20
namespace sdds {


	class MenuItem {

		char* m_item;
		friend class Menu;

		MenuItem();
		MenuItem(const char* value);

		MenuItem(const MenuItem&) = delete;
		void operator=(const MenuItem&) = delete;

		~MenuItem();

		operator bool() const;
		operator const char* () const;

		std::ostream& display(std::ostream& out = std::cout);

	};

	class Menu {
		
		MenuItem m_title{};
		MenuItem* m_items[MAX_MENU_ITEMS]{};
		int m_counter = 0;

	public:

		Menu(const Menu&) = delete;
		void operator=(Menu&) = delete;

		Menu();
		Menu(const char* title);
		~Menu();

		std::ostream& displayTitle(std::ostream& out = std::cout);
		std::ostream& displayMenu(std::ostream& out = std:: cout);

		int run();

		int operator~();

		Menu& operator<<(const char* menuitemConent);

		operator int();
		operator unsigned int();
		operator bool();

		const char* operator[](int index) const;
	};

	std::ostream& operator<<(std::ostream& cout, Menu& menu);

	int getInput(int min, int max, const char* prompt);

	


}
#endif