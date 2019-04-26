#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

//Estruturas para guardar informa�ao sobre as linhas e condutores

typedef struct
{
	int idNumber;
	int frequency;
	vector<string> stopsList;
	vector<int> timesBetweenStops;
} Line;

typedef struct
{
	int lineID;
	int shiftBegin;
	int shiftEnd;
} Shift;

typedef struct
{
	int idNumber;
	string name;
	int shiftHours;
	int maxHoursWeek;
	int minRestHours;
	bool availability;
	vector<Shift> shifts;
} Driver;

typedef struct
{
	int hours;
	int minutes;
} Time;


//Possibilita o uso do nome dos ficheiros de texto em v�rios ficheiros de c�digo
extern string linesFileName, driversFileName;

//Constantes para indicar o momento de �nicio e fim dos servi�os dos autocarros
extern int const startingTime, endingTime;

//Fun��o para limpar a consola, independentemente do sistema operativo
#ifdef _WIN32
#define clearScreen() system("cls");
#else
#define clearScreen() system("clear");
#endif


//Fun��o para possibilitar o uso de carateres portugueses caso o sistema operativo seja o windows
#ifdef _WIN32
	#include <windows.h>
	#define setPTChar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else
	#define setPTChar() void
#endif


//DECLARA��O DAS FUN��ES

//Gest�o de linhas
void createLine(vector<Line> &data);
void editLine(vector<Line> &data);
void removeLine(vector<Line> &data);
void changeFrequency(int id, vector<Line> &data);
void removeStop(int id, vector<Line> &data);
void addStop(int id, vector<Line> &data);
void changeStop(int id, vector<Line> &data);
void changeDuration(int id, vector<Line> &data);

//Gest�o de condutores
void createDriver(vector<Driver> &data);
void editDriver(vector<Driver> &data);
void removeDriver(vector<Driver> &data);
void changeShift(int id, vector<Driver> &data);
void changeMaxHours(int id, vector<Driver> &data);
void changeMinRest(int id, vector<Driver> &data);
void changeName(int id, vector<Driver> &data);
void setAvailability(vector<Driver> &data);
void showShifts(vector<Driver> &data);

//Interfaces
void mainUserInterface(vector<Line> linesData, vector<Driver> driversData);
void linesInterface(vector<Line> linesData, vector<Driver> driversData);
void driversInterface(vector<Line> linesData, vector<Driver> driversData);
void schedulesInterface(vector<Line> linesData, vector<Driver> driversData);
void searchInterface(vector<Line> linesData, vector<Driver> driversData);
void quitOrContinue(vector<Line> linesData, vector<Driver> driversData);

//Gest�o de input
int verifyInput(int low, int high);

//Leitura de informa��o
vector<string> readLines();
vector<string> readDrivers();
vector<Line> storingLinesData(const vector<string> &data);
vector<Driver> storingDriversData(const vector<string> &data);

//Guardar altera��es
void savingLinesData(const vector<Line> &data);
void savingDriversData(const vector<Driver> &data);
void savingChanges(vector<Line> linesData, vector<Driver> driversData);

//Hor�rios
void stopSchedule(const vector<Line> &data);
void lineSchedule(const vector<Line> &data);
void normalDirection(int lineIndex, const vector<Line> &data);
void reverseDirection(int lineIndex, const vector<Line> &data);
Time minutesToHours(int minutes);

//Pesquisa
void searchStop(const vector<Line> &data);
bool searchStop2(const vector<Line> &data, string stop);
bool searchStop3(const vector<Line> &data, int lineIndex, string stop);
void routeCalculator(const vector<Line> &data);
void availableDrivers(vector<Driver> &data);
int searchLineIdentifier(int id, const vector<Line> &data);
int searchDriverIdentifier(int id, const vector<Driver> &data);