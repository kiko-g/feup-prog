#include "Company.h"
#include "Time.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

Company::Company(string name, string linesFile, string driversFile) {

	linesFileName = linesFile;
	driversFileName = driversFile;
	serviceStartingTime = 6 * 60;
	serviceEndingTime = 19 * 60;

	//LER DOS FICHEIROS PARA STRINGS
	ifstream in_stream;
	string line;
	vector<string> linesFileContent;

	in_stream.open(linesFileName);

	if (in_stream.fail())
	{
		cerr << "Ficheiro das linhas nao encontrado. Fechando o programa..." << endl;
		exit(1);
	}

	while (!in_stream.eof())
	{
		getline(in_stream, line);
		if (line == "")
			continue;
		linesFileContent.push_back(line);
	}

	cout << "Conteudos lidos!" << endl << endl;

	in_stream.close();

	vector<string> driversFileContent;


	in_stream.open(driversFileName);

	if (in_stream.fail())
	{
		cerr << "Ficheiro dos condutores nao encontrado. Fechando o programa..." << endl;
		exit(1);
	}

	while (!in_stream.eof())
	{
		getline(in_stream, line);
		if (line == "")
			continue;
		driversFileContent.push_back(line);
	}

	cout << "Conteudos lidos!" << endl << endl;

	in_stream.close();

	//Ler das strings para os vetores de informacao

	vector<Line> linesVector;

	for (int i = 0; i < linesFileContent.size(); i++)
	{
		Line l(linesFileContent[i]);
		linesVector.push_back(l);
	}

	vector<Driver> driversVector;

	for (int i = 0; i < driversFileContent.size(); i++)
	{
		Driver d(driversFileContent[i]);
		driversVector.push_back(d);
	}


	this->name = name;
	lines = linesVector;
	drivers = driversVector;

	//Construir o vetor com os turnos a atribuir aos autocarros para toda a semana (um turno equivale a uma viagem de ida e volta)

	for (int days = 0; days < 5; days++)
	{
		for (int i = 0; i < lines.size(); i++)
		{
			unsigned int bus = 1;
			unsigned int start = serviceStartingTime + 24 * 60 * days;
			unsigned int end = start + 2 * lines[i].totalDuration();
			vector<Shift> temp;

			//Cria os primeiros turnos, associados aos diferentes autocarros necessarios
			while (bus <= lines[i].numberOfBuses())
			{
				Shift s(lines[i].getId(), bus, start, end);
				temp.push_back(s);

				bus++;
				start += lines[i].getFrequency();
				end = start + 2 * lines[i].totalDuration();
			}

			//Para cada autocarro, cria os turnos que tem que percorrer ate ao final do servico
			for (int c = 0; c < temp.size(); c++)
			{
				start = temp[c].getStartTime();
				end = temp[c].getEndTime();

				while (start < serviceEndingTime + 24 * 60 * days)
				{
					Shift s(temp[c].getBusLineId(), temp[c].getBusOrderNumber(), start, end);
					busShifts.push_back(s);

					start += lines[i].numberOfBuses()*lines[i].getFrequency();
					end = start + 2 * lines[i].totalDuration();
				}
			}
		}
	}
}

////////////////////////////////
// metodos get
///////////////////////////////
string Company::getName() const {
	return name;
}

vector<Line> Company::getLines() const
{
	return lines;
}

vector<Driver> Company::getDrivers() const
{
	return drivers;
}

unsigned int Company::getStartingTime() const
{
	return serviceStartingTime;
}

unsigned int Company::getEndingTime() const
{
	return serviceEndingTime;
}

vector<Shift> Company::getBusShifts() const
{
	return busShifts;
}

//////////////////////////////
// metodos set
/////////////////////////////

void Company::setDrivers(vector<Driver> newDrivers)
{
	drivers = newDrivers;
}

void Company::addDriver(Driver newDriver)
{
	drivers.push_back(newDriver);
}

void Company::removeDriver(int index)
{
	drivers.erase(drivers.begin() + index);
}

void Company::removeShift(int index)
{
	busShifts.erase(busShifts.begin() + index);
}

////////////////////////////
// outros metodos
///////////////////////////

