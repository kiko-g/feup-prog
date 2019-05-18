#include <iostream>
#include <string>
#include <vector>

#include "classes/Agency.h"
#include "Menus.h"
// #include "utils.h"


int main()
{
  Agency agency(AGENCY_FILE_NAME);   // create the agency
  cout << "\n\n\n";
  agency.savePacksInfo("packsnew.txt");
  agency.saveClientsInfo("clientsnew.txt");
  //mainMenu(agency); // initial menu inicial with the major options of the application
  return 0;
}

