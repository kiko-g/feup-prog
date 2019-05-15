#include <iostream>
#include <iomanip>
#include <vector>
#include "Time.h"

using namespace std;

//associado aos horários
void showMIN(int time) {
    if (time < 10)
        cout <<  setfill('0') << setw(2);}


void dealWITHtime(int &horas, int &minutos){
    while (minutos >= 60){
        horas++;
        minutos -= 60;
    }
}
//util para formaração dos horarios
int verificarLENGTHparagemMAIOR(vector<string> busStops){
    int i=0;
    for (int j = 0; j < busStops.size(); ++j) {
        if(busStops.at(j).length()>i)
            i=busStops.at(j).length();
    }
    return i;
}

/*
Recebe uma hora representada em minutos e devolve uma struct que a representa em horas, minutos, e dia da semana.
*/
Time convertMinHours(int minutes)
{
    int hours;
    int min;
	int num;
	double min2;
    string dayOfWeek;
    Time t;
    double temp;

    if(minutes>=0 && minutes<24*60) {
		num = 0;
        dayOfWeek = "Segunda";
		min = minutes;
    }
    else if(minutes<2*24*60) {
		num = 1;
        dayOfWeek = "Terca";
		min = minutes - 24*60;
    }
    else if(minutes<3*24*60){
		num = 2;
        dayOfWeek="Quarta";
		min = minutes - 2*24*60;
	}
    else if(minutes<4*24*60){
		num = 3;
        dayOfWeek="Quinta";
		min = minutes - 3*24*60;
	}
    else if(minutes<5*24*60){
		num = 4;
        dayOfWeek="Sexta";
		min = minutes - 4*24*60;
	}


	temp = (double)min / 60;
	hours = min / 60;
	min2 = ((temp - min / 60) * 60);

    t.hours=hours;
    t.minutes=min2;
    t.dayOfWeek=dayOfWeek;
	t.numberOfDay = num;

	return t;
}

/*
Mostra uma hora representada em horas,minutos e dia da semana.
*/
void showTime(Time t){
    cout << setprecision(0);

    cout << setfill('0') << setw(2) << t.hours;
    cout << ":";
    cout << setfill('0') << setw(2) << t.minutes;
    cout << " - ";
    cout << t.dayOfWeek << endl;
}

/*
Faz o inverso da funcao acima.
*/
int convertHoursMin(Time t) {
	int min;

	if (t.dayOfWeek == "Segunda")
		min = (t.hours * 60 + t.minutes) + 0 * 24 * 60;
	else if (t.dayOfWeek == "Terca")
		min = (t.hours * 60 + t.minutes) + 1 * 24 * 60;
	else if (t.dayOfWeek == "Quarta")
		min = (t.hours * 60 + t.minutes) + 2 * 24 * 60;
	else if (t.dayOfWeek == "Quinta")
		min = (t.hours * 60 + t.minutes) + 3 * 24 * 60;
	else if (t.dayOfWeek == "Sexta")
		min = (t.hours * 60 + t.minutes) + 4 * 24 * 60;


	return min;
}