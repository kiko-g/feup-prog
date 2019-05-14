#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "p.h"
using namespace std;


int main()
{
    start(2);
    string s ("F  C   P  O  R  T  O");
    while(s.find("  ")!= string::npos)
    s.erase(s.find("  "), 2);
    cout << s;
    end(2);
}