#include <string>
#include "Company.h"
#include <iostream>

using namespace std;

void mainUserInterface(Company &company);

int main(){

    string linesFileName,  driversFileName;

	cout << "Ficheiro das linhas: ";
	getline(cin, linesFileName);

	cout << "Ficheiro dos condutores: ";
	getline(cin, driversFileName);




	Company SRL("SEMPRAROLAR", linesFileName, driversFileName);


	mainUserInterface(SRL); //Invoca a interface principal


	return 0;
}
