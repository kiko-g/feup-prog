#pragma once

#include "Line.h"
#include "Driver.h"

using namespace std;

class Company{
private:
    string name;
    vector<Driver> drivers;
    vector<Line> lines;
	string linesFileName;
	string driversFileName;
	unsigned int serviceStartingTime;
	unsigned int serviceEndingTime;
	vector<Shift> busShifts;
public:
    Company(string name, string linesFile, string driversFile);
    // metodos get
    string getName() const;
	vector<Driver> getDrivers() const;
	vector<Line> getLines() const;
	unsigned int getStartingTime() const;
	unsigned int getEndingTime() const;
	vector<Shift> getBusShifts() const;
    // metodos set
	void setDrivers(vector<Driver> newDrivers);
	void addDriver(Driver newDriver);
	void removeDriver(int index);
	void removeShift(int index);
    // outros metodos
    void allocateService(unsigned int driverId, unsigned int busOrderNumber, unsigned int busLineId, unsigned int startTime, unsigned int endTime); // funcao que implementa a afectacao de servico
	void routeCalculator(string stop1, string stop2) const;
	void searchStop(string stop) const;
	vector<int> searchStop2(string stop) const;
	int searchLineIdentifier(unsigned int id) const;
	int searchDriverIdentifier(unsigned int id) const;
	void savingLinesData() const;
	void savingDriversData() const;
	int searchShift(unsigned int busOrderNumber, unsigned int busLineId, unsigned int startTime, unsigned int endTime) const;
	void checkAvailableDrivers() const;
	void checkBuses() const;
};
