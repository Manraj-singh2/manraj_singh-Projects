#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H
#include "Menu.h"
namespace sdds {
   class LibApp {

       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       //Methods
       bool confirm(const char* message);
       void load();  // prints: "Loading Data"<NEWLINE>
       void save();  // prints: "Saving Data"<NEWLINE>
       void search();  // prints: "Searching for publication"<NEWLINE>

       void returnPub();  /*  Calls the search() method.
                              prints "Returning publication"<NEWLINE>
                              prints "Publication returned"<NEWLINE>
                              sets m_changed to true;
                          */

       void newPublication();
       void removePublication();
       void checkOutPub();

   public:

       LibApp();
       void run();
   };
}
#endif // !SENECA_LIBAPP_H



