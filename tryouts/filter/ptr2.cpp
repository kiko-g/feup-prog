#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "p.h"
using namespace std;



int main()
{
    start(3);
    int a;
    int *p;
    a = 10;
    p = &a;
    cout << setw(8) << left << "&a: " << &a                             << " (HEX)\n";
    cout << setw(7) << left << "&a: " << setw(8) << (unsigned long)&a   << " (DEC)\n\n";
    cout << setw(7) << left << "&p: " << &p                             << " (HEX)\n";
    cout << setw(7) << left << "&p: " << setw(8) << (unsigned long)&p   << " (DEC)\n\n";
    cout << setw(7) << left << "p: "  << p                              << " (HEX)\n";
    cout << setw(7) << left << "p: "  << setw(8)  << (unsigned long)p   << " (DEC)\n\n";
    cout << setw(7) << left << "a: "  << a << endl;
    cout << setw(7) << left << "*p: " << *p << "\n\n";
    *p = 99; // *p – dereferencing pointer p, using * operator, changing value of a with the pointer
    cout << "a = " << a << "";
    end(3);
}










void setcolor(int color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    //#include <windows.h>
}

void start(int color)
{
    setcolor(color);
    cout << "========================================"
         << "========================================"
         << "========================================\n";
    setcolor(7);
}

void end(int color)
{
    setcolor(color);
    cout << "\n========================================"
         << "========================================"
         << "========================================";
    setcolor(7);
}