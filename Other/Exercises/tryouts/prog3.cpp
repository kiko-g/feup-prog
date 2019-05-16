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
    int id;
    string id_str = "12345";
    stoint(id_str, id);
    cout << id;
    end(3);
}