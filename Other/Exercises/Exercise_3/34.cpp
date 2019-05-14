#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double round(double x, int n)
{
    return floor(x * pow(10.0, n) + 0.5) / pow(10.0, n);
}

int main()
{
    double x;
    int n;
    cout << "====================================\n";
    cout << "Number you want to round (x): \t"; cin >> x;
    cout << "Type the precision (n): \t"; cin >> n;
    cout << "\nRESULT = " << round(x, n);
    cout << "\n====================================\n";
    return 0;    
}