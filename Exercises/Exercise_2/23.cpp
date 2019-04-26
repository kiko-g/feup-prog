#include <iostream>
#include <cmath>
using namespace std;

/*
Escreva um programa que simule uma calculadora, isto é,
que leia do teclado dois números e um caracter (+, - , * ou /)
que indica uma operação aritmética, no formato "número operação
número", e que apresente o resultado da operação indicada.
*/

int main()
{   
  int op1, op2, result, answer;
  char operation;
  bool ok = false;
     
    
  while(!ok)
  {
    cout << "\nType a value for operator 1: ";    cin >> op1;
    cout << "Type a value for operator 2: ";    cin >> op2;
    cout << "Indicate the operation:  ";        cin >> operation;

    if (cin.fail())
    {
      cin.clear();
      cin.ignore(1, '\n');
      cout << "\n======= Invalid operation. Try one of these [+ - / *] ========\n";
      continue;
    }

    switch (operation)
    {
      case '+':
      result = op1 + op2;
      ok = true;
      break;
                
      case '-':
      result = op1 - op2;
      ok = true;
      break;
             
      case '*':
      result = op1 * op2;
      ok = true;
      break;

      case '/':
      result = op1 / op2;
      ok = true;
      break;

      default:
      cout << "\n======= Invalid operation. Try one of these [+ - / *] ========\n";
    }
  } 
    cout << op1 << " " << operation << " " << op2 << " = " << result << endl;
}