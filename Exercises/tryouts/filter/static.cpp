#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int nletstr_count(string str, char letter)
{
    static int ct = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == letter) ct++;
    }
    return ct;
}

int main()
{
    
}
