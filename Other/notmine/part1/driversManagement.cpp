#include "myTypes.h"

/*
Recebe os par�metros do utilizador (ID, nome do condutor, n�mero de horas de um turno, n�mero m�ximo de horas
por semana e n�mero m�nimo de horas de descanso entre turnos) e guarda-os numa nova struct, que � adicionada 
ao vetor criado anteriormente.
*/
void createDriver(vector<Driver> &data)
{
	Driver driverStruct;
	data.push_back(driverStruct); //Coloca uma struct no vetor de structs dos condutores, para poder inserir os dados
	int id, shift, numMaxHours, nminRestHours;
	int verify = -1;
	bool validInput = false;
	string name;

	cout << "Criar condutor" << endl << endl;

	//Colocar o ID numa nova struct, tendo em conta o input v�lido/inv�lido.

	while (!validInput)
	{
		cout << "Identificador do condutor: ";

		if (cin >> id && id>0)
		{
			verify = searchDriverIdentifier(id, data);

			if (id > 1000)
			{
				cin.ignore(1000, '\n');
				cout << "Insira um ID com, no m�ximo, 3 d�gitos." << endl;
			}

			else if (verify == -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Esse identificador j� existe! Tente novamente..." << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	data[data.size() - 1].idNumber = id;

	//Colocar o nome do motorista na struct

	validInput = false;
	while (!validInput)
	{
		cout << "Nome do condutor: ";
		getline(cin, name);

		if (name == "")
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	data[data.size() - 1].name = name;

	//Colocar o numero de horas de um turno na struct

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero de horas de um turno: ";
		if (cin >> shift)
		{
			if (shift > 0)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else if (shift == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Deve inserir mais horas. Ningu�m trabalha t�o pouco!" << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	data[data.size() - 1].shiftHours = shift;

	// Colocar o numero maximo de horas por semana na struct

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero m�ximo de horas de condu��o por semana: ";
		if (cin >> numMaxHours)
		{
			if(numMaxHours<0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
			else if(numMaxHours<=shift)
			{
				cin.ignore(1000, '\n');
				cout << "N�o � poss�vel atribuir esse n�mero! Deve inserir mais horas." << endl;
			}
			else
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	data[data.size() - 1].maxHoursWeek = numMaxHours;

	//Colocar o numero de horas de descanso na struct

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero m�nimo de horas de descanso: ";
		if (cin >> nminRestHours)
		{
			if (nminRestHours > 0)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else if (nminRestHours == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Seja mais generoso! Insira mais horas." << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}

	}

	data[data.size() - 1].minRestHours = nminRestHours;

	cout << "Condutor criado com sucesso!" << endl;
}

/*
Edita os condutores j� criados. Fornece meios para: alterar o n�mero de horas de um turno, o n�mero m�ximo 
de horas de trabalho por semana, e o n�mero m�nimo de horas de descanso.
*/
void editDriver(vector<Driver> &data)
{
	int id, userChoice;
	int verify = -1;
	bool validInput = false;

	cout << "Alterar condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		if (cin >> id && id>0)
		{
			verify = searchDriverIdentifier(id, data);

			if (verify != -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Esse identificador n�o existe! Tente novamente..." << endl << endl;
			}

		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	//Apresenta uma interface com as fun��es que permitem alterar um condutor

	cout << endl << "Escolha o que pretende alterar" << endl << endl;
	cout << "1 - Alterar nome" << endl;
	cout << "2 - Alterar turno" << endl;
	cout << "3 - Alterar n�mero m�ximo de horas de trabalho" << endl;
	cout << "4 - Alterar horas de descanso entre turnos" << endl << endl;

	userChoice = verifyInput(1, 4);

	clearScreen();

	if (userChoice == 1)
		changeName(id, data);
	else if (userChoice == 2)
		changeShift(id, data);
	else if (userChoice == 3)
		changeMaxHours(id, data);
	else if (userChoice==4)
		changeMinRest(id, data);
}

/*
Recebe do utilizador um identificador para um condutor, e caso exista apaga-o do vetor de structs.
*/
void removeDriver(vector<Driver> &data)
{
	int id;
	int verify = -1;
	bool validInput = false;

	cout << "Remover condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		if (cin >> id && id>0)
		{
			verify = searchDriverIdentifier(id, data);

			if (verify != -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Esse identificador n�o existe! Tente novamente..." << endl << endl;
			}

		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	data.erase(data.begin() + verify); //Apaga a struct do condutor do vetor

	cout << "Condutor apagado com sucesso!" << endl;
}

/*
Altera o n�mero de horas de um turno de um condutor.
*/
void changeShift(int id, vector<Driver> &data)
{
	int index, newShift;
	bool validInput = false;

	index = searchDriverIdentifier(id, data);

	cout << "Alterar turno" << endl;

	cout << endl << "O n�mero atual de horas de um turno �: " << data[index].shiftHours << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";

		if (cin >> newShift)
		{
			if (newShift < 0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl;
			}
			else if (newShift == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Deve inserir mais horas!" << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				validInput = true;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl;
		}
	}

	data[index].shiftHours = newShift;

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o n�mero m�ximo de horas de trabalho por semana de um condutor.
*/
void changeMaxHours(int id, vector<Driver> &data)
{
	int index, newMaxHours;
	bool validInput = false;

	index = searchDriverIdentifier(id, data);

	cout << "Alterar n�mero m�ximo de horas de trabalho" << endl;

	cout << endl << "O n�mero m�ximo atual de horas de trabalho �: " << data[index].maxHoursWeek << " por semana" << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";

		if (cin >> newMaxHours)
		{
			if (newMaxHours<0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
			else if (newMaxHours <= data[index].shiftHours)
			{
				cin.ignore(1000, '\n');
				cout << "N�o � poss�vel atribuir esse n�mero! Deve inserir mais horas." << endl;
			}
			else
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl;
		}
	}

	data[index].maxHoursWeek = newMaxHours;

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o n�mero m�nimo de horas de descanso entre turnos de um condutor.
*/
void changeMinRest(int id, vector<Driver> &data)
{
	int index, newMinRest;
	bool validInput = false;

	index = searchDriverIdentifier(id, data);

	cout << "Alterar horas de descanso entre turnos" << endl;

	cout << endl << "O n�mero m�nimo atual de horas de descanso entre turnos �: " << data[index].minRestHours << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";

		if (cin >> newMinRest)
		{
			if (newMinRest < 0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl;
			}
			else if (newMinRest == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Deve inserir mais horas!" << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				validInput = true;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl;
		}
	}

	data[index].minRestHours = newMinRest;

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o nome de um condutor. Pode ser �til, por exemplo, na eventualidade de um condutor ser substitu�do 
e o n�mero identificador de manter.
*/
void changeName(int id, vector<Driver> &data)
{
	int index; 
	string newName;
	bool validInput = false;

	index = searchDriverIdentifier(id, data);

	cout << "Alterar nome" << endl;

	cout << endl << "O nome do condutor atual �: " << data[index].name << endl;

	while (!validInput)
	{
		cout << "Novo nome: ";
		getline(cin, newName);

		if (newName == "")
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}
	data[index].name = newName;

	cout << "As altera��es foram efetuadas com sucesso!" << endl;
}

/*
Coloca todos os condutores dispon�veis, visto que n�o nos � pedido mais nesta fase do trabalho.
*/
void setAvailability(vector<Driver> &data)
{
	for (int i = 0; i < data.size(); i++)
		data[i].availability = true;
}

/*
Mostra o trabalho atribu�do no condutor. Nesta fase do trabalho apenas devolve que o condutor n�o tem nada
atribu�do. Se o condutor tiver de facto trabalho atribu�do, assume-se que essa informa��o se traduz na linha do autocarro
que conduz, na hora de in�cio e de fim do turno, dados que s�o mostrados pelo programa.
*/
void showShifts(vector<Driver> &data)
{
	int id, driverIndex;
	bool validInput = false;

	cout << "Estado do condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Introduza o ID do condutor: ";

		if (cin >> id)
		{
			driverIndex = searchDriverIdentifier(id, data);

			if (driverIndex != -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cout << "N�o existe qualquer condutor com esse ID! Tente novamente..." << endl;
				cin.ignore(1000, '\n');
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl;
		}
	}

	if (data[driverIndex].shifts.size() == 0)
		cout << "Neste momento, o condutor n�o tem trabalho atribu�do. " << endl;
	else
		for (int i = 0; i < data[driverIndex].shifts.size(); i++)
		{
			cout << "Turno " << (i + 1) << endl << endl;
			cout << "Linha: " << data[driverIndex].shifts[i].lineID << endl;
			cout << "Hora de in�cio: " << data[driverIndex].shifts[i].shiftBegin << endl;
			cout << "Hora de fim: " << data[driverIndex].shifts[i].shiftEnd << endl;
		}
}