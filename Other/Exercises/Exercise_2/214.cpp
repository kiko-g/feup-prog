#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float n, dif;
    float rq, rqn, rqn2;
    int nit, i=0;

    cout << "\nThis program allows you to type a number and find";
    cout << "it's square root based on and initial guess and a number of iterations\n";
    cout << "RQ is the initial guess, RQN is the result, RQN_2 is approximately n and dif is a delta.\n\n";
    cout << "Type the number (n): "; cin >> n;
    cout << "Type the initial guess (RQ): "; cin >> rq;
    cout << "Type the max number of iterations (nit): " ; cin >> nit;
    cout << endl;
    
    while(i < nit)
    {
        if (i != 0) rq = rqn;
        rqn = (rq + (n / rq)) / 2;
        rqn2 = rqn*rqn;
        dif = n - rqn2;
        if (abs(dif) <= 0.0001) break;
        cout << "[" << i << "]\tRQ: " << setprecision(4) << fixed << rq << "\tRQN: " << rqn << "\tRQN_2: " << rqn2 << "\t dif: " << dif << endl;
        i++;
    }
    cout << endl;
}
