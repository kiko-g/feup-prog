#include "Company.h"
#include <string>
#include <iostream>

using namespace std;

/*
Pergunta ao utilizador se pretende guardar as alteracoes e age de acordo com a sua resposta.
*/
void savingChanges(const Company &company)
{
	string userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout <<  "Deseja guardar as alteracoes? (S/N) : ";
		getline(cin, userChoice);

		if (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n")
			validInput = true;
		else
			cout << "Opcao invalida, tente novamente..." << endl << endl;
	}

	if (userChoice == "S" || userChoice == "s")
	{
		company.savingDriversData();
		company.savingLinesData();
	}
}