/*
Aloca servi�o aos condutores e autocarros, recebendo a informa��o necess�ria (que antes j� � verificada se consiste
com os turnos a atribuir) e verifica a consist�ncia com os dados do condutor que deseja atribuir. Caso seja inconsistente,
n�o atribui o trabalho. Incoveniente: apenas atribui trabalho de forma sequencial, ou seja, nao permite que se atribua um turno
anterior aos que ja se encontram no vetor de turnos do condutor.
*/
void Company::allocateService(unsigned int driverId, unsigned int busOrderNumber, unsigned int busLineId, unsigned int startTime, unsigned int endTime) {

	int totalTime = 0;
	int consecutiveTime = 0;
	int const interval = 30;

	//Calcular o tempo total de trabalho do condutor
	for (int i = 0; i < drivers[searchDriverIdentifier(driverId)].getShifts().size(); i++)
		totalTime += drivers[searchDriverIdentifier(driverId)].getShifts()[i].getEndTime() - drivers[searchDriverIdentifier(driverId)].getShifts()[i].getStartTime();

	for (int i = drivers[searchDriverIdentifier(driverId)].getShifts().size() - 1; i > 0; i--)
	{
		//Verifica se os turnos sao consecutivos, para isso arbitra-se que o sao se come�arem 30 minutos depois do turno anterior terminar e guarda o tempo consecutivo 
		if (drivers[searchDriverIdentifier(driverId)].getShifts()[i - 1].getEndTime() < drivers[searchDriverIdentifier(driverId)].getShifts()[i].getStartTime() - interval)
			consecutiveTime += (drivers[searchDriverIdentifier(driverId)].getShifts()[i].getEndTime() - drivers[searchDriverIdentifier(driverId)].getShifts()[i].getStartTime()) + (drivers[searchDriverIdentifier(driverId)].getShifts()[i - 1].getEndTime() - drivers[searchDriverIdentifier(driverId)].getShifts()[i - 1].getStartTime());
		else
			break;
	}

	//Se nao existir qualquer turno, entao nao existe qualquer restri�ao e pode-se atribuir o trabalho
	if (drivers[searchDriverIdentifier(driverId)].getShifts().size() == 0)
	{
		//Atribui o turno ao condutor
		Shift s(busLineId, driverId, busOrderNumber, startTime, endTime);
		drivers[searchDriverIdentifier(driverId)].addShift(s);

		//Atribui o condutor ao autocarro
		vector<Bus> newB = lines[searchLineIdentifier(busLineId)].getBuses();
		newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].addShift(s);
		newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].setDriverId(driverId);

		lines[searchLineIdentifier(busLineId)].setBus(newB);

		cout << "Turno atribuido!" << endl;

		//Remove o turno da lista dos turnos a atribuir
		removeShift(searchShift(busOrderNumber, busLineId, startTime, endTime));
	}
	// Se o tempo total for inferior ao tempo maximo de trabalho semanal
	else if (totalTime < drivers[searchDriverIdentifier(driverId)].getMaxWeekWorkingTime() * 60)
	{
		if (convertMinHours(startTime).dayOfWeek == convertMinHours(drivers[searchDriverIdentifier(driverId)].getShifts().at(drivers[searchDriverIdentifier(driverId)].getShifts().size() - 1).getEndTime()).dayOfWeek)
			if (startTime >= drivers[searchDriverIdentifier(driverId)].getShifts().at(drivers[searchDriverIdentifier(driverId)].getShifts().size() - 1).getEndTime())  //Se o turno for posterior ao ultimo turno atribuido
			{
				//Se o turno a atribuir e o ultimo atribuido forem consecutivos
				if (startTime - interval < drivers[searchDriverIdentifier(driverId)].getShifts()[drivers[searchDriverIdentifier(driverId)].getShifts().size() - 1].getEndTime())
				{
					consecutiveTime += endTime-startTime;
					//Se o tempo consecutivo for menor que o tempo maximo de horas consecutivas do condutor
					if (consecutiveTime < drivers[searchDriverIdentifier(driverId)].getShiftMaxDuration())
					{
						Shift s(busLineId, driverId, busOrderNumber, startTime, endTime);
						drivers[searchDriverIdentifier(driverId)].addShift(s);

						vector<Bus> newB = lines[searchLineIdentifier(busLineId)].getBuses();
						newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].addShift(s);
						newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].setDriverId(driverId);

						lines[searchLineIdentifier(busLineId)].setBus(newB);

						cout << "Turno atribuido!" << endl;

						removeShift(searchShift(busOrderNumber, busLineId, startTime, endTime));
					}
					else
						cout << "Numero maximo de horas seguidas de trabalho atingido!" << endl;
				}
				else //Se o turno a atribuir e o ultimo atribuido nao forem consecutivos, mas tiverem uma diferen�a maior ao periodo minimo de descanso
					if (startTime - drivers[searchDriverIdentifier(driverId)].getMinRestTime() * 60 > drivers[searchDriverIdentifier(driverId)].getShifts()[drivers[searchDriverIdentifier(driverId)].getShifts().size() - 1].getEndTime())
					{
						Shift s(busLineId, driverId, busOrderNumber, startTime, endTime);
						drivers[searchDriverIdentifier(driverId)].addShift(s);

						vector<Bus> newB = lines[searchLineIdentifier(busLineId)].getBuses();
						newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].addShift(s);
						newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].setDriverId(driverId);

						lines[searchLineIdentifier(busLineId)].setBus(newB);

						cout << "Turno atribuido!" << endl;

						removeShift(searchShift(busOrderNumber, busLineId, startTime, endTime));
					}
					else
						cout << "Numero minimo de horas de descanso entre turnos nao esta de acordo!" << endl;
			}
			else //Garantir que o turno nao coincide com outros ja atribuidos
				cout << "Nao e possivel atribuir o turno" << endl;
		else //Se os turnos sao em dias diferentes, nao ha qualquer problema
		{
			//Atribui o turno ao condutor
			Shift s(busLineId, driverId, busOrderNumber, startTime, endTime);
			drivers[searchDriverIdentifier(driverId)].addShift(s);

			//Atribui o condutor ao autocarro
			vector<Bus> newB = lines[searchLineIdentifier(busLineId)].getBuses();
			newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].addShift(s);
			newB[lines[searchLineIdentifier(busLineId)].searchBusOrderNumber(busOrderNumber)].setDriverId(driverId);

			lines[searchLineIdentifier(busLineId)].setBus(newB);

			cout << "Turno atribuido!" << endl;

			//Remove o turno da lista dos turnos a atribuir
			removeShift(searchShift(busOrderNumber, busLineId, startTime, endTime));
		}
	}
	else
		cout << "Numero total de horas de trabalho semanal atingido! Nao e possivel atribuir trabalho a este condutor." << endl;
}

