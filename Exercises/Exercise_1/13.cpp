#define pi 3.141592653589793238462643383279502884
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float r, p;
    cout << "\nType in a value for p (kg/m^3): ";  cin >> p;
    cout << "Type in a value for r (m): ";  cin >> r;
    float mass = 4*(pi * p * r*r*r)/3;
    cout << "Mass of the sphere is " << mass << " kg\n\n";
}