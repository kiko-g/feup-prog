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
    int **a; // <-- NOTE THIS 
    int i, j, nLin, nCol;
    cout << "N Lines:     "; cin >> nLin; 
    cout << "N Columns:   "; cin >> nCol;

    // allocate memory for 2D array 
    a = (int **)malloc(nLin * sizeof(int *)); // allocate memory for each line pointer
    for (i = 0; i < nLin; i++) a[i] = (int *)malloc(nCol * sizeof(int)); // allocate memory for each line contents
    // use the array 
    for (i = 0; i < nLin; i++) 
        for (j = 0; j < nCol; j++) a[i][j] = 10 * (i + 1) + j;

    cout << "*a = " << (ul)*a << endl;
    cout << "&a = " << (ul)&a << endl;
    cout << " a = " << (ul)a << endl; 
    
    for (i = 0; i < nLin; i++) cout << "&a[" << i << "] = " << (ul)&a[i] << endl;
    for (i = 0; i < nLin; i++) cout << " a[" << i << "] = " << (ul)a[i] << endl;
    cout << endl;
    for (i = 0; i < nLin; i++) 
        for (j = 0; j < nCol; j++) 
        cout << "a[" << i << "][" << j << "] = " << a[i][j] 
             << "\t&a[" << i << "][" << j << "] = " << (ul)&a[i][j] << endl;
    
    // free all allocated memory (in reverse order of allocation) 
    for (i = 0; i < nLin; i++) free(a[i]);
    free(a);
    end(3);
}