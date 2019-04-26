#include "myTypes.h"
/*
Apresenta ao utilizador uma tabela formatada com o hor�rio de uma paragem. Divide o hor�rio em v�rias sec��es,
cada uma representando as horas de passagem por cada linha, indicando tamb�m qual o sentidoda linha.
*/
void stopSchedule(const vector<Line> &data)
{
	bool validInput = false;
	string stop;
	struct stopInfo
	{	//Para guardar informa��es necess�rias sobre a paragem
		int id; //Id da linha
		int frequency; //Frequencia de passagem do autocarro pela paragem
		int finalBus; //�ltima passagem do autocarro pela paragem
		int firstBus; //Primeira passagem do autocarro pela paragem
		string firstStop; //Primeira paragem da linha
		string lastStop; //�ltima paragem da linha
		vector<int> times; //Tempos de passagem do autocarro pela paragem
	}; 
	vector<stopInfo> normalDLines; //Vetor para passagens no sentido normal
	vector<stopInfo> reverseDLines; //Vetor para passagem no sentido inverso
	struct time
	{
		//Para guardar a informa��o das horas e dos minutos, visto que anteriormente apenas trabalhava com minutos
		int hours;
		double minutes;
	};

	cout << "Hor�rio de uma paragem" << endl << endl;

	while (!validInput)
	{
		cout << "Paragem: ";
		getline(cin, stop);

		if (searchStop2(data, stop) == true)
			validInput = true;
		else
			cout << "A paragem n�o foi encontrada! Tente novamente..." << endl;
	}

	for (int i = 0; i < data.size(); i++)
	{
		int finalB = startingTime;
		int totalDuration = 0;

		//Dura��o total de um percurso de uma linha
		for (int c = 0; c < data[i].timesBetweenStops.size(); c++)
			totalDuration = totalDuration + data[i].timesBetweenStops[c];

		//Tempo de passagem do �ltimo autocarro pela primeira paragem
		while (finalB + totalDuration < endingTime)
			finalB = finalB + data[i].frequency;

		for (int c = 0; c < data[i].stopsList.size(); c++)
		{
			if (data[i].stopsList[c] == stop) //Se encontrar a paragem
			{
				int firstB = startingTime;
				stopInfo stopI;

				for (int c1 = 0; c1 < c; c1++)
					firstB = firstB + data[i].timesBetweenStops[c1]; //Calcula tempo da primeira passagem pela paragem
				
				stopI.id = data[i].idNumber;
				stopI.firstStop = data[i].stopsList[0];
				stopI.lastStop = data[i].stopsList[data[i].stopsList.size() - 1];
				stopI.finalBus = finalB;
				stopI.firstBus = firstB;
				stopI.frequency = data[i].frequency;

				normalDLines.push_back(stopI);
				break; // Assume-se que uma paragem s� aparece numa linha uma vez
			}

			finalB = finalB + data[i].frequency;
		}
	}
	
	//Coloca num vetor todas as passagens das linhas pela paragem
	for (int i = 0; i < normalDLines.size(); i++)
	{
		int nextTime = normalDLines[i].firstBus;

		while (nextTime < normalDLines[i].finalBus)
		{
			normalDLines[i].times.push_back(nextTime);
			nextTime = nextTime + normalDLines[i].frequency;
		}
	}

	//Procedimento semelhante para o sentido inverso, alterando o comportamento dos contadores
	for (int i = 0; i < data.size(); i++)
	{
		int finalB = startingTime;
		int totalDuration = 0;

		for (int c = 0; c < data[i].timesBetweenStops.size(); c++)
			totalDuration = totalDuration + data[i].timesBetweenStops[c];

		while (finalB + totalDuration < endingTime)
			finalB = finalB + data[i].frequency;

		for (int c = data[i].stopsList.size() - 1; c >= 0; c--)
		{
			if (data[i].stopsList[c] == stop)
			{
				int firstB = startingTime;
				stopInfo stopI;

				for (int c1 = data[i].timesBetweenStops.size()-1; c1 >= c; c1--)
					firstB = firstB + data[i].timesBetweenStops[c1];

				stopI.id = data[i].idNumber;
				stopI.firstStop = data[i].stopsList[0];
				stopI.lastStop = data[i].stopsList[data[i].stopsList.size() - 1];
				stopI.firstBus = firstB;
				stopI.finalBus = finalB;
				stopI.frequency = data[i].frequency;

				reverseDLines.push_back(stopI);
				break;
			}

			if (c < 1) //Devido ao desfasamento entre os vetores das paragens e dos tempos
				continue;
			else
				finalB = finalB + data[i].timesBetweenStops[c - 1];
		}
	}

	for (int i = 0; i < reverseDLines.size(); i++)
	{
		int nextTime = reverseDLines[i].firstBus;

		while (nextTime < reverseDLines[i].finalBus)
		{
			reverseDLines[i].times.push_back(nextTime);
			nextTime = nextTime + reverseDLines[i].frequency;
		}
	}


	//Mostrar hor�rio

	cout << endl << "Hor�rio da paragem " << stop << endl;

	for (int i = 0; i < normalDLines.size(); i++)
	{
		cout << endl << "Linha " << normalDLines[i].id << endl;
		cout << "Sentido " << normalDLines[i].firstStop << " -> " << normalDLines[i].lastStop << endl;

		cout << setprecision(0);

		for (int c = 0; c < normalDLines[i].times.size(); c++)
		{
			int hours = minutesToHours(normalDLines[i].times[c]).hours;
			int minutes = minutesToHours(normalDLines[i].times[c]).minutes;

			//Se o n�mero for menor que 10, coloca um 0 � frente
			cout << setfill('0') << setw(2) << hours;
			cout << ":";
			cout << setfill('0') << setw(2) << minutes;
			cout << '\t';
		}

		cout << endl;
	}

	for (int i = 0; i < reverseDLines.size(); i++)
	{
		cout << endl << "Linha " << reverseDLines[i].id << endl;
		cout << "Sentido " << reverseDLines[i].lastStop << " -> " << reverseDLines[i].firstStop << endl;

		cout << setprecision(0);

		for (int c = 0; c < reverseDLines[i].times.size(); c++)
		{
			int hours = minutesToHours(reverseDLines[i].times[c]).hours;
			int minutes = minutesToHours(reverseDLines[i].times[c]).minutes;

			//Se o n�mero for menor que 10, coloca um 0 � frente
			cout << setfill('0') << setw(2) << hours;
			cout << ":";
			cout << setfill('0') << setw(2) << minutes;
			cout << '\t';
		}

		cout << endl;
	}
}

