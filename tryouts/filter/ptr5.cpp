#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "p.h"
#define NMAX 3
using namespace std;
typedef unsigned long ul;
int main()
{
    start(3);
    int a[NMAX];
    int *aPtr;
    int i;
    for (i = 0; i < NMAX; i++)   
    {
        a[i] = 10 * (i + 1);
        cout << "&a[" << i << "] = " << (ul)&a[i] << "     a[" << i << "] = " << a[i] << endl;
    }

    aPtr = a; // an array identifier is a pointer to the 1st array element
    cout << "\na = " << (ul)a << endl;
    cout << "&a[0] = " << (ul)&a[0] << endl;
    cout << "aPtr = " << (ul)aPtr << endl;
    for (i = 0; i < NMAX; i++)
    {
        cout << "\n(aPtr+" << i << ") = " << (ul)(aPtr + i) << " | *(aPtr+" << i << ") = " << *(aPtr + i);
    }
    end(3);
}