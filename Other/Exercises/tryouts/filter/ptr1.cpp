#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int a[10];
    int *p;
    cout << "\np: " << p << "\na: " << &a[0] << " " << (&a[0] + 2) << "\n\n";
    p = &a[0];
    a[3] = 27;
    cout << "a[3]: " << a[3] << "\n";
    *(p + 3) = 28;
    cout << "a[3]: " << a[3] << "\n\n";
}