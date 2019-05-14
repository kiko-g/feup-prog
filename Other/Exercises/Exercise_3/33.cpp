#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void startup()
{
    cout << "\n==============================================================\n";
    cout << "This program allows you to type a number and find ";
    cout << "it's square root based on and initial guess and a number of iterations (Heron)\n";
    cout << "RQ is the initial guess, RQN is the result, RQN_2 is approximately n and dif is a delta.\n\n";
}

float heron_result(int nMaxIter, int P)
{
    int i=0;
    float n, rq, rqn, rqn2, DELTA;              //DELTA aka dif
    float crit_stop = pow(10, -P);
    cout << "Type the number (n): "; cin >> n;
    cout << "Type the initial guess (rq): "; cin >> rq;

    while(i < nMaxIter)
    {
        if (i != 0) rq = rqn;
        rqn = (rq + (n / rq)) / 2;
        rqn2 = rqn*rqn;
        DELTA = n - rqn2;

        if (abs(DELTA) <= crit_stop) break;
        i++;
    }
    cout << "\nRESULT = " << setprecision(P) << fixed << rqn << "\n==============================================================\n\n";
    return rqn;
}

float heron_print(int nMaxIter, int P)
{
    int i=0;
    float n, rq, rqn, rqn2, DELTA;              //DELTA aka dif
    float crit_stop = pow(10, -P);
    cout << "Type the number (n): "; cin >> n;
    cout << "Type the initial guess (rq): "; cin >> rq; cout << endl;

    while(i < nMaxIter)
    {
        if (i != 0) rq = rqn;
        rqn = (rq + (n / rq)) / 2;
        rqn2 = rqn*rqn;
        DELTA = n - rqn2;

        if (abs(DELTA) <= crit_stop) break;

        cout << "[" << i << "]\tRQ: " << setprecision(P) << fixed << rq;
        cout << "\t  RQN: " << rqn << "\t  RQN_2: " << rqn2 << "\t  DIF: " << DELTA << endl;
        i++;
    }
    cout << "==============================================================\n\n";
    return rqn;
}




int main()
{
    startup();
    int nMaxIter, P;
    cout << "Type the max number of iterations (nMaxIter): " ; cin >> nMaxIter; 
    cout << "Type the precision (P): "; cin >> P;
    heron_print(nMaxIter, P);

    return 0;
}
