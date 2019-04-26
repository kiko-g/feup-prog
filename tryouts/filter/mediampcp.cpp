#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "p.h"
using namespace std;

int main()
{
    start(3);

    ifstream fin;
    fin.open("info.txt");
    if( fin.fail() )
    {
        cerr << "\nInput file opening failed.\n";
        exit(1);
    }

    int i=0;
    float avg=0, read;

    while(!( fin.eof() ))
    {
        i++;
        fin >> read;
        avg+=read;
    }
    avg = avg/i;
    
    cout << "Average of numbers in text file: " << avg;
    end(3);
}