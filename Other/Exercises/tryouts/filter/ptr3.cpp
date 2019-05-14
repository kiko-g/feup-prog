#include <iostream>
#include <iomanip>
#include <string>
#include "p.h"
using namespace std;

void swap1(int *x, int *y)
{
    // X tem &a
    // *X tem A
    // &X tem novo endereço, nova variável
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void swap2(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    start(3);
    int a = 5, b = 10;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "&a: " << &a << ", &b: " << &b << endl
         << endl;
    swap1(&a, &b);
    cout << "after swap1(): a = " << a << ", b = " << b << endl;
    swap2(a, b);
    cout << "after swap2(): a = " << a << ", b = " << b;
    end(3);
}

// Passing reference parameters (as we have seen before) // A reference is a pointer "in disguise"
// When you use references the compiler automatically passes parameters adresses
// and dereferences the pointer parameters in the function body.
// For that reason , references are more convenient for the programmer
// than explicit pointers