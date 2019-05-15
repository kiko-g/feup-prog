
#include "myTypes.h"

/*
Interface principal entre o programa e o utilizador. Apresenta no ecr� as funcionalidades principais, recebe
a escolha do utilizador e devolve-a ao programa.
*/
void mainUserInterface(vector<Line> linesData, vector<Driver> driversData)
{
	int userChoice;

	cout << "Sistema de gest�o de informa��o - SEMPRARROLAR" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Gest�o de linhas" << endl;
	cout << "2 - Gest�o de condutores" << endl;
	cout << "3 - Visualiza��o de hor�rios" << endl;
	cout << "4 - Pesquisa" << endl;
	cout << "5 - Sair" << endl << endl;

	userChoice = verifyInput(1, 5);

	clearScreen(); //Limpa a consola para melhorar o aspeto e simplicidade do programa

	if (userChoice == 1)
		linesInterface(linesData, driversData);
	else if (userChoice == 2)
		driversInterface(linesData, driversData);
	else if (userChoice == 3)
		schedulesInterface(linesData, driversData);
	else if (userChoice == 4)
		searchInterface(linesData, driversData);
	else if (userChoice == 5)
	{
		cout << "Programa terminado! Pressione ENTER para fechar." << endl;
		exit(1);
	}
}

/*
Sub-interface dedicada � gest�o de linhas. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void linesInterface(vector<Line> linesData, vector<Driver> driversData)
{
	int userChoice;

	cout << "Gest�o de linhas" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Criar linha" << endl;
	cout << "2 - Alterar linha" << endl;
	cout << "3 - Remover linha" << endl;
	cout << "4 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 4);

	clearScreen();

	switch (userChoice)
	{
	case 1: createLine(linesData);
		quitOrContinue(linesData, driversData);
		break;
	case 2: editLine(linesData);
		quitOrContinue(linesData, driversData);
		break; 
	case 3: removeLine(linesData);
		quitOrContinue(linesData, driversData);
		break;
	case 4: mainUserInterface(linesData, driversData);
		break;
	}
}

/*
Sub-interface dedicada � gest�o de condutores. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void driversInterface(vector<Line> linesData, vector<Driver> driversData)
{
	int userChoice;

	cout << "Gestao de condutores" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Criar condutor" << endl;
	cout << "2 - Alterar condutor" << endl;
	cout << "3 - Remover condutor" << endl;
	cout << "4 - Estado do condutor" << endl;
	cout << "5 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 5);

	clearScreen();

	switch (userChoice)
	{
	case 1: createDriver(driversData);
		quitOrContinue(linesData, driversData);
		break;
	case 2: editDriver(driversData);
		quitOrContinue(linesData, driversData);
		break;
	case 3: removeDriver(driversData);
		quitOrContinue(linesData, driversData);
		break;
	case 4: showShifts(driversData);
		quitOrContinue(linesData, driversData);
		break;
	case 5: mainUserInterface(linesData, driversData);
		break;
	}
}

/*
Sub-interface dedicada � gest�o de hor�rios. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void schedulesInterface(vector<Line> linesData, vector<Driver> driversData)
{
	int userChoice;

	cout << "Gest�o de horarios" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Hor�rio de uma paragem" << endl;
	cout << "2 - Hor�rio de uma linha " << endl;
	cout << "3 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 3);

	clearScreen();

	switch (userChoice)
	{
	case 1: stopSchedule(linesData);
		quitOrContinue(linesData, driversData);
		break;
	case 2: lineSchedule(linesData);
		quitOrContinue(linesData, driversData);
		break;
	case 3: mainUserInterface(linesData, driversData);
		break;
	}
}

/*
Sub-interface dedicada � pesquisa de informa��o. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void searchInterface(vector<Line> linesData, vector<Driver> driversData)
{
	int userChoice;

	cout << "Pesquisa" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Procurar paragem" << endl;
	cout << "2 - Condutores dispon�veis" << endl;
	cout << "3 - Percurso entre paragens" << endl;
	cout << "4 - Condutores necess�rios para a linha" << endl;
	cout << "5 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 5);

	clearScreen();

	switch (userChoice)
	{
	case 1: searchStop(linesData);
		quitOrContinue(linesData, driversData);
		break;
	case 2: availableDrivers(driversData);
		quitOrContinue(linesData, driversData);
		break;
	case 3: routeCalculator(linesData);
		quitOrContinue(linesData, driversData);
		break;
	case 4: cout << "Funcionalidade em desenvolvimento..." << endl;
		quitOrContinue(linesData, driversData);
		break;
	case 5: mainUserInterface(linesData, driversData);
		break;
	}
}

/*
Pergunta ao utilizador se pretente efetuar outra opera��o ou terminar o programa.
Tamb�m assegura que este insere um valor v�lido.
*/
void quitOrContinue(vector<Line> linesData, vector<Driver> driversData)
{
	char userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout << endl << "Deseja efetuar outra opera��o? (S/N) : ";
		if (cin >> userChoice && (userChoice == 'S' || userChoice == 'N' || userChoice == 's' || userChoice == 'n'))
			validInput = true;
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Op��o inv�lida, tente novamente..." << endl << endl;
		}
	}

	if (userChoice == 'S' || userChoice == 's')
	{
		clearScreen();
		mainUserInterface(linesData, driversData);
	}
	else
	{
		savingChanges(linesData, driversData);
		cout << endl << "Programa terminado! Pressione ENTER para fechar." << endl << endl;
		exit(1);
	}
}
