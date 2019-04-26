#include <iostream>
#include <iomanip>
#include <string>
#include "p.h"
using namespace std;

typedef unsigned long ul;

void swap1(int *x, int *y)
{
    int temp;
    setcolor(2); cout << "SWAP1_a\n";  setcolor(7);
    cout << " &x = "    << (ul) &x << ", " 
         << " &y = "    << (ul) &y << ", " 
         << " &temp = " << (ul) &temp << " (decimal)\n";
    cout << " x = "     << (ul) x << ", "
         << " y = "     << (ul) y << " (decimal)\n";
    cout << " *x = "    << *x 
         << " *y = "    << *y << ", " 
         << " temp = "  << temp << endl;
    temp = *x;
    *x = *y;
    *y = temp;
    
    setcolor(2); cout << "SWAP1_b\n"; setcolor(7);
    cout << " *x = " << *x 
         << " *y = " << *y << ", " 
         << " temp = " << temp << endl;
}

void swap2(int &x, int &y)
{
    int temp;
    setcolor(2);
    cout << "SWAP2_a\n";
    setcolor(7);
    cout << " &x = " << (ul) &x << ", " <<
    " &y = " << (ul) &y << ", " <<
    " &temp = " << (ul)&temp << " (decimal)\n";
    cout << " x = " << (ul) x << ", " <<
    " y = " << (ul) y << ", " << " (decimal)" <<
    " temp = " << temp << endl; temp = x; x = y; y = temp;
    setcolor(2);
    cout << "SWAP2_b\n";
    setcolor(7);
    cout << " x = " << x << ", " <<
    " y = " << y << ", " <<
    " temp = " << temp << ", " <<endl;
}

int main()
{
    start(3);
    int a = 1, b = 2;
    setcolor(2); cout << "MAIN\n"; setcolor(7);
    
    cout << " &a = " << (ul) &a << ",  &b = " << (ul) &b << " (decimal)\n";
    cout << " a = " << a << ", b = " << b << endl << endl;
    
    swap1(&a,&b); //pointer receivers
    cout << "MAIN after swap1(): a = " << a << ", b = " << b << endl << endl;

    swap2(a,b); //ampersand receivers
    cout << "MAIN after swap2(): a = " << a << ", b = " << b;
    end(3);
}