/*
Procura a existencia de uma linha no vetor de classes, dado o ID. Caso exista, devolve o indice da linha.
Caso contrario, devolve -1.
*/
int Company::searchLineIdentifier(unsigned int id) const
{
	int found = -1;

	for (int i = 0; i < lines.size(); i++)
		if (lines[i].getId() == id)
		{
			found = i;
			break;
		}

	return found;
}

/*
Procura a existencia de um condutor no vetor de classes, dado o ID. Caso exista, devolve o indice do condutor.
Caso contrario, devolve -1.
*/
int Company::searchDriverIdentifier(unsigned int id) const
{
	int found = -1;

	for (int i = 0; i < drivers.size(); i++)
		if (drivers[i].getId() == id)
		{
			found = i;
			break;
		}

	return found;
}

/*
Guarda a informacao contida no vetor de Lines no ficheiro de linhas.
*/
void Company::savingLinesData() const
{
	ofstream out_stream;

	out_stream.open(linesFileName);

	for (int i = 0; i < lines.size(); i++)
	{
		out_stream << lines[i].getId() << " ; ";
		out_stream << lines[i].getFrequency() << " ; ";

		for (int j = 0; j < lines[i].getBusStops().size(); j++)
		{
			if (j > 0)
				out_stream << ", ";
			out_stream << lines[i].getBusStops()[j];
		}

		out_stream << "; ";

		for (int t = 0; t < lines[i].getTimings().size(); t++)
		{
			if (t > 0)
				out_stream << ", ";
			out_stream << lines[i].getTimings()[t];
		}

		out_stream << endl;
	}

	out_stream.close();
}

