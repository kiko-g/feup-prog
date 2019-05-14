#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t11, t12, t13;
    int t21, t22, t23;
    int s0=0, s1, s2, s3;
    int aux;

    cout << "\nThis program allows you to sum two time values\n";
    cout << "The time values will be interpreted as Hours Minutes Seconds";
    cout << "You can enter values over 24 for hours.\n";
    cout << "Do not enter values over 59 for minutes or seconds.";
    cout << "\nEnter the times in this format (H M S).\n\n";
    cout << "Type in the 1st time values: ";     cin >> t11 >> t12 >> t13;
    cout << "Type in the 2nd time values: ";     cin >> t21 >> t22 >> t23;

    s1 = t11 + t21;
    s2 = t12 + t22;
    s3 = t13 + t23;

    if(s3 > 59)
    {
        s3 = s3 - 60;
        s2++;
    }

    if(s2 > 59)
    {
        s2 = s2 - 60;
        s1++;
    }

    if(s1 > 24)
    {
        aux = (s1 / 24);
        s1 = s1 - 24*aux;
        s0 = s0 + aux;
        if(t11 < 24 && t21 < 24) s0++;
    }

    cout << "\nResult: " << s0 << " days " << s1 << " hours " << s2 << " minutes " << s3 << " seconds" << "\n\n";
}