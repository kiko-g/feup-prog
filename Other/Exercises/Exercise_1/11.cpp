#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char key;
    cout << endl << "This porgram will read a single ";
    cout << "char and show its code on the ASCII table.\n";
    cout << "Character: ";
    cin >> key;
    int code = key;
    cout << "ASCII code: " << code << endl << endl;
}