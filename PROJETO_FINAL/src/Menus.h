#pragma once
#include "classes/Agency.h"
#include "defs.h"

#ifdef _WIN64
#define clearScreen() system("cls");
#elif _WIN32
#define clearScreen() system("cls");
#else
#define clearScreen() system("clear");
#endif

void mainMenu(Agency agency);
void browsingInterface(Agency agency);
void clientsInterface(Agency &agency);

void browseClientsInterface(Agency agency);
void browsePacksInterface(Agency agency);