/*
Guarda a informacao contida no vetor de Drivers no ficheiro de condutores.
*/
void Company::savingDriversData() const
{
	ofstream out_stream;

	out_stream.open(driversFileName);

	for (int i = 0; i < drivers.size(); i++)
	{
		out_stream << drivers[i].getId() << " ; ";
		out_stream << drivers[i].getName() << " ; ";
		out_stream << drivers[i].getShiftMaxDuration() << " ; ";
		out_stream << drivers[i].getMaxWeekWorkingTime() << " ; ";
		out_stream << drivers[i].getMinRestTime() << endl;
	}
	out_stream.close();
}

/*
Esta struct e a funcao a seguir sao uteis para, na funcao de calcular um percurso, se poder ordenar os varios percursos
por duracao.
*/

typedef struct {
	int ID; //Identifica o percurso
	int duration;
}durationHelper;

bool sortHelper(const durationHelper& x, const durationHelper& y)
{
	return x.duration < y.duration;
}

/*
Recebe duas paragens do utilizador e procura-as nas linhas existentes. Devolve todos os percursos possiveis,
sendo que se admite que ha, no maximo, um transbordo. Tambem funciona para o caso de nao existir.
*/
void Company::routeCalculator(string stop1, string stop2) const
{
	typedef struct {
		int lineIndex;
		int stopIndex;
	} stopInfo;

	typedef struct {
		vector<string> stops;
		int ID; //Identifica o percurso, util para coordenar com a struct durationHelper
		int lineID;
		int duration;
	}sameLineRoute;

	typedef struct {
		string commonStop;
		int ID; //Identifica o percurso, util para coordenar com a struct durationHelper
		int line1ID;
		vector<string> line1stops;
		vector<string> line2stops;
		int line2ID;
		int duration;
	}difLineRoute;

	typedef struct {
		int line1StopIndex;
		int line2StopIndex;
		string stop;
	}commonStopInfo;

	vector<durationHelper> durHelper;
	vector<difLineRoute> difLineRoutes;
	vector<sameLineRoute> sameLineRoutes;
	vector<stopInfo> info; //Para guardar informacoes sobre a paragem inicial

						   //Procurar a paragem inicial
	for (int i = 0; i < lines.size(); i++)
		for (int j = 0; j < lines[i].getBusStops().size(); j++)
			if (lines[i].getBusStops()[j] == stop1)
			{
				stopInfo stopI;
				stopI.lineIndex = i;
				stopI.stopIndex = j;

				info.push_back(stopI);
			}


	//Procurar a paragem final
	for (int i = 0; i < lines.size(); i++)
		for (int j = 0; j < lines[i].getBusStops().size(); j++)
			if (lines[i].getBusStops()[j] == stop2)
				for (int c = 0; c < info.size(); c++)
					if (info[c].lineIndex == i) //Paragens estao na mesma linha
					{
						sameLineRoute route;
						durationHelper dH;
						route.duration = 0;

						if (j > info[c].stopIndex)
						{
							for (int c1 = 0; c1 <= (j - info[c].stopIndex); c1++)
								route.stops.push_back(lines[i].getBusStops()[info[c].stopIndex + c1]);

							for (int c2 = 0; c2 < (j - info[c].stopIndex); c2++)
								route.duration += lines[i].getTimings()[info[c].stopIndex + c2];
						}
						else
						{
							for (int c1 = 0; c1 <= (info[c].stopIndex - j); c1++)
								route.stops.push_back(lines[i].getBusStops()[info[c].stopIndex - c1]);

							for (int c2 = 0; c2 < (info[c].stopIndex - j); c2++)
								route.duration += lines[i].getTimings()[j + c2];
						}

						route.ID = c;
						route.lineID = lines[i].getId();
						sameLineRoutes.push_back(route);
						dH.duration = route.duration;
						dH.ID = c;
						durHelper.push_back(dH);
					}
					else //Paragens estao em linhas diferentes
					{
						vector<commonStopInfo> commonStopsInfo;

						//Procurar paragens comuns
						for (int c1 = 0; c1 < lines[info[c].lineIndex].getBusStops().size(); c1++)
							for (int c2 = 0; c2 < lines[i].getBusStops().size(); c2++)
							{
								if (lines[info[c].lineIndex].getBusStops()[c1] == lines[i].getBusStops()[c2])
								{
									commonStopInfo cSI;

									string common = lines[info[c].lineIndex].getBusStops()[c1];

									if (common != stop1 && common != stop2)
									{
										cSI.line1StopIndex = c1;
										cSI.line2StopIndex = c2;
										cSI.stop = common;

										commonStopsInfo.push_back(cSI);
									}
								}

							}

						for (int c3 = 0; c3 < commonStopsInfo.size(); c3++)
						{
							difLineRoute dLR;
							durationHelper dH;

							dLR.commonStop = commonStopsInfo[c3].stop;
							dLR.line1ID = lines[info[c].lineIndex].getId();
							dLR.duration = 0;
							dLR.line2ID = lines[i].getId();

							if (commonStopsInfo[c3].line1StopIndex > info[c].stopIndex)
							{
								for (int c4 = 0; c4 <= (commonStopsInfo[c3].line1StopIndex - info[c].stopIndex); c4++)
									dLR.line1stops.push_back(lines[info[c].lineIndex].getBusStops()[info[c].stopIndex + c4]);

								for (int c5 = 0; c5 < (commonStopsInfo[c3].line1StopIndex - info[c].stopIndex); c5++)
									dLR.duration += lines[info[c].lineIndex].getTimings()[info[c].stopIndex + c5];
							}
							else
							{
								for (int c4 = 0; c4 <= (info[c].stopIndex - commonStopsInfo[c3].line1StopIndex); c4++)
									dLR.line1stops.push_back(lines[info[c].lineIndex].getBusStops()[info[c].stopIndex - c4]);

								for (int c5 = 0; c5 < (info[c].stopIndex - commonStopsInfo[c3].line1StopIndex); c5++)
									dLR.duration += lines[info[c].lineIndex].getTimings()[commonStopsInfo[c3].line1StopIndex + c5];
							}

							if (j > commonStopsInfo[c3].line2StopIndex)
							{
								for (int c4 = 0; c4 <= (j - commonStopsInfo[c3].line2StopIndex); c4++)
									dLR.line2stops.push_back(lines[i].getBusStops()[commonStopsInfo[c3].line2StopIndex + c4]);

								for (int c5 = 0; c5 < (j - commonStopsInfo[c3].line2StopIndex); c5++)
									dLR.duration += lines[i].getTimings()[commonStopsInfo[c3].line2StopIndex + c5];
							}
							else
							{
								for (int c4 = 0; c4 <= (commonStopsInfo[c3].line2StopIndex - j); c4++)
									dLR.line2stops.push_back(lines[i].getBusStops()[commonStopsInfo[c3].line2StopIndex - c4]);

								for (int c5 = 0; c5 < (commonStopsInfo[c3].line2StopIndex - j); c5++)
									dLR.duration += lines[i].getTimings()[j + c5];
							}

							dLR.ID = info.size() + 1 + c3;
							dH.duration = dLR.duration;
							dH.ID = dLR.ID;
							durHelper.push_back(dH);
							difLineRoutes.push_back(dLR);
						}

					}


	sort(durHelper.begin(), durHelper.end(), sortHelper); //Ordenar o vetor por ordem de dura�ao

														  //Mostrar os percursos

	if (durHelper.size() == 0)
		cout << "Nao foi encontrado qualquer percurso!" << endl;
	else
	{
		if (durHelper.size() > 1)
			cout << endl << "Foram encontrados " << durHelper.size() << " percursos" << endl;
		else
			cout << endl << "Existe um unico percurso" << endl << endl;

		for (int i = 0; i < durHelper.size(); i++)
		{
			if (durHelper.size() > 1)
				cout << endl << "Percurso " << i + 1 << endl;

			//Procurar o tipo de percurso e mostra-lo

			for (int c = 0; c < sameLineRoutes.size(); c++)
			{
				if (durHelper[i].ID == sameLineRoutes[c].ID)
				{
					cout  << "|" << left << setw(10) << "Linha: "  <<  sameLineRoutes[c].lineID << endl << right;
					cout  << "|" << left << setw(10) << "Paragens: "  << right;

					for (int c1 = 0; c1 < sameLineRoutes[c].stops.size(); c1++)
					{
						if (c1 > 0)
							cout << " -> ";
						cout << sameLineRoutes[c].stops[c1];
					}

					cout << endl << "|" << left << setw(10) << "Duracao:  " << sameLineRoutes[c].duration << " minutos" << endl << right << endl;
				}
			}

			for (int c = 0; c < difLineRoutes.size(); c++)
			{
				if (durHelper[i].ID == difLineRoutes[c].ID)
				{
					cout <<"|" << left << setw(10) <<  "Linha 1: "  << difLineRoutes[c].line1ID << endl<<right;
					cout <<"|" << left << setw(10) << "Paragens: " << right;

					for (int c1 = 0; c1 < difLineRoutes[c].line1stops.size(); c1++)
					{
						if (c1 > 0)
							cout << " -> ";
						cout << difLineRoutes[c].line1stops[c1];
					}

					cout << endl << endl << "Transbordo em: " << difLineRoutes[c].commonStop << endl << endl;
					cout <<"|" << left << setw(10) <<  "Linha 2: " << difLineRoutes[c].line2ID << endl << right;
					cout <<"|" << left << setw(10) <<  "Paragens: "<< right;


					for (int c1 = 0; c1 < difLineRoutes[c].line2stops.size(); c1++)
					{
						if (c1 > 0)
							cout << " - ";
						cout << difLineRoutes[c].line2stops[c1];
					}

					cout << endl << "|" << left << setw(10) << "Duracao:  " << difLineRoutes[c].duration << " minutos" << endl << right;
				}
			}
		}
	}

}

