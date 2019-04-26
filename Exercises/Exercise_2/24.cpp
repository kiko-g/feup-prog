// Exemolo de funcionamento do programa
// Se o preço for 601 o programa faz o preço como 5 + 1.5 * 2
// Devido ao grama a mais de 600

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int weight, cost;
    cout << "\nIntroduce the weight of the product in grams: "; cin >> weight;

    if(weight < 500) cost = 5;
    if(weight >= 500 && weight <= 1000)
    {
        int aux1;
        aux1 = ((weight - 500)/100) + 1;
        cost = 5 + 1.5 * aux1;
    }
    if(weight > 1000)
    {
        int aux2;
        aux2 = ((weight - 1000)/250) + 1;
        cost = 12.5 + 5 * aux2;
    }

    cout << "The price of transport for the weight of " << weight << " grams is " << cost << " euros.\n\n"; 
}








/*
O custo do transporte de uma certa mercadoria é determinado,
em função do peso da mesma, do seguinte modo: 
- Se o peso for inferior a 500 gramas o custo é igual a 5 euros.
- Se o peso estiver compreendido entre 500 gramas e 1000 gramas,
inclusivé, o custo é igual a 5 euros mais 1.5 euros por cada 
adicional de 100 gramas ou fracção, acima de 500 gramas. 
- Se o peso for superior a 1000 gramas, o custo é 12.5 euros 
mais 5 euros por cada adicional de 250 gramas ou
fracção, acima de 1000 gramas. 

Escreva um programa que dado o peso de uma determinada
mercadoria determine o custo do seu transporte.
*/