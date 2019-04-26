#include <iostream>
#include <cmath>
using namespace std;

bool primecheck(int x)
{
    int i = 2, aux = sqrt(x);
    bool ok = true;

    while (i <= aux)
    {
        if ((x % i) == 0)
        {
            ok = false;
            break;
        }
        else i++;
    }
    return ok;
}


int main()
{
    int n;
    cout << "\nType in a number to check if it's prime: ";
    cin >> n; 
    if (primecheck(n) == true) cout << "ANSWER: " << n << " is prime.\n\n";
    else cout << n << " is not prime.\n\n";

    bool ok = true;
}
