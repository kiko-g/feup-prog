#include <iostream>
#include <string>
#include <vector>

#include "classes/Agency.h"
#include "Menus.h"
// #include "utils.h"


int main()
{
    Agency agency(AGENCY_FILE_NAME);   // create the agency
    vector<Client> c_list = agency.getClients();
    for(int i=0; i<c_list.size(); i++)
    c_list.at(i).setTotalPurchased(agency.determineMoneySpentByClient(c_list.at(i).getPackList()));
    //agency.mostVisited(10);
    mainMenu(agency); // initial menu inicial with the major options of the application
  return 0;
}

