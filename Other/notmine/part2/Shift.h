#pragma once

#include <vector>

using namespace std;


class Shift{
 private:
  unsigned int busLineId;
  unsigned int driverId;  
  unsigned int busOrderNumber; 
  unsigned int startTime; 
  unsigned int endTime;   

 public:
  Shift(unsigned int busLineId, unsigned int driverId, unsigned int busNumber, unsigned int startTime, unsigned int endTime);
  Shift(unsigned int line, unsigned int bus, unsigned int start, unsigned int end);
  // get methdos
  unsigned int getBusLineId() const;
  unsigned int getDriverId() const;
  unsigned int getBusOrderNumber() const; // order of the bus within the bus line
  unsigned int getStartTime() const;
  unsigned int getEndTime() const;

  //  set methods
  void setBusLineId(unsigned int newLineID);
  void setDriverId(unsigned int newDriverID);
  void setBusOrderNumber(unsigned int newBusOrderNumber);
  void setStartTime(unsigned int newStartTime);
  void setEndTime(unsigned int newEndTime);

  // other methods
    void showInfo() const;
	void showInitialInfo() const;
};
