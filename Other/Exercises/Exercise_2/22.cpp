#include <iostream>
#include <cmath>
using namespace std;

double max(double a, double b, double c)
{
    double max = a;
    if(b > max) max = b;
    if(c > max) max = c;

    return max;
}

double min(double a, double b, double c)
{
    double min = a;
    if(b < min) min = b; 
    if(c < min) min = c;

    return min;
}

void dec_and_sides(double a, double b, double c)
{
    double x, y, z;
    if(a == max(a, b, c))
    {
        x = a;
        if(b == min(a, b, c))
        {
            y = c;
            z = b;
        }
        else
        {
            y = b;
            z = c;
        }
    }   
    if (b == max(a, b, c))
    {
        x = b;
        if (a == min(a, b, c))
        {
            y = c;
            z = a;
        }
        else
        {
            y = a;
            z = c;
        }
    }
    if (c == max(a, b, c))
    {
        x = c;
        if (a == min(a, b, c))
        {
            y = b;
            z = a;
        }
        else
        {
            y = a;
            z = c;
        }
    }

    cout << "(a, b, c) in decrescent order: " << x << " | " << y << " | " << z << endl;
    if( (y + z) <= x) 
    {
        cout << "(a, b, c) cannot form a triangle\n\n"; 
    }
    else
    {
        cout << "It's possible to form a triangle with (a, b, c).\n\n";
    }
    
}


int main()
{
    double a, b, c, mx, mn;

    cout << "\nThis program:\n- Compares 3 numbers of type double and indicates the min and max values.\n";
    cout << "- Prints them in decrescent order.\n";
    cout << "- Checks if (a, b, c) could be the sides of a triangle.\n\n";
    cout << "Type a value for a: "; cin >> a;
    cout << "Type a value for b: "; cin >> b;
    cout << "Type a value for c: "; cin >> c;
    
    mx = max(a, b, c);
    mn = min(a, b, c);
    cout << "\nThe MIN value of (a, b, c) is " << mn << endl;
    cout << "The MAX value of (a, b, c) is " << mx << endl;
    dec_and_sides(a, b, c);

    return 0;
}
