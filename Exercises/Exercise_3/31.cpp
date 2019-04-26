#include <iostream>
#include <cmath>
using namespace std;

// a(x1, y1)
// b(x2, y2)
// c(x3, y3)

float distance(float x1, float y1, float x2, float y2)
{
    float distance;
    distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); 

    return distance;
}

float area(float s, float a, float b, float c)
{
    float area2;
    area2 = sqrt(s * (s - a) * (s - b) * (s - c));

    return area2;
}




int main()
{
    float x1, y1, x2, y2, x3, y3; //points a, b, c

    cout << "\nThis program allows you to calculate the Area of a Triangle based on the coordinates of three points.\n";
    cout << "To get the result we need the semiperimiter (s) and the lenght of the sides of the triangle (a, b, c).\n";
    cout << "Type in the coordinates of the 1st point: "; cin >> x1 >> y1;
    cout << "Type in the coordinates of the 2nd point: "; cin >> x2 >> y2;
    cout << "Type in the coordinates of the 3rd point: "; cin >> x3 >> y3;

    float area_var, s, a, b, c;
    a = distance(x1, y1, x2, y2);           //Distance from point A to point B (1 --> 2)
    b = distance(x1, y1, x3, y3);           //Distance from point A to point C (1 --> 3)
    c = distance(x2, y2, x3, y3);           //Distance from point B to point C (2 --> 3)
    s = (a + b + c) / 2;
    area_var = area(s, a, b, c);

    cout.precision(5);
    cout << "\na: " << a << "\nb: " << b << "\nc: " << c << "\ns: " << s << "\nArea: " << area_var << "\n\n";
}