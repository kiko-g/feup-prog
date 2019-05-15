#include "Company.h"
#include <string>
#include <iostream>

using namespace std;

bool isNumber(string input);

/*
Recebe um ID de uma linha do utilizador e invoca o metodo da classe que mostra o horario dessa linha.
*/
void lineSchedule(const Company &company){

	int indice;
	string input;
	bool validInput = false;

    //receber input do user
	while (!validInput)
	{
		cout << "Indique o ID da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{
			if (isNumber(input)) //Se o input for um numero positivo
			{
				indice = company.searchLineIdentifier(stoi(input)); //Verifica a existencia do ID

				if (indice != -1)
					validInput = true;
				else
					cout << "Esse ID nao existe! Tente novamente..." << endl;
			}
			else
				cout << "Input invalido! Tente novamente..." << endl;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	company.getLines()[indice].schedule();
}

/*
Recebe uma paragem do utilizador e invoca o metodo da classe que mostra o horario dessa paragem.
*/
void stopSchedule(const Company &company) {

	bool validInput = false;
	string input;

	while (!validInput)
	{
		cout << "Indique o nome da paragem: ";
		getline(cin, input);

		if(company.searchStop2(input).size()> 0)
			validInput = true;
		else
			cout << "Essa paragem nao existe! Tente novamente..." << endl;
		}

    for (int i = 0; i < company.searchStop2(input).size(); ++i) {

   company.getLines()[company.searchStop2(input).at(i)].stopsSchedule(input);
        cout << endl<<endl;
        }
}

/*
Recebe do utilizador um ID de uma linha e o numero de ordem de um autocarro e mostra informacao sobre ele.
*/
void busInfo(const Company &company) {

	unsigned int id, busOrder;
	int indice;
	bool validInput = false;
	string input;

	while (!validInput)
	{
		cout << "Insira o id da linha que o autocarro percorre: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{
			if (isNumber(input)) //Se o input for um numero positivo
			{
				indice = company.searchLineIdentifier(stoi(input)); //Verifica a existencia do ID

				if (indice != -1)
					validInput = true;
				else
					cout << "Esse ID nao existe! Tente novamente..." << endl;
			}
			else
				cout << "Input invalido! Tente novamente..." << endl;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	id = stoi(input);

	validInput = false;

	while (!validInput)
	{
		cout << "Indique o numero de ordem do autocarro: ";
		getline(cin,input);

		if (isNumber(input))
			validInput = true;
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	busOrder = stoi(input);

	company.getLines().at(company.searchLineIdentifier(id)).busesInf(busOrder);
}
