#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    float avg;
    cout << "\nType in 3 integers: ";
    cin >> a >> b >> c;
    avg = (a+b+c) / 3;

    cout << "\navg: " << avg << endl;
    cout << "a-avg: " << a - avg << endl;
    cout << "b-avg: " << b - avg << endl;
    cout << "c-avg: " << c - avg << endl << endl;
}