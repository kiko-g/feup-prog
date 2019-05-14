#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, i=2;
    bool ok = true;
    cout << "\nType in a number to check if it's prime: "; cin >> n;
    int aux = sqrt(n);
    
    while(i <= aux)
    {
       if((n % i) == 0) 
       {
          ok = false;
          break;
       }
       else i++;
    }
    
    if(ok == true) cout << "ANSWER: " << n << " is prime.\n\n";  
    else cout << n << " is not prime.\n\n"; 
}
