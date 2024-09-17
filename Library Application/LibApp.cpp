/*Name: Manraj Singh
Email : manraj-singh2@myseneca.ca
Student ID : 119504231
Section : ZFF
Date : 17 July 2034
---------------------------------------------------------- -
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -*/
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "LibApp.h"
namespace sdds {
   
	bool LibApp::confirm(const char* message) {

		Menu menu(message);

		menu << "Yes";

		if (menu.run())
		{
			return true;
		}

		return false;
	}

	void LibApp::load() {
		std::cout << "Loading Data" << std::endl;
	}

	void LibApp::save() {
		std::cout << "Saving Data" << std::endl;
	}

	void LibApp::search() {
		std::cout << "Searching for publication" << std::endl;
	}

	void LibApp::returnPub() {
		search();

		std::cout << "Returning publication" << std::endl;
		std::cout << "Publication returned" << std::endl << std::endl;

		m_changed = true;
		
	}

	void LibApp::newPublication() {

		std::cout << "Adding new publication to library" << std::endl;
		
		if (confirm("Add this publication to library?")) {

			m_changed = true;
			std::cout << "Publication added" << std::endl;
		}
		std::cout << std::endl;
	}

	void LibApp::removePublication() {
		std::cout << "Removing publication from library" << std::endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			std::cout << "Publication removed" << std::endl << std::endl;
		}
	}

	void LibApp::checkOutPub() {

		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			std::cout << "Publication checked out" << std::endl <<std::endl;
		}
	}

	LibApp::LibApp():m_mainMenu("Seneca Library Application"),m_exitMenu("Changes have been made to the data, what would you like to do?") {

		m_changed = false;
		m_mainMenu << "Add New Publication";
		m_mainMenu << "Remove Publication";
		m_mainMenu << "Checkout publication from library";
		m_mainMenu << "Return publication to library";

		m_exitMenu << "Save changes and exit";
		m_exitMenu << "Cancel and go back to the main menu";

		load();


	}

	void LibApp::run() {

		bool exit = false;
		int selection;
		
		do{
			selection = m_mainMenu.run();
			
			if (selection == 1)
			{
				newPublication();
			}
			else if (selection == 2)
			{
				removePublication();
			}
			else if (selection == 3) {
				checkOutPub();
			}
			else if (selection == 4) {
				returnPub();				
			}

		} while (selection != 0);

		if (m_changed) {

			int select = m_exitMenu.run();

			if (select == 1) {
				save();
				exit = true;
			}
			else if (select == 2) {
				std::cout << std::endl;
				run();
			}
			else if (select == 0)
			{
				if (confirm("This will discard all the changes are you sure?")) {
					exit = true;
				}
				else
				{
					run();
				}
			}
		}
		else {
			exit = true;
		}

		if (exit) {
			std::cout << std::endl << "-------------------------------------------" << std::endl;
			std::cout << "Thanks for using Seneca Library Application" << std::endl;
		}
		

	}

}//Seneca
