#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "p.h"
using namespace std;

int main()
{
    start(3);
    int x, y;
    char c;
    cin >> x >> c >> y;
    cout << x << c << y;
    end(3);
}