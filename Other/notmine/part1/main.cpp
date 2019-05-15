/*
FICHEIRO: main.cpp
PROGRAMA: Sistema de gest�o de informa��o da empresa "SEMPRARROLAR"
DESCRI��O:
Primeiro projeto para a unidade curricular de programa��o, do 1�ano do MIEIC, na FEUP.
O objetivo � desenvolver um programa que disponibilize funcionalidades para ler dados de ficheiros e apresentar
ao utilizador v�rias informa��es �teis sobre a empresa de transportes.
AUTOR: Pedro Fernandes, 1MIEIC_02
DATA DE IN�CIO: 27-03-2017
DATA DE T�RMINO: 18-04-1017
*/

#include "myTypes.h"

//Declara��o dos nomes dos ficheiros, necess�rios em variadas fun��es
string linesFileName, driversFileName;

//Declara��o das constantes de in�cio e final dos servi�os dos autocarros
const int startingTime = 8 * 60; // 8:00
const int endingTime = 20 * 60; // 20:00

//FUN��O PRINCIPAL
int main()
{
	setPTChar(); //Permite o uso de carateres portugueses no input/output

	vector<string> rawLinesData;
	vector<string> rawDriversData;
	vector<Line> storedLinesData;
	vector<Driver> storedDriversData;

	rawLinesData = readLines(); // Come�a por ler os ficheiros para um vetor de strings
	rawDriversData = readDrivers();

	storedLinesData = storingLinesData(rawLinesData); //L� do vetor de strings para um vetor de structs adequadas
	storedDriversData = storingDriversData(rawDriversData);

	mainUserInterface(storedLinesData, storedDriversData); // Invoca a interface principal
}