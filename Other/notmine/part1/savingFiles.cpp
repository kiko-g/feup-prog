#include "myTypes.h"

/*
Guarda a informa��o contida no vetor de structs no ficheiro de linhas.
*/
void savingLinesData(const vector<Line> &data)
{
	ofstream out_stream;

	out_stream.open(linesFileName);

	for (int i = 0; i < data.size(); i++)
	{
		out_stream << data[i].idNumber << " ; ";
		out_stream << data[i].frequency << " ; ";

		for (int j = 0; j < (data[i].stopsList.size() - 1); j++)
			out_stream << data[i].stopsList[j] << ", ";

		out_stream << data[i].stopsList[data[i].stopsList.size() - 1] << "; ";

		for (int t = 0; t < (data[i].timesBetweenStops.size() - 1); t++)
			out_stream << data[i].timesBetweenStops[t] << ", ";

		out_stream << data[i].timesBetweenStops[(data[i].timesBetweenStops.size() - 1)] << endl;
	}
	out_stream.close();
}

/*
Guarda a informa��o contida no vetor de structs no ficheiro de condutores.
*/
void savingDriversData(const vector<Driver> &data)
{
	ofstream out_stream;

	out_stream.open(driversFileName);

	for (int i = 0; i < data.size(); i++)
	{
		out_stream << data[i].idNumber << " ; ";
		out_stream << data[i].name << " ; ";
		out_stream << data[i].shiftHours << " ; ";
		out_stream << data[i].maxHoursWeek << " ; ";
		out_stream << data[i].minRestHours << endl;
	}
	out_stream.close();
}

/*
Pergunta ao utilizador se pretende guardar as altera��es e age de acordo com a sua resposta.
*/
void savingChanges(vector<Line> linesData, vector<Driver> driversData)
{
	char userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout << endl << "Deseja guardar as altera��es? (S/N) : ";

		if (cin >> userChoice && (userChoice == 'S' || userChoice == 'N' || userChoice == 's' || userChoice == 'n'))
		{
			validInput = true;
			cin.ignore(1000, '\n');
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Op��o inv�lida, tente novamente..." << endl << endl;
		}
	}

	if (userChoice == 'S' || userChoice == 's')
	{
		savingDriversData(driversData);
		savingLinesData(linesData);
	}
}