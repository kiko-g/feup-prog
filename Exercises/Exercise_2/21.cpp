#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float x, y, a, b, c, d, e, f;  
    cout << "\nConsider the system\n{ ax + by = c\n{ dx + ey = f\n\n";
    cout << "The expressions for the solution are known.\n";
    cout << "To get the solution (x, y) we need the coeficients.\n\n";
    cout << "Type in a value for a: ";  cin >> a;
    cout << "Type in a value for b: ";  cin >> b;
    cout << "Type in a value for c: ";  cin >> c;
    cout << "Type in a value for d: ";  cin >> d;
    cout << "Type in a value for e: ";  cin >> e;
    cout << "Type in a value for f: ";  cin >> f;
    cout << "\n";

    if ((a * e - b * d) == 0)
    {
        if((c * e - b * f) == 0 || (a * f - c * d) == 0)
        {
            cout << "Underdetermined system\n\n";
        }
        else
        {
            cout << "Impossible system\n\n";
        }
        
    }

    else
    {
        x = (c * e - b * f) / (a * e - b * d);
        y = (a * f - c * d) / (a * e - b * d);
        cout << "x = " << x << endl << "y = " << y << endl << endl;
    }
}
