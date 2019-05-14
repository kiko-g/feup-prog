#include <iostream>
#include <iomanip>
using namespace std;

std::cout << "|" << std::setw(10) << centered("Table")
          << "|" << std::setw(10) << centered("Column")
          << "|" << std::setw(9) << centered("Header") << "|"
          << std::endl;