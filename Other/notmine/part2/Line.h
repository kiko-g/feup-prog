#pragma once

#include <vector>
#include <string>
#include "bus.h"

using namespace std;

class Line{
 private:
  unsigned int id;
  unsigned int frequency;
  vector<string> busStopList;
  vector<int> timesList;
  vector<Bus> buses;
 public:
  Line(string textLine);
  Line(unsigned int id, unsigned int frequency, vector<string> busStopsList, vector<int> timesList);
  // metodos get
  unsigned int getId() const;
  unsigned int getFrequency() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  vector<Bus> getBuses() const;
  // set methods
  void setFrequency(unsigned int newFrequency);
  void setBusStops(vector<string> newStopsList);
  void setTimings(vector<int> newTimings);
  void setBus(vector<Bus> newBus);
  // other methods
  int numberOfBuses() const;
  int totalDuration() const;
  bool searchStop(string stop) const;
  int searchStop2(string stop) const;
  void schedule() const;
  void stopsSchedule(string stop) const;
  void horarioPARAGEMlilhelper(string stop, int i) const;
  void busesInf(unsigned int busOrder);
  int searchBusOrderNumber(unsigned int order) const;
  void busesChecker() const;
}; 