/*
Recebe uma paragem, e "devolve" as linhas em que se encontra, funcionando tambem para o caso de nao existir.
*/
void Company::searchStop(string stop) const
{
	vector<int> foundLines;

	//Guarda num vetor os identificadores das linhas que contiverem a paragem indicada
	for (int i = 0; i < lines.size(); i++)
		if (lines[i].searchStop(stop))
			foundLines.push_back(lines[i].getId());

	if (foundLines.size() == 0)
		cout << "A paragem nao se encontra em nenhuma linha!" << endl;
	else
	{
		cout << "A paragem encontra-se na(s) linha(s): ";

		for (int c = 0; c < foundLines.size(); c++)
		{
			if (c > 0)
				cout << ", ";
			cout << foundLines[c];
		}
		cout << endl;
	}
}


//Recebe uma paragem, e devolve on indices do em que se encontra num vetor
vector<int> Company::searchStop2(string stop) const
{
	vector<int> foundLines;

	for (int i = 0; i < lines.size(); i++)
		if (lines[i].searchStop(stop))
			foundLines.push_back(i);

	return foundLines;

}

/*
Procura um turno de autocarro no vetor, e devolve o seu indice caso exista, senao devolve -1.
*/
int Company::searchShift(unsigned int busOrderNumber, unsigned int busLineId, unsigned int startTime, unsigned int endTime)const
{
	for (int i = 0; i < busShifts.size(); i++)
	{
		if (busShifts[i].getBusLineId() == busLineId &&busShifts[i].getBusOrderNumber() == busOrderNumber && busShifts[i].getStartTime() == startTime && busShifts[i].getEndTime() == endTime)
			return i;
	}

	return -1;
}

/*
Mostra uma lista com todos os periodos de todos os autocarros sem condutor atribuido.
*/
void Company::checkBuses() const
{
	for (int i = 0; i < lines.size(); i++)
	{
		cout << "Linha: " << lines.at(i).getId() << endl;

		lines.at(i).busesChecker();
	}
}

/*
Mostra uma lista com todos os periodos sem trabalho de todos os condutores que nao atingiram o limite maximo semanal
*/
void Company::checkAvailableDrivers() const
{
	for (int i = 0; i < drivers.size(); i++)
	{
		cout << "Condutor: " << drivers.at(i).getName() << " || ID: " << drivers.at(i).getId() << endl;

		drivers.at(i).checkCompleteService();
	}
}