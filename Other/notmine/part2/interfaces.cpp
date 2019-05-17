#include "Company.h"
#include <iostream>

int verifyInput(int low, int high);
void savingChanges(const Company &company);
void createDriver(Company &company);
void editDriver(Company &company);
void removeDriver(Company &company);
void showShifts(const Company &company);
void lineSchedule(const Company &company);
void stopSchedule(const Company &company);
void searchStop(const Company &company);
void routeCalculator(const Company &company);
void clearScreen();
void mainUserInterface(Company &company);
void driversInterface(Company &company);
void infoInterface(Company &company);
void searchInterface(Company &company);
void allocateService(Company &company);
bool quitOrContinue(const Company &company);
void busInfo(const Company &company);

/*
Interface principal entre o programa e o utilizador. Apresenta no ecra as funcionalidades principais, recebe
a escolha do utilizador e devolve-a ao programa.
*/
void mainUserInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{
		int userChoice;

		cout << "Sistema de gestao de informacao - SEMPRARROLAR" << endl;
		cout << "Funcionalidades disponiveis" << endl << endl;
		cout << "1 - Gestao de condutores" << endl;
		cout << "2 - Visualizar informacao" << endl;
		cout << "3 - Pesquisa" << endl;
		cout << "0 - Sair" << endl << endl;

		userChoice = verifyInput(0, 3);

		clearScreen(); //Limpa a consola para melhorar o aspeto e simplicidade do programa

		if (userChoice == 1)
			driversInterface(company);
		else if (userChoice == 2)
			infoInterface(company);
		else if (userChoice == 3)
			searchInterface(company);
		else if (userChoice == 0)
		{
			savingChanges(company);
			cout << "Programa terminado! Pressione ENTER para fechar." << endl;
			exit(1);
		}

	}
}

/*
Sub-interface dedicada a gest�o de condutores. Apresenta as funcionalidades disponiveis, recebe a escolha
do utilizador e inicializa a funcao pedida
*/
void driversInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{
		int userChoice;

		cout << "Gestao de condutores" << endl;
		cout << "Funcionalidades disponiveis" << endl << endl;
		cout << "1 - Criar condutor" << endl;
		cout << "2 - Alterar condutor" << endl;
		cout << "3 - Remover condutor" << endl;
		cout << "4 - Atribuir servico" << endl;
		cout << "0 - Voltar" << endl << endl;

		userChoice = verifyInput(0, 4);

		clearScreen();

		switch (userChoice)
		{
		case 1: createDriver(company);
			anotherOp = quitOrContinue(company);
			break;
		case 2: editDriver(company);
			break;
		case 3: removeDriver(company);
			anotherOp = quitOrContinue(company);
			break;
		case 4: allocateService(company);
			anotherOp = quitOrContinue(company);
			break;
		case 0: return;
			break;
		}

	}
}

/*
Sub-interface dedicada a visualizacao de informacao. Apresenta as funcionalidades disponiveis, recebe a escolha
do utilizador e inicializa a funcao pedida
*/
void infoInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{

		int userChoice;

		cout << "Visualiza�ao de informacao" << endl;
		cout << "Funcionalidades disponiveis" << endl << endl;
		cout << "1 - Horario de uma paragem" << endl;
		cout << "2 - Horario de uma linha " << endl;
		cout << "3 - Informacao de um autocarro" << endl;
		cout << "4 - Trabalho de um condutor" << endl;
        cout << "5 - Verificar periodos de condutores sem o servico completo atribuido" << endl;
		cout << "6 - Verificar periodos de autocarros sem condutor atribuido" << endl;
		cout << "0 - Voltar" << endl << endl;

		userChoice = verifyInput(0, 6);

		clearScreen();

		switch (userChoice)
		{
		case 1: stopSchedule(company);
			anotherOp = quitOrContinue(company);
			break;
		case 2: lineSchedule(company);
			anotherOp = quitOrContinue(company);
			break;
		case 3: busInfo(company);
			anotherOp = quitOrContinue(company);
			break;
		case 4: showShifts(company);
			anotherOp = quitOrContinue(company);
			break;
        case 5:
			company.checkAvailableDrivers();
			anotherOp = quitOrContinue(company);
			break;
		case 6:
			company.checkBuses();
			anotherOp = quitOrContinue(company);
			break;
		case 0: return;
			break;
		}

	}
}

/*
Sub-interface dedicada a pesquisa de informacao. Apresenta as funcionalidades disponiveis, recebe a escolha
do utilizador e inicializa a funcao pedida
*/
void searchInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{

		int userChoice;

		cout << "Pesquisa" << endl;
		cout << "Funcionalidades disponiveis" << endl << endl;
		cout << "1 - Procurar paragem" << endl;
		cout << "2 - Percurso entre paragens" << endl;
		cout << "0 - Voltar" << endl << endl;

		userChoice = verifyInput(0, 2);

		clearScreen();

		switch (userChoice)
		{
		case 1: searchStop(company);
			anotherOp = quitOrContinue(company);
			break;
		case 2: routeCalculator(company);
			anotherOp = quitOrContinue(company);
			break;
		case 0: return;
			break;
		}

	}
}

/*
Pergunta ao utilizador se pretente efetuar outra operacao ou terminar o programa.
Tambem assegura que este insere um valor valido.
*/
bool quitOrContinue(const Company &company)
{
	string userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Deseja efetuar outra operacao? (S/N) : ";
		getline(cin, userChoice);

		if (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n")
			validInput = true;
		else cout << "Opcao invalida, tente novamente..." << endl << endl;
	}

	if (userChoice == "S" || userChoice == "s")
	{
		clearScreen();
		return false;
	}
	else
	{
		savingChanges(company);
		cout << endl << "Programa terminado! Pressione ENTER para fechar." << endl << endl;
		exit(1);
	}
}


/*
Funcao simples para limpar o ecra.
*/
void clearScreen()
{
    cout << string(100,'\n');
}