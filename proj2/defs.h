#pragma once

#ifdef _WIN32
#define clearScreen() system("cls");
#else
#define clearScreen() system("clear");
#endif

#include <string>

const std::string AGENCY_FILE_NAME="agency.txt";

