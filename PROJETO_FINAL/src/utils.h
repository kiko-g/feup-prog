#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "defs.h"

#include "classes/Address.h"

using namespace std;

int stoint(const string &str, int &value);

int numberOf(const string filename);

vector<string> strtok_cpp(string h, string n);

Address string_to_address(string address_str);


