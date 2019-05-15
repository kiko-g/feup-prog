#include "Driver.h"
#include "Time.h"
#include <algorithm>
#include <iostream>

Driver::Driver(string textLine){
  //RECOLHER O ID
  int firstPos = 0;

  int semicolonPos = textLine.find(";", firstPos);

  string ids = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int idN = stoi(ids);

  id = idN;


  //RECOLHER O NOME
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string name = textLine.substr(firstPos, semicolonPos - firstPos - 1);

  this->name = name;

  // RECOLHER O TURNO
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string shiftS = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int shiftN = stoi(shiftS);

  maxHours = shiftN;


  //RECOLHER O NUMERO MAX DE HORAS
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string maxHoursW = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int maxHoursN = stoi(maxHoursW);

  maxWeekWorkingTime = maxHoursN;

  //RECOLHER O NUMERO DE HORAS DE DESCANSO
  firstPos = semicolonPos + 2;

  string restHours = textLine.substr(firstPos);
  unsigned int restHoursN = stoi(restHours);

  minRestTime = restHoursN;
}

Driver::Driver(unsigned int id, string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime)
{
	this->id = id;
	this->name = name;
	this->maxHours = maxHours;
	this->maxWeekWorkingTime = maxWeekWorkingTime;
	this->minRestTime = minRestTime;
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return shifts;
}

/////////////////
// set methods //
/////////////////
void Driver::setName(string newName)
{
	name = newName;
}
void Driver::setShiftMaxDuration(unsigned int newShiftMaxDuration)
{
	maxHours = newShiftMaxDuration;
}
void Driver::setMaxWeekWorkingTime(unsigned int newMaxWeekWorkingTime)
{
	maxWeekWorkingTime = newMaxWeekWorkingTime;
}
void Driver::setMinRestTime(unsigned int newMinRestTime)
{
	minRestTime = newMinRestTime;
}

bool shiftSortHelper(const Shift &x, const Shift &y)
{
	return x.getStartTime() < y.getStartTime();
}

void Driver::addShift(Shift s)
{
	shifts.push_back(s);

	sort(shifts.begin(), shifts.end(),shiftSortHelper); //Garantir que os turnos estao ordenados
}

