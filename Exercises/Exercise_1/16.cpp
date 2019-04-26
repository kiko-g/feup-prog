#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // a(x1, y1)
    // b(x2, y2)
    // c(x3, y3)

    float x1, y1, x2, y2, x3, y3; //points a, b, c
    
    cout << "\nThis program allows you to calculate the Area of a Triangle based on the coordinates of three points.\n";
    cout << "To get the result we need the semiperimiter (s) and the lenght of the sides of the triangle (a, b, c).\n";
    cout << "Type in the coordinates of the 1st point: "; cin >> x1 >> y1;
    cout << "Type in the coordinates of the 2nd point: "; cin >> x2 >> y2;
    cout << "Type in the coordinates of the 3rd point: "; cin >> x3 >> y3;

    float Area, s, a, b, c;
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); //Distance from point A to point B (1 --> 2)
    b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1)); //Distance from point A to point C (1 --> 3)
    c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)); //Distance from point B to point C (2 --> 3)

    s = (a + b + c)/2;

    Area = sqrt(s * (s-a) * (s-b) * (s-c));
    cout << "\na: " << a << "\nb: " << b << "\nc: " << c << "\ns: " << s << "\nArea: " << Area << "\n\n";
    
}