#include <iostream>
using namespace std;
//Aula Teórica 22/02/2019

/*
- Conceitos Básicos
    - For
    - Cin funcs (clear, ignore, fail)
    
Quando uma leitura falha convem fazer um cin clear

*/

//##############################################################

int main()
{
    int x;
    bool failed;
    do
    {
        failed = false;
        cout << "x ? ";
        cin >> x;
        if (cin.fail());
        {
            cin.clear(); 
            cin.ignore(1, '\n');
            failed = true;
        }
    } while(!failed);

    cout << "x = " << x << endl;
    return 0;
}

//##############################################################