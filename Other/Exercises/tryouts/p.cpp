#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
#include "p.h"
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

int stoint(const string &str, int &value)
{
    int base = 10;
    size_t* pos = 0;
    // wrapping stoi because it may throw an exception

    try
    {
        value = stoi(str, pos, base);
        return 0;
    }

    catch (const invalid_argument& ia)
    {
        //cerr << "Invalid argument: " << ia.what() << endl;
        return -1;
    }

    catch (const out_of_range& oor)
    {
        //cerr << "Out of Range error: " << oor.what() << endl;
        return -2;
    }

    catch (const exception& e)
    {
        //cerr << "Undefined error: " << e.what() << endl;
        return -3;
    }
}

void fill_vec_rand(vector<int> &v, int n)
{
    srand((unsigned)time(NULL));
    int i = 0;
    int b;
    while (i < 6)
    {
        b = rand() % n;
        v.push_back(b);
        i++;
    }
}

void invert_vect(vector<int> &v)
{
    int j = 0, max;
    size_t size = v.size();
    max = size / 2;
    while (j < max)
    {
        int hold;
        hold = v.at(j);
        v.at(j) = v.at(size - j - 1);
        v.at(size - j - 1) = hold;
        j++;
    }
}

void print_vect( vector<int> v )
{
    cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << "  ";
    }
    cout << "\b]\n";
}

void setcolor(int color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    //#include <windows.h>
    return;
}

void start(int color)
{
    setcolor(color);
    cout << "==================================="
         << "==================================="
         << "====================================\n";
    setcolor(7);
    return;
}

void end(int color)
{
    setcolor(color);
    cout << "\n=================================="
         << "===================================="
         << "====================================";
    setcolor(7);
    return;
}
