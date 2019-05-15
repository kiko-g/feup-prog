#include <string>
#include "Company.h"
#include <iostream>

using namespace std;

/*
Recebe uma paragem do utilizador, e devolve as linhas em que se encontra, funcionando tambem para o caso de não existir.
*/
void searchStop(const Company &company)
{
	string stop;
	vector<int> lines;

	cout << "Procurar paragem" << endl << endl;

	cout << "Paragem: ";
	getline(cin, stop);

	company.searchStop(stop);
}

/*
Recebe duas paragens do utilizador e procura-as nas linhas existentes. Caso exista alguma linha que as contenha,
calcula o percurso a efetuar e a duracao total. Caso exista mais do que uma linha, apenas devolve a que tiver
menor duracao. Também funciona para o caso de não existir.
*/
void routeCalculator(const Company &company)
{
	string stop1, stop2;

	cout << "Percurso entre paragens" << endl << endl;

	cout << "Paragem inicial: ";
	getline(cin, stop1);

	cout << "Paragem final: ";
	getline(cin, stop2);

	company.routeCalculator(stop1, stop2);
}
