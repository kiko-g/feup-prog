#pragma once

#include <string>

using namespace std;


typedef struct {
	int hours;
	int numberOfDay;
	double minutes;
	string dayOfWeek;
} Time;

Time convertMinHours(int minutes);
int convertHoursMin(Time t);
void showTime(Time t);
