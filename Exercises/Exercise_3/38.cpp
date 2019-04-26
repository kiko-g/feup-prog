#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;

int mdc(int x, int y);
void start();
void end();


int main()
{
    start();
    int A, B, C;
    cout << "Type a value for A: "; cin >> A;
    cout << "Type a value for B: "; cin >> B;
    cout << "C is the greatest common divisor (GCD aka MDC)\n";
    C = mdc(A, B);
    cout << "\nC = " << C;

    end();
}




int mdc(int x, int y)
{
    if(x % y == 0)
    {
        return y;
    }
    else return mdc(x, (x % y));
}

void start()
{
    cout << "=========================================\n\n";
}
void end()
{
    cout << "\n\n=========================================";
}