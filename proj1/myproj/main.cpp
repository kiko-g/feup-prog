#include "Agency.h"
#include "Menus.h"
// #include "utils.h"

int main()
{
    Agency agency(AGENCY_FILE_NAME); // create the agency

    mainMenu(agency); // initial menu inicial with the major options of the application

    return 0;
}

/*
#include "myLib.h"
using namespace std;

string pathToFile = "textfiles/";
string limit = "::::::::::";
string clients_file;
string packs_file;
string clients_file2 = "clientsnew.txt";
string packs_file2 = "packsnew.txt";

int main()
{
    //RAW STORAGE
    vector<string> raw_agency, raw_clients, raw_packs;
    raw_agency = read_agency();
    raw_clients = read_clients(raw_agency.at(4));    //clients.txt
    raw_packs = read_packs(raw_agency.at(5));        //packs.txt

    
    //DECOMPOSITION
    Agency agency_pure;
    vector<Client> clients_pure;
    vector<Pack> packs_pure;
    agency_pure = decompose_agency(raw_agency);                      //AGENCY
    clients_file = raw_agency.at(4);
    clients_pure = decompose_clients(raw_clients, clients_file);     //CLIENTS
    packs_file = raw_agency.at(5);
    packs_pure = decompose_packs(raw_packs, packs_file);             //PACKS

    init_navigation(clients_pure, packs_pure);
}
Text files are in a folder called 'textfiles' inside the 'myproj' folder
*/