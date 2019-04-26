#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <windows.h>
//#include <cmath>
//#include <algorithm>
//#undef max
using namespace std;

vector<string> strtok_cpp(string h, string n)
{
    // h is haystack, n is needle
    vector<string> ret;
    size_t startPos = 0, endPos = 0;
    while (endPos<h.length())
    {
        endPos=h.find(n,startPos);
        if(endPos==h.npos)
        {
            ret.push_back(h.substr(startPos));
            break;
        } 
        else ret.push_back(h.substr(startPos,endPos-startPos));
        startPos=endPos + n.length();
    }
    return ret;
}


int main()
{
    string a ("FC Porto 3-3 Liverpool");
    string b ("o");
    cout << strtok_cpp(a, b).at(0) << endl;
    cout << strtok_cpp(a, b).at(1) << endl;
    cout << strtok_cpp(a, b).at(2) << endl;
    cout << strtok_cpp(a, b).at(3) << endl << endl;
}
