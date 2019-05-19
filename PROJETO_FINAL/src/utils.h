#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "defs.h"
#include "classes/Address.h"

using namespace std;

int validateInterfaceInput(int a, int b);
int stoint(const string &str, int &value);
int numberOf(const string filename);
vector<string> strtok_cpp(string h, string n);
Address string_to_address(string address_str);
void readline(string &str);
bool cin_test();