/*
Verifica se o condutor atingiu o servico maximo semanal, e caso contrario, lista os periodos sem trabalho atribuido.
*/
void Driver::checkCompleteService() const
{
	int totalTime=0;
	int const startingTime = 6 * 60;
	int const endingTime = 19 * 60;
	int counter = 1;
	int const numDays = 5;

	for (int i = 0; i < shifts.size(); i++){
		totalTime += shifts[i].getEndTime() - shifts[i].getStartTime(); }


	if (totalTime < maxWeekWorkingTime*60)
	{
		if (totalTime == 0)
		{
			for (int i = 0; i < numDays; ++i)
			{
				cout << "Periodo " << (i + 1) << endl;

				cout << "Tempo inicial: ";
				showTime(convertMinHours(startingTime + i*24*60));
				cout << "Tempo final: ";
				showTime(convertMinHours(endingTime +  i*24* 60)) ;
				cout << endl;
			}
		}
		else if(shifts.size()==1)
		{
			int min1 = shifts.at(0).getStartTime();
			int min2 = shifts.at(0).getEndTime();
			int numPeriods;

			if (convertMinHours(min1).hours == convertMinHours(startingTime).hours && convertMinHours(min1).minutes ==
																					  convertMinHours(
																							  startingTime).minutes) //Se o turno comecar no inicio do dia
			{
				numPeriods = 5;

				for (int i = 0; i < numPeriods; i++) 
				{
					cout << "Periodo " << (i + 1) << endl;

					if (convertMinHours(min1).numberOfDay == i) //O periodo a mostrar e o que segue o turno
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(min2));
						cout << "Tempo final: ";
						showTime(convertMinHours(endingTime + i * 24 * 60));
						cout << endl;
					}
					else //Senao, significa que o periodo corresponde a outro dia
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(startingTime + i * 24 * 60));
						cout << "Tempo final: ";
						showTime(convertMinHours(endingTime + i * 24 * 60));
						cout << endl;
					}
				}
			} else if (convertMinHours(min2).hours == convertMinHours(endingTime).hours &&
					   convertMinHours(min2).minutes ==
					   convertMinHours(endingTime).minutes) //Se o turno for o ultimo do dia
			{
				numPeriods = 5;

				for (int i = 0; i < numPeriods; i++)
				{
					cout << "Periodo " << (i + 1) << endl;

					if (convertMinHours(min1).numberOfDay == i) //O periodo a mostrar e o que antecede o turno
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(startingTime + i * 24 * 60));
						cout << "Tempo final: ";
						showTime(convertMinHours(min2));
						cout << endl;
					}
					else //Senao, significa que o periodo corresponde a outro dia
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(startingTime + i * 24 * 60));
						cout << "Tempo final: ";
						showTime(convertMinHours(endingTime + i * 24 * 60));
						cout << endl;
					}
				}
			}
			else //Se o turno for no meio do dia
			{
				numPeriods = 6;

				for (int i = 0; i < numPeriods; i++)
				{
					cout << "Periodo " << (i + 1) << endl;

					if (convertMinHours(min1).numberOfDay == i)
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(startingTime + i * 24 * 60));
						cout << "Tempo final: ";
						showTime(convertMinHours(min1));
						cout << endl;
					}
					else if (i>0 && convertMinHours(min1).numberOfDay == i - 1) //O mesmo dia tera dois periodos livres
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(min2));
						cout << "Tempo final: ";
						showTime(convertMinHours(endingTime + (i - 1) * 24 * 60));
						cout << endl;
					}
					else if (i>0)
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(startingTime + (i - 1) * 24 * 60));
						cout << "Tempo final: ";
						showTime(convertMinHours(endingTime + (i - 1) * 24 * 60));
						cout << endl;
					}
					else
					{
						cout << "Tempo inicial: ";
						showTime(convertMinHours(startingTime + i * 24 * 60));
						cout << "Tempo final: ";
						showTime(convertMinHours(endingTime + i * 24 * 60));
						cout << endl;
					}

				}
			}

		}
		else //Existem varios turnos, logo e necessario calcular os periodos entre os mesmos, e caso existam os periodos ate ao primeiro turno e depois do ultimo
		{
		int counter = 1;

		//Primeiro periodo (ate o inicio do primeiro turno)

		int min1 = shifts.at(0).getStartTime();
		int min2 = shifts.at(0).getEndTime();

		if (convertMinHours(min1).hours == convertMinHours(startingTime).hours && convertMinHours(min1).minutes == convertMinHours(startingTime).minutes)
			for (int i = 0; i < convertMinHours(min1).numberOfDay; i++)
			{
				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(min2));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		else if (convertMinHours(min2).hours == convertMinHours(endingTime).hours && convertMinHours(min2).minutes == convertMinHours(endingTime).minutes)
			for (int i = 0; i <= convertMinHours(min1).numberOfDay; i++)
			{

				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		else
			for (int i = 0; i <= convertMinHours(min1).numberOfDay; i++)
			{
				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}

			}


		//Periodos entre os turnos
		for (int i = 0; i < shifts.size() - 1; i++)
		{
			int min3 = shifts.at(i).getEndTime();
			int min4 = shifts.at(i + 1).getStartTime();

			if (convertMinHours(min3).numberOfDay == convertMinHours(min4).numberOfDay) //Se os dois turnos forem no mesmo dia
			{
				cout << "Periodo: " << counter << endl;
				counter++;
				cout << "Tempo inicial: ";
				showTime(convertMinHours(min3));
				cout << "Tempo final: ";
				showTime(convertMinHours(min4));
				cout << endl;
			}
			else //se forem em dias diferentes, ha varios periodos a mostrar
			{	//Desde o fim do primeiro turno ate ao fim do dia
				cout << "Periodo: " << counter << endl;
				counter++;
				cout << "Tempo inicial: ";
				showTime(convertMinHours(min3));
				cout << "Tempo final: ";
				showTime(convertMinHours(endingTime + convertMinHours(min3).numberOfDay * 24 * 60));
				cout << endl;

				//dias que existam entretanto
				for (int c = convertMinHours(min3).numberOfDay + 1; c<convertMinHours(min4).numberOfDay; c++)
				{
					cout << "Periodo: " << counter << endl;
					counter++;
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + c * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + c * 24 * 60));
					cout << endl;
				}

				//Desde o inicio do dia do segundo turno ate ao inicio deste
				cout << "Periodo: " << counter << endl;
				counter++;
				cout << "Tempo inicial: ";
				showTime(convertMinHours(startingTime + convertMinHours(min4).numberOfDay * 24 * 60));
				cout << "Tempo final: ";
				showTime(convertMinHours(min4));
				cout << endl;
			}
		}

		//Ultimo turno (depois do fim do ultimo turno)

		int min5 = shifts.at(shifts.size() - 1).getStartTime();
		int min6 = shifts.at(shifts.size() - 1).getEndTime();

		if (convertMinHours(min5).hours == convertMinHours(startingTime).hours && convertMinHours(min5).minutes == convertMinHours(startingTime).minutes)
			for (int i = convertMinHours(min5).numberOfDay; i <= (numDays-1); i++)
			{
				if (i == convertMinHours(min5).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(min6));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		else if (convertMinHours(min6).hours == convertMinHours(endingTime).hours && convertMinHours(min6).minutes == convertMinHours(endingTime).minutes)
			for (int i = convertMinHours(min5).numberOfDay; i < (numDays-1); i++)
			{
				if (i == convertMinHours(min5).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min5));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}

		else
			for (int i = convertMinHours(min5).numberOfDay; i <= (numDays-1); i++)
			{
				if (i == convertMinHours(min5).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(min6));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}

			}
		}
	}
	else
		cout << "O condutor atingiu o tempo maximo semanal!" << endl;
}


