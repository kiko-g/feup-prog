#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include "p.h"
using namespace std;

#define N 4
#define M 4

void fill_array(int b[N])
{
    int j = 0;
    for(int i=0; i<N; i++) { b[i] = 10 + j + i; j++; }
}
void alter(int &n)
{
    n = n*n;
    n = n/4 - 7;
}

int main()
{
    start(3);
    int a[N];
    for(int i=0; i<N; i++) { a[i] = 10 + i; }
    cout << "sizeof(a): " << sizeof(a) << "\n\n";

    int b[N];
    for(int i=0; i<N; i++) { b[i] = 10+i; } // fill 1
    for(int i=0; i<N; i++) { cout << "a[" << i << "] = " << b[i] << "\t"; }
    cout << endl;

    fill_array(b);

    for(int i=0; i<N; i++) { cout << "a[" << i << "] = " << b[i] << "\t"; }
    cout << endl;
    cout << "\nsizeof(b): " << sizeof(b);

    int n = 12;
    alter(n);
    cout << "\nValue of N: " << n;
    end(3);
}