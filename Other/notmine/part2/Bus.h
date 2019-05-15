#pragma once

#include <vector>

#include "Shift.h"

using namespace std;

class Bus{
 private:
  unsigned int orderInLine;
  unsigned int driverId;
  unsigned int lineId;
  vector<Shift> schedule;
 public:
  Bus(unsigned int order, unsigned int driver, unsigned int line);
  Bus(unsigned int order, unsigned int line);
  // get methods
  unsigned int getBusOrderInLine() const;
  unsigned int getDriverId() const;
  unsigned int getLineId() const;
  vector<Shift> getSchedule() const;
  // set methods
    void setDriverId(unsigned int newdriverID);
	void setLineId(unsigned int newLineID);
  // other methods
    void showInfo() const;
	void addShift(Shift s);
	void checkBus() const;
};
