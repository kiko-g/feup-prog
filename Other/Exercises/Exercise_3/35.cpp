#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//HELPFUL EDITOR FUNCTIONS
void start()
{
   cout << "==============================================================\n";
}
void end()
{
   cout << "\n==============================================================";
}
void backspace(int n) //backspace n times
{
   int i = 0;
   while (i < n)
   {
      cout << "\b \b";
      i++;
   }
}

int gcd(int m, int n)
{
    int r;
    while (n != 0)
    {
       r = m % n;
       m = n;
       n = r;
    }
    return m;
}

//ESSENTIAL FUNCTIONS
bool readFrac(int &N, int &D)
{
    bool success = false;
    char fracSymbol;
    
    while(success == false)
    {
       cout << "N/D: "; cin >> N >> fracSymbol >> D;
       if(cin.fail())
       {
          success = false;
          break;
       }
       if (fracSymbol == '/')  success = true;
       else success = false;       
    }
       //cout << "Success: " << success << endl; 
       return success;
}

void writeFrac(int N, int D)
{
   cout << N << "/" << D;
}

void reduceFrac(int &N, int &D)
{
   int aux = gcd(N,D); 
   N = N / aux;
   D = D / aux;
}

void opFrac(char &op, int &N, int &D, int &N1, int &D1, int &N2, int &D2)
{
    cout << "Operation: "; cin >> op;
    switch(op)
    {
      case '+':
      N = (N1*D2) + (N2*D1);
      D = D1*D2;
      break;
                
      case '-':
      N = (N1*D2) - (N2*D1);
      D = D1*D2;
      break;
             
      case '*':
      N = N1 * N2;
      D = D1 * D2;
      break;

      case '/':
      N = N1 * D2;
      D = D1 * N2;
      break;

      default:
      cout << "\nWhen calling opFrac use one of these: + - * /\n";
    } 
}

int main()
{
    int X, Y;                   //  result = X/Y
    int A, B, C, D;             //  op1 = A/B
    char op;                    //  op2 = C/D
    start();

    readFrac(A, B);
    readFrac(C, D);
    opFrac(op, X, Y, A, B, C, D);
    reduceFrac(X, Y);

    cout << "\n"; writeFrac(A, B);                 //op1
    cout << " " << op << " "; writeFrac(C, D);     //op2
    cout << " = "; writeFrac(X, Y);                //result

    if(Y==1 || X==Y || X==0) backspace(2);
    end();
}












