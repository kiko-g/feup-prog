#pragma once
#include "classes/Agency.h"
#include "defs.h"

#ifdef _WIN32   //_WIN32 is defined for applications for Win32 and Win64.
#define clearScreen() system("cls");    
#else
#define clearScreen() system("clear");
#endif

#ifdef _WIN32   //_WIN32 is defined for applications for Win32 and Win64.
#define backToMenu() system("pause");   
#else
#define backToMenu system("read");      
#endif

void mainMenu(Agency &agency);
void clientsInterface(Agency &agency);
void packsInterface(Agency &agency);
void editClients(Agency &agency);
void editPacks(Agency &agency);

void browsingInterface(Agency agency);
void browseClientsInterface(Agency agency);
void browsePacksInterface(Agency agency);