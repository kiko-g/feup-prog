#include <iostream>
#include <iomanip>
#include <string>
#include "p.h"
using namespace std;

int main()
{ 
    start(3);
    int i;
    double op1, op2;
    double sum, diff, prdct;
    double quot;

    cout << "\nOperator 1: ";     cin >> op1;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid operator. Try again\n\n"
             << "Operator 1: "; cin >> op1;
    }
    cout << "Operator 2: ";     cin >> op2;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nInvalid operator. Try again\n"
             << "Operator 2: "; cin >> op2;
    }

    cout << "\nOP1: " << op1 << "\nOP2: " << op2 << "\n";

    sum = op1 + op2;
    diff = op1 - op2;
    prdct = op1 * op2;
    quot = (double)((op1) / op2);

    cout << "\n";
    cout << left << setw(8) << "sum = "        << sum   << endl;
    cout << left << setw(8) << "diff = "       << diff  << endl;
    cout << left << setw(8) << "prdct = "      << prdct << endl;
    cout << left << setw(8) << "quot = "       << quot  << endl << endl;
    end(3);
    return 0;
}