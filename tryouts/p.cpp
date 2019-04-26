#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <windows.h>
#include "p.h"
using namespace std;

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
