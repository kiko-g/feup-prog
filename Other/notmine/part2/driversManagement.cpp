#include <iostream>
#include "Company.h"
#include <string>
#include <sstream>
#include "Time.h"

using namespace std;


bool isNumber(string input);
int verifyInput(int low, int high);
void clearScreen();
bool quitOrContinue(const Company &company);

/*
Recebe os parametros do utilizador (ID, nome do condutor, numero de horas de um turno, numero maximo de horas
por semana e numero minimo de horas de descanso entre turnos) e guarda-os num novo Driver, que e adicionado
ao vetor criado anteriormente.
*/
void createDriver(Company &company)
{
	unsigned int id, shift, numMaxHours, nminRestHours;
	int verify = -1;
	bool validInput = false;
	string name, input;

	cout << "Criar condutor" << endl << endl;

	//Recebe o ID do utilizador, tendo em conta o input valido/invalido.

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{

			if (isNumber(input)) //Se o input for um numero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existencia do ID

				if (verify == -1)
					validInput = true;
				else
					cout << "Esse ID ja existe! Tente novamente..." << endl;
			}
			else
				cout << "Input invalido! Tente novamente..." << endl;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	id = stoi(input);

	//Recebe o nome do motorista do utilizador

	validInput = false;
	while (!validInput)
	{
		cout << "Nome do condutor: ";
		getline(cin, name);

		if (name == "")
			cout << "Input invalido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	//Recebe o numero de horas de um turno

	validInput = false;
	while (!validInput)
	{
		cout << "Numero de horas de um turno: ";
		getline(cin, input);

		if (isNumber(input))
		{
			shift = stoi(input);

			if (shift > 0 && shift <= 8)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	// Recebe o numero maximo de horas por semana

	validInput = false;
	while (!validInput)
	{
		cout << "Numero maximo de horas de conducao por semana: ";
		getline(cin, input);

		if (isNumber(input))
		{
			numMaxHours = stoi(input);

			if (numMaxHours > shift && numMaxHours <= 48)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	//Recebe o numero de horas de descanso

	validInput = false;
	while (!validInput)
	{
		cout << "Numero minimo de horas de descanso: ";
		getline(cin, input);

		if (isNumber(input))
		{
			nminRestHours = stoi(input);

			if (nminRestHours > 0 && nminRestHours <= 7)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	Driver newDriver(id, name, shift, numMaxHours, nminRestHours);
	company.addDriver(newDriver);

	cout << "Condutor criado com sucesso!" << endl;
}


/*
Recebe do utilizador um identificador para um condutor, e caso exista apaga-o do vetor de Drivers.
*/
void removeDriver(Company &company)
{
	string input;
	int verify = -1;
	bool validInput = false;

	cout << "Remover condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{
			if (isNumber(input)) //Se o input for um numero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existencia do ID

				if (verify != -1)
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

	company.removeDriver(verify);

	cout << "Condutor apagado com sucesso!" << endl;
}

/*
Altera o numero de horas de um turno de um condutor.
*/
void changeShift(Company &company, unsigned int id)
{
	int index;
	unsigned int newShift;
	string input;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar turno" << endl;

	cout << endl << "O numero atual de horas de um turno: " << company.getDrivers()[index].getShiftMaxDuration() << endl;

	while (!validInput)
	{
		cout << "Novo numero de horas: ";
		getline(cin, input);

		if (isNumber(input))
		{
			newShift = stoi(input);

			if (newShift == 0)
				cout << "Deve inserir mais horas!" << endl;
			else if (newShift >= 24)
				cout << "Deve inserir um valor mais baixo!" << endl;	
			else
				validInput = true;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	vector<Driver> newDrivers = company.getDrivers();
	newDrivers[index].setShiftMaxDuration(newShift);
	company.setDrivers(newDrivers);

	cout << "Alteracao efetuada com sucesso!" << endl;
}

/*
Altera o numero maximo de horas de trabalho por semana de um condutor.
*/
void changeMaxHours(Company &company, unsigned int id)
{
	int index;
	string input;
	unsigned int newMaxHours;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar numero maximo de horas de trabalho" << endl;

	cout << endl << "O numero maximo atual de horas de trabalho: " << company.getDrivers()[index].getMaxWeekWorkingTime() << " por semana" << endl;

	while (!validInput)
	{
		cout << "Novo numero de horas: ";
		getline(cin, input);

		if (isNumber(input))
		{
			newMaxHours = stoi(input);

			if (newMaxHours <= company.getDrivers()[index].getShiftMaxDuration())
				cout << "Nao e possivel atribuir esse nu�mero! Deve inserir mais horas." << endl;
			else
				validInput = true;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
		}


	vector<Driver> newDrivers = company.getDrivers();
	newDrivers[index].setMaxWeekWorkingTime(newMaxHours);
	company.setDrivers(newDrivers);

	cout << "Alteracao efetuada com sucesso!" << endl;
}

/*
Altera o numero minimo de horas de descanso entre turnos de um condutor.
*/
void changeMinRest(Company &company, unsigned int id)
{
	int index;
	unsigned int newMinRest;
	string input;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar horas de descanso entre turnos" << endl;

	cout << endl << "O numero minimo atual de horas de descanso entre turnos: " << company.getDrivers()[index].getMinRestTime() << endl;

	while (!validInput)
	{
		cout << "Novo numero de horas: ";
		getline(cin, input);

		if (isNumber(input))
		{
			newMinRest = stoi(input);

			if (newMinRest == 0)
				cout << "Deve inserir mais horas!" << endl;
			else
				validInput = true;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	vector<Driver> newDrivers=company.getDrivers();
	newDrivers[index].setMinRestTime(newMinRest);
	company.setDrivers(newDrivers);

	cout << "Alteracao efetuada com sucesso!" << endl;
}

/*
Altera o nome de um condutor. Pode ser util, por exemplo, na eventualidade de um condutor ser substituido
e o numero identificador de manter.
*/
void changeName(Company &company, unsigned int id)
{
	int index;
	string newName;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar nome" << endl;

	cout << endl << "O nome do condutor atual: " << company.getDrivers()[index].getName() << endl;

	while (!validInput)
	{
		cout << "Novo nome: ";
		getline(cin, newName);

		if (newName == "")
			cout << "Input invalido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	vector<Driver> newDrivers=company.getDrivers();
	newDrivers[index].setName(newName);
	company.setDrivers(newDrivers);

	cout << "As alteracoes foram efetuadas com sucesso!" << endl;
}

/*
Apresenta informacao relativa ao trabalho atribuido a um condutor especificado pelo utilizador, que e traduzida nos
turnos que tem que realizar.
*/
void showShifts(const Company &company)
{
	bool validInput = false;
	string input;
	int verify = -1;

	cout << "Visualizar trabalho do condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{

			if (isNumber(input)) //Se o input for um numero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existencia do ID

				if (verify != -1)
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

	if (company.getDrivers()[verify].getShifts().size() == 0)
		cout << "De momento, o condutor nao tem qualquer trabalho atribuido." << endl;
	else
		for (int i = 0; i < company.getDrivers()[verify].getShifts().size(); i++)
		{
			cout << "Turno " << i + 1 << endl;
			company.getDrivers()[verify].getShifts()[i].showInfo();
			cout << endl;
		}
}

/*
Edita os condutores ja criados. Fornece meios para: alterar o namero de horas de um turno, o numero maximo
de horas de trabalho por semana, e o numero minimo de horas de descanso.
*/
void editDriver(Company &company)
{
	int userChoice;
	unsigned int id;
	string input;
	int verify = -1;
	bool validInput = false;

	cout << "Alterar condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{

			if (isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existencia do ID

				if (verify != -1)
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

	bool anotherOp = true;

	while (anotherOp)
	{

		//Apresenta uma interface com as funcoes que permitem alterar um condutor

		cout << endl << "Escolha o que pretende alterar" << endl << endl;
		cout << "1 - Alterar nome" << endl;
		cout << "2 - Alterar turno" << endl;
		cout << "3 - Alterar numero maximo de horas de trabalho" << endl;
		cout << "4 - Alterar horas de descanso entre turnos" << endl;
		cout << "0 - Voltar" << endl << endl;

		userChoice = verifyInput(0, 4);

		clearScreen();

		switch (userChoice)
		{
		case 1:changeName(company, id);
			anotherOp=quitOrContinue(company);
			break;
		case 2:changeShift(company, id);
			anotherOp = quitOrContinue(company);
			break;
		case 3:changeMaxHours(company, id);
			anotherOp = quitOrContinue(company);
			break;
		case 4:changeMinRest(company, id);
			anotherOp = quitOrContinue(company);
			break;
		case 0: return;
		}
	}
}


/*
Atribuir interativamente o servico aos condutores. Mostra ao utilizador uma "lista" com os turnos a atribuir aos autocarros,
recebe o ID do turno a atribuir e o ID do condutor e invoca o metodo da classe.
*/
void allocateService(Company &company)
{
	string input;
	bool validInput = false;
	unsigned int driverID;
	int verify = -1;
	unsigned int lineID;
	unsigned int busNumber;
	string dayOfWeek;
	unsigned int start;
	unsigned int end;
	Time t1, t2;

	cout << "Atribuir servico" << endl << endl;

	while (!validInput)
	{
		cout << "Dia da semana: ";
		getline(cin, input);

		if (input == "Segunda" || input == "Terca" || input == "Quarta" || input == "Quinta" || input == "Sexta" )
		{
			validInput = true;
			dayOfWeek = input;
		}
		else
			cout << "Input invalido! Tente novamente..." << endl;
	}

	cout << "Turnos por atribuir" << endl;

	for (int i = 0; i < company.getBusShifts().size(); i++)
	{
		if (convertMinHours(company.getBusShifts()[i].getStartTime()).dayOfWeek == dayOfWeek)
		{
			company.getBusShifts()[i].showInitialInfo();
			cout << endl;
		}
	}

	validInput = false;
	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{

			if (isNumber(input)) //Se o input for um numero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existencia do ID

				if (verify != -1)
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

	driverID = stoi(input);

	validInput = false;
	verify = -1;

	while (!validInput)
	{
		cout << "Identificador da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //So sao aceites IDs com, no maximo 3 digitos
		{

			if (isNumber(input)) //Se o input for um numero positivo
			{
				verify = company.searchLineIdentifier(stoi(input)); //Verifica a existencia do ID

				if (verify != -1)
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

	lineID = stoi(input);

	validInput = false;
	while (!validInput)
	{
		cout << "Numero do autocarro: ";
		getline(cin, input);

			if (isNumber(input)) //Se o input for um numero positivo
			{
				validInput = true;
			}
			else
				cout << "Input invalido! Tente novamente..." << endl;
	}

	busNumber = stoi(input);

	validInput = false;
	while (!validInput)
	{
		cout << "Hora de inicio (HH:MM): ";
		getline(cin, input);

		istringstream instr;
		instr.str(input);

		int h;
		char symbol;
		int min;

		if (instr >> h >> symbol >> min)
			if (h >= 6 && h <= 19 && min >= 0 && min < 60 && symbol == ':')
			{
				validInput = true;

				t1.dayOfWeek = dayOfWeek;
				t1.hours = h;
				t1.minutes = (double) min;

			}
			else
				cout << "Input invalido! Tente novamente..." << endl;
	}

	validInput = false;
	while (!validInput)
	{
		cout << "Hora de fim (HH:MM): ";
		getline(cin, input);

		istringstream instr;
		instr.str(input);

		int h;
		char symbol;
		int min;

		if (instr >> h >> symbol >> min)
			if (h >= 6 && h <= 19 && min >= 0 && min < 60 && symbol == ':')
			{
				validInput = true;

				t2.dayOfWeek = dayOfWeek;
				t2.hours = h;
				t2.minutes = (double) min;
			}
			else
				cout << "Input invalido! Tente novamente..." << endl;
	}

	start = convertHoursMin(t1);
	end = convertHoursMin(t2);

	verify = company.searchShift(busNumber, lineID, start, end);

	if (verify != -1)
		company.allocateService(driverID, busNumber, lineID, start, end);
	else
		cout << "Turno inexistente!" << endl;
}