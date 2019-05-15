#pragma once

#include <string>
#include <vector>

#include "Shift.h"


using namespace std;

class Driver{
 private:
  unsigned int id;
  string name;
  unsigned int maxHours;        // maximum duration of a shift
  unsigned int maxWeekWorkingTime;  // maximum number of hours of work in a week
  unsigned int minRestTime;     // minimum number of rest hours between shifts
  vector<Shift> shifts;         // assigned shifts
 public:
  Driver(string textLine);
  Driver(unsigned int id, string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime);
  // get methods
  unsigned int getId() const;
  string getName() const;
  unsigned int getShiftMaxDuration() const;
  unsigned int getMaxWeekWorkingTime() const;
  unsigned int getMinRestTime() const;
  vector<Shift> getShifts() const;
  //setmethods
  void setName(string newName);
  void setShiftMaxDuration(unsigned int newShiftMaxDuration);
  void setMaxWeekWorkingTime(unsigned int newMaxWeekWorkingTime);
  void setMinRestTime(unsigned int newMinRestTime);
  void addShift(Shift s);

  // outher methods
  void checkCompleteService() const;
};