/*
Apresenta ao utilizador uma tabela formatada com o hor�rio de uma linha, depois de perguntar ao utilizador qual
o sentido que deseja visualizar. Divide o hor�rio em v�rias sec��es, cada uma representando as horas de passagem por
cada paragem da linha.
*/
void lineSchedule(const vector<Line> &data)
{
	bool validInput = false;
	int id, lineIndex, userChoice;

	cout << "Hor�rio de uma linha" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador da linha: ";

		if (cin >> id)
		{
			lineIndex = searchLineIdentifier(id, data);

			if (lineIndex != -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cout << "Esse identificador n�o existe! Tente novamente..." << endl;
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

	cout << "Selecionar sentido" << endl;
	cout << "1: " << data[lineIndex].stopsList[0] << " - " << data[lineIndex].stopsList[data[lineIndex].stopsList.size() - 1] << endl;
	cout << "2: " << data[lineIndex].stopsList[data[lineIndex].stopsList.size() - 1] << " - " << data[lineIndex].stopsList[0] << endl;

	userChoice = verifyInput(1, 2);

	if (userChoice == 1)
		normalDirection(lineIndex, data);
	else
		reverseDirection(lineIndex, data);
}

/*
Apresenta o hor�rio de uma linha no sentido normal, como colocado nos ficheiros.
*/
void normalDirection(int lineIndex, const vector<Line> &data)
{
	int totalDuration = 0;
	int finalBus;
	vector<vector<int>> timesAllStops;
	struct time //Para guardar a informa��o das horas e dos minutos, visto que anteriormente apenas trabalhava com minutos
	{
		int hours;
		double minutes;
	};

	//Calcula dura��o total de uma viagem
	for (int i = 0; i < data[lineIndex].timesBetweenStops.size(); i++)
		totalDuration = totalDuration + data[lineIndex].timesBetweenStops[i];

	finalBus = startingTime; //Inicialmente a vari�vel guarda o tempo da primeira passagem pela primeira paragem da linha

	while (finalBus + totalDuration < endingTime)
		finalBus = finalBus + data[lineIndex].frequency; //No final, tem o tempo da �ltima passagem pela primeira paragem da linha

	for (int i = 0; i < data[lineIndex].stopsList.size(); i++)
	{
		vector<int> times; // Tempos em que o autocarro passa por cada paragem
		int startingT = startingTime;
		int nextTime;

		for (int c = 0; c < i; c++)
			startingT = startingT + data[lineIndex].timesBetweenStops[c]; //Calcula tempo da 1� passagem

		nextTime = startingT;

		while (nextTime<finalBus)
		{
			times.push_back(nextTime);
			nextTime = nextTime + data[lineIndex].frequency;
		}

		timesAllStops.push_back(times);

		if (i >= data[lineIndex].timesBetweenStops.size())
			continue;
		else
			finalBus = finalBus + data[lineIndex].timesBetweenStops[i]; //Vari�vel guarda o �ltimo autocarro de cada paragem		
	}

	//Mostrar o hor�rio

	cout << endl << endl << "Hor�rio da linha " << data[lineIndex].idNumber << endl;
	cout << "Sentido " << data[lineIndex].stopsList[0] << " -> " << data[lineIndex].stopsList[data[lineIndex].stopsList.size() - 1] << endl << endl;

	for (int i = 0; i < timesAllStops.size(); i++)
	{
		cout << data[lineIndex].stopsList[i] << endl << endl;

		cout << setprecision(0);

		for (int c = 0; c < timesAllStops[i].size(); c++)
		{
			int hours = minutesToHours(timesAllStops[i][c]).hours;
			int minutes = minutesToHours(timesAllStops[i][c]).minutes;

			//Se o n�mero for menor que 10, coloca um 0 � frente
			cout << setfill('0') << setw(2) << hours;
			cout << ":";
			cout << setfill('0') << setw(2) << minutes;
			cout << '\t';
		}

		cout << endl << endl;
	}
}

/*
Apresenta o hor�rio de uma linha no sentido inverso ao do colocado nos ficheiros.
*/
void reverseDirection(int lineIndex, const vector<Line> &data)
{
	int totalDuration = 0;
	int finalBus;
	vector<vector<int>> timesAllStops;
	struct time //Para guardar a informa��o das horas e dos minutos, visto que anteriormente apenas trabalhava com minutos
	{
		int hours;
		double minutes;
	};

	//Calcula dura��o total de uma viagem
	for (int i = 0; i < data[lineIndex].timesBetweenStops.size(); i++)
		totalDuration = totalDuration + data[lineIndex].timesBetweenStops[i];

	finalBus = startingTime;

	while (finalBus + totalDuration < endingTime)
		finalBus = finalBus + data[lineIndex].frequency; 

	for (int i = data[lineIndex].stopsList.size() - 1; i >= 0; i--)
	{
		vector<int> times; // Tempos em que o autocarro passa por cada paragem
		int startingT = startingTime;
		int nextTime;

		for (int c = data[lineIndex].timesBetweenStops.size() - 1; c >= i; c--)
			startingT = startingT + data[lineIndex].timesBetweenStops[c]; //Calcula tempo da 1� passagem

		nextTime = startingT;

		while (nextTime<finalBus)
		{
			times.push_back(nextTime);
			nextTime = nextTime + data[lineIndex].frequency;
		}

		timesAllStops.push_back(times);

		if (i < 1)
			continue;
		else
			finalBus = finalBus + data[lineIndex].timesBetweenStops[i-1]; //vari�vel guarda o �ltimo autocarro de cada paragem
	}

	//Mostrar o hor�rio

	cout << endl << endl << "Hor�rio da linha " << data[lineIndex].idNumber << endl;
	cout << "Sentido " << data[lineIndex].stopsList[data[lineIndex].stopsList.size() - 1] << " -> " << data[lineIndex].stopsList[0] << endl << endl;

	for (int i = 0; i < timesAllStops.size(); i++)
	{
		cout << data[lineIndex].stopsList[data[lineIndex].stopsList.size() - 1 - i] << endl << endl;

		cout << setprecision(0);

		for (int c = 0; c < timesAllStops[i].size(); c++)
		{
			int hours = minutesToHours(timesAllStops[i][c]).hours;
			int minutes = minutesToHours(timesAllStops[i][c]).minutes;

			//Se o n�mero for menor que 10, coloca um 0 � frente
			cout << setfill('0') << setw(2) << hours;
			cout << ":";
			cout << setfill('0') << setw(2) << minutes;
			cout << "\t";
		}

		cout << endl << endl;
	}
}

/*
Recebe um tempo em minutos (normalmente a contar a partir das 00:00) e converte em horas e minutos, retornando
o resultado numa struct.
*/
Time minutesToHours(int minutes)
{
	int hours;
	double temp;
	double min;
	Time t;

	temp = (double) minutes / 60;
	min = round((temp - minutes / 60)*60);
	hours = minutes / 60;
	

	t.hours = hours;
	t.minutes = min;

	return t;
}


