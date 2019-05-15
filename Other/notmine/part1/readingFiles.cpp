#include "myTypes.h"

/*
Le o ficheiro das linhas e guarda cada fila de informacao numa string, adicionando-a num vetor de strings.
*/
vector<string> readLines()
{
	ifstream in_stream;
	string line;
	vector<string> fileContent;

	cout << "Insira o nome do ficheiro das linhas: ";
	cin >> linesFileName;

	in_stream.open(linesFileName);

	if (in_stream.fail())
	{
		cerr << "Ficheiro n�o encontrado. Fechando o programa..." << endl;
		exit(1);
	}

	while (!in_stream.eof())
	{
		getline(in_stream, line);
		if (line == "")
			continue;
		fileContent.push_back(line);
	}

	cout << "Conte�dos lidos!" << endl << endl;

	in_stream.close();

	return fileContent;
}

/*
L� o ficheiro dos condutores e guarda cada fila de informa��o numa string, adicionando-a num vetor de strings.
*/
vector<string> readDrivers()
{
	ifstream in_stream;
	string line;
	vector<string> fileContent;

	cout << "Insira o nome do ficheiro dos condutores: ";
	cin >> driversFileName;

	in_stream.open(driversFileName);

	if (in_stream.fail())
	{
		cerr << "Ficheiro n�o encontrado. Fechando o programa..." << endl;
		exit(1);
	}

	while (!in_stream.eof())
	{
		getline(in_stream, line);
		if (line == "")
			continue;
		fileContent.push_back(line);
	}

	cout << "Conte�dos lidos!" << endl << endl;

	in_stream.close();

	return fileContent;
}

/*
L� o vetor de strings e guarda a informa�ao num vetor de structs, sendo que cada struct representa uma linha.
*/
vector<Line> storingLinesData(const vector<string> &data)
{
	vector<Line> linesVector;

	for (int i = 0; i < data.size(); i++)
	{
		string input = data[i];
		Line lineStruct;

		linesVector.push_back(lineStruct);

		//RECOLHER O ID
		int firstPos = 0;

		int semicolonPos = input.find(";", firstPos);

		string id = input.substr(firstPos, semicolonPos - firstPos);
		int idN = stoi(id);

		linesVector[i].idNumber = idN;

		//RECOLHER A FREQUENCIA
		firstPos = semicolonPos + 2;

		semicolonPos = input.find(";", firstPos);

		string frequency = input.substr(firstPos, semicolonPos - firstPos);
		int freq = stoi(frequency);

		linesVector[i].frequency = freq;

		// RECOLHER AS PARAGENS

		firstPos = semicolonPos + 2;
		semicolonPos = input.find(";", firstPos);
		int commaPos = input.find(",", firstPos);
		while (commaPos < semicolonPos)
		{
			string stop = input.substr(firstPos, commaPos - firstPos);

			linesVector[i].stopsList.push_back(stop);

			firstPos = commaPos + 2;
			commaPos = input.find(",", firstPos);
		}
		//Extrai ultima paragem
		string stop = input.substr(firstPos, semicolonPos - firstPos);
		linesVector[i].stopsList.push_back(stop);

		// RECOLHER AS DURACOES

		firstPos = semicolonPos + 2;
		commaPos = input.find(",", firstPos);
		while (commaPos < input.length())
		{
			string duration = input.substr(firstPos, commaPos - firstPos);

			int dur = stoi(duration);

			linesVector[i].timesBetweenStops.push_back(dur);

			firstPos = commaPos + 2;
			commaPos = input.find(",", firstPos);
		}
		//Extrai ultima duracao
		string duration = input.substr(firstPos, commaPos - firstPos);

		int dur = stoi(duration);
		linesVector[i].timesBetweenStops.push_back(dur);
	}

	return linesVector;
}

/*
L� o vetor de strings e guarda a informa�ao num vetor de structs, sendo que cada struct representa um condutor.
*/
vector<Driver> storingDriversData(const vector<string> &data)
{
	vector<Driver> driversVector;

	for (int i = 0; i < data.size(); i++)
	{
		string input = data[i];
		Driver driverStruct;

		driversVector.push_back(driverStruct);


		//RECOLHER O ID
		int firstPos = 0;

		int semicolonPos = input.find(";", firstPos);

		string id = input.substr(firstPos, semicolonPos - firstPos);
		int idN = stoi(id);

		driversVector[i].idNumber = idN;

		//RECOLHER O NOME
		firstPos = semicolonPos + 2;

		semicolonPos = input.find(";", firstPos);

		string name = input.substr(firstPos, semicolonPos - firstPos - 1);

		driversVector[i].name = name;

		// RECOLHER O TURNO
		firstPos = semicolonPos + 2;

		semicolonPos = input.find(";", firstPos);

		string shift = input.substr(firstPos, semicolonPos - firstPos);
		int shiftN = stoi(shift);

		driversVector[i].shiftHours = shiftN;

		//RECOLHER O NUMERO MAX DE HORAS
		firstPos = semicolonPos + 2;

		semicolonPos = input.find(";", firstPos);

		string maxHours = input.substr(firstPos, semicolonPos - firstPos);
		int maxHoursN = stoi(maxHours);

		driversVector[i].maxHoursWeek = maxHoursN;

		//RECOLHER O NUMERO DE HORAS DE DESCANSO
		firstPos = semicolonPos + 2;

		string restHours = input.substr(firstPos);
		int restHoursN = stoi(restHours);

		driversVector[i].minRestHours = restHoursN;
	}

	return driversVector;
}


