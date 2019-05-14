#include "Other.h"

//Consider there are not equal names
vector<int> search_client_name(vector<Client> CL)
{
    string input_name;
    vector<int> found; 
    found.push_back(-1);
    while(found.at(0) == -1)
    {
        cout << "\nInput name: "; readline(input_name);
        for(int j=0; j < CL.size(); j++)
        {
            if(CL.at(j).name.find(input_name) != string::npos)
            {
                if(found.at(0) == -1) found.at(0) = j;
                else found.push_back(j);
           }
        }

        if(found.at(0) == -1) cout << "There isn't a client with that name.\nTry again";
    }

    return found;
}

int search_client_NIF(vector<Client> CL)
{
    string NIF_str;
    int NIF, found = -1;
    while(found == -1)
    {
        cout << "\nInput NIF: "; readline(NIF_str);
        while((stoint(NIF_str, NIF) != 0))
        {
            cout << "Try again. Just numbers, please: ";
            readline(NIF_str);
        }

        for(int i=0; i < CL.size(); i++)
        {
           if(NIF == CL.at(i).NIF) 
           {
              found = i;
              break;
           }
        }

        if(found == -1) cout << "There isn't a client with that NIF. Try again";
    }

    return found;
}


//use with if( f() != -1 )
int search_pack_ID(vector<Pack> PK)
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


void print_client(vector<Client> CL, int i)
{
    string div = " | ";
    cout << "==== CLIENT " << i << " =====\n";
    cout << left << setw(20) << "Name: " << CL.at(i).name << "\n";
    cout << left << setw(20) << "NIF: " << CL.at(i).NIF << "\n";
    cout << left << setw(20) << "Ppl in FamAgr: " << CL.at(i).nFamAgr << "\n";
    cout << left << setw(20) << "Address: " << CL.at(i).address.street
         << div  << CL.at(i).address.doorNumber
         << div  << CL.at(i).address.floor
         << div  << CL.at(i).address.CP
         << div  << CL.at(i).address.location << "\n";
    cout << left << setw(20) << "Packs bought: " << CL.at(i).packs_str << "\n\n\n";
}

void print_all_clients(vector<Client> CL)
{
    clearScreen();
    string div = " | ";
    cout << "LISTING CLIENTS\n\n";
    for(int i=0; i<CL.size(); i++)
    {
        cout << "==== CLIENT " << i << " =====\n";
        cout << left << setw(20) << "Name: " << CL.at(i).name << "\n";
        cout << left << setw(20) << "NIF: " << CL.at(i).NIF << "\n";
        cout << left << setw(20) << "Ppl in FamAgr: " << CL.at(i).nFamAgr << "\n";
        cout << left << setw(20) << "Address: " << CL.at(i).address.street
             << div  << CL.at(i).address.doorNumber
             << div  << CL.at(i).address.floor
             << div  << CL.at(i).address.CP
             << div  << CL.at(i).address.location << "\n";
        cout << left << setw(20) << "Packs bought: " << CL.at(i).packs_str << "\n\n\n";
    }
}

void print_all_packs(vector<Pack> PK)
{
    clearScreen();
    string div = " | ";
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