#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;

//HELPFUL EDITOR FUNCTIONS
void start();
void end();
void tabs(int n);
//ACTUAL FUNCTIONS
long long factorial_itr(int n);
long long unfac(long long x);
long long factorial_rec(int n);


int main()
{
    start();
    int a;
    long long f1, f2;
    cout << "Factorial: \n"; cin >> a;
    f1 = factorial_itr(a);
    f2 = factorial_rec(a);

    cout << a << "! = " << f1 << endl;
    cout << a << "! = " << f2;
    end();
}









void start()
{
   cout << "=========================================\n\n";
}
void end()
{
   cout << "\n\n=========================================";
}
void tabs(int n)
{
    int i=0;
    while(i < n)
    {
        cout << "\t";
        i++;
    }
}
long long factorial_itr(int n)
{
    long long F = 1;
    int i=1;
    while(i <= n) F*=i++;
    return F;
}
long long unfac(long long x)
{
    long long n = 1;
    while (x /= ++n);
    return (n - 1);
}
long long factorial_rec(int n)
{
    if(n > 1) return n * factorial_rec(n - 1);
    else return 1;
}
