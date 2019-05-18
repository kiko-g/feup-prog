#pragma once

#include "classes/Agency.h"
#include "defs.h"

#ifdef _WIN64
#define clearScreenTemp() system("clear");
#elif _WIN32
#define clearScreenTemp() system("clear");
#else
#define clearScreenTemp() system("cls");
#endif

unsigned mainMenu(Agency agency);
void browsingInterface(Agency agency);
void browseClientsInterface(Agency agency);
void browsePacksInterface(Agency agency);

int validateInterfaceInput(int a, int b);
