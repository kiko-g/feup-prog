#include "defs.h"

//Consider there are not equal names
vector<int> searchClientName(Agency agency)
{
    string input_name;
    cout << "\nSearching client name\nInput name: "; readline(input_name);
    return agency.searchClientName(input_name);
}

int searchClientNIF(Agency agency)
{
    string NIF_str;
    int NIF;
    cout << "\nInput NIF: "; readline(NIF_str);
    while((stoint(NIF_str, NIF) != 0))
    {
        cout << "Try again. Just numbers, please: ";
        readline(NIF_str);
    }
    agency.searchClientNIF(NIF);
}


//use with if( f() != -1 )
int searchPackID(vector<Pack> PK)
{
    string ID_str;
    int id, found = -1;
    while(found == -1)
    {
        cout << "\n(Input) Pack ID: "; readline(ID_str);
        while((stoint(ID_str, id) != 0))
        {
            cout << "Try again. Just numbers, please: ";
            readline(ID_str);
        }

        for(int i=0; i < PK.size(); i++)
        {
           if(id == PK.at(i).id) 
           {
              found = i;
              break;
           }
        }

        if(found == -1) cout << "There isn't a pack with that ID. Try again";
    }
    return found;
}


void printClient(vector<Client> CL, int i)
{
    string divi = " | ";
    cout << "==== CLIENT " << i << " =====\n";
    cout << left << setw(20) << "Name: " << CL.at(i).name << "\n";
    cout << left << setw(20) << "NIF: " << CL.at(i).NIF << "\n";
    cout << left << setw(20) << "Ppl in FamAgr: " << CL.at(i).nFamAgr << "\n";
    cout << left << setw(20) << "Address: " << CL.at(i).address.street
         << divi  << CL.at(i).address.doorNumber
         << divi  << CL.at(i).address.floor
         << divi  << CL.at(i).address.CP
         << divi  << CL.at(i).address.location << "\n";
    cout << left << setw(20) << "Packs bought: " << CL.at(i).packs_str << "\n\n\n";
}

void printAllClients(vector<Client> CL)
{
    clearScreen();
    string divi = " | ";
    cout << "LISTING CLIENTS\n\n";
    for(int i=0; i<CL.size(); i++)
    {
        cout << "==== CLIENT " << i << " =====\n";
        cout << left << setw(20) << "Name: " << CL.at(i).name << "\n";
        cout << left << setw(20) << "NIF: " << CL.at(i).NIF << "\n";
        cout << left << setw(20) << "Ppl in FamAgr: " << CL.at(i).nFamAgr << "\n";
        cout << left << setw(20) << "Address: " << CL.at(i).address.street
             << divi  << CL.at(i).address.doorNumber
             << divi  << CL.at(i).address.floor
             << divi  << CL.at(i).address.CP
             << divi  << CL.at(i).address.location << "\n";
        cout << left << setw(20) << "Packs bought: " << CL.at(i).packs_str << "\n\n\n";
    }
}

void printAllPacks(vector<Pack> PK)
{
    clearScreen();
    string divi = " | ";
    cout << "LISTING PACKS\n\n";
    for (int i = 0; i < PK.size(); i++)
    {
        cout << "==== PKIENT " << i << " =====\n";
        cout << left << setw(25) << "ID: "                  << PK.at(i).id << "\n";
        cout << left << setw(25) << "Destination: "         << PK.at(i).destination << "\n";
        cout << left << setw(25) << "Start Date: "          << PK.at(i).startDate.day << "/" << PK.at(i).startDate.month << "/" << PK.at(i).startDate.year << "\n";
        cout << left << setw(25) << "End Date: "            << PK.at(i).endDate.day << "/" << PK.at(i).endDate.month << "/" << PK.at(i).endDate.year << "\n";
        cout << left << setw(25) << "Price per person: "    << PK.at(i).price_pp << "\n";
        cout << left << setw(25) << "Available Seats: "     << PK.at(i).price_pp << "\n";
        cout << left << setw(25) << "Sold Seats: "          << PK.at(i).price_pp << "\n\n\n";
    }
}