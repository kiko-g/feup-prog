#include "Shift.h"
#include <iostream>
#include "Time.h"

Shift::Shift(unsigned int busLineId, unsigned int driverId, unsigned int busNumber, unsigned int startTime, unsigned int endTime) {

	this->busLineId = busLineId;
	this->driverId = driverId;
	busOrderNumber = busNumber;
	this->startTime = startTime;
	this->endTime = endTime;
}

Shift::Shift(unsigned int line, unsigned int bus, unsigned int start, unsigned int end) {
	busLineId = line;
	busOrderNumber = bus;
	startTime = start;
	endTime = end;
}

// metodos get
unsigned int Shift::getBusLineId() const{
  return busLineId;
}

unsigned int Shift::getDriverId() const{
  return driverId;
}
unsigned int Shift::getBusOrderNumber() const{
  return busOrderNumber;
}

unsigned int Shift::getStartTime() const{
  return startTime;
}

unsigned int Shift::getEndTime() const{
  return endTime;
}

///////////////
// set methods
//////////////

void Shift::setBusLineId(unsigned int busLineId){
  this->busLineId = busLineId;
}

void Shift::setDriverId(unsigned int driverId){
  this->driverId = driverId;
}

void Shift::setBusOrderNumber(unsigned int busOrderNumber){
  this->busOrderNumber = busOrderNumber;
}

void Shift::setStartTime(unsigned int startTime){
  this->startTime = startTime;
}

void Shift::setEndTime(unsigned int endTime){
  this->endTime = endTime;
}

// other methods

/*
Mostra informacao sobre um turno.
*/
void Shift::showInfo() const {
  cout << "ID da linha: " << busLineId << endl;
  cout << "ID do condutor: " << driverId << endl;
  cout << "Numero de ordem do autocarro: " << busOrderNumber << endl;
  cout << "Hora de inicio: ";
  showTime(convertMinHours(startTime));
  cout << "Hora de fim: ";
  showTime(convertMinHours(endTime));
 }

/*
Mostra informaçao sobre um turno, quando este nao tem condutor atribuido
*/
void Shift::showInitialInfo() const {
	cout << "ID da linha: " << busLineId << endl;
	cout << "Numero de ordem do autocarro: " << busOrderNumber << endl;
	cout << "Hora de inicio: ";
	showTime(convertMinHours(startTime));
	cout << "Hora de fim: ";
	showTime(convertMinHours(endTime));
}