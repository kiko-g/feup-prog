#include "defs.h"
#include "Menus.h"
using namespace std;


// ===== CLIENT =====
// ADD CLIENT
void addClient(Agency &agency)
{
    bool valid = false;
    cout << "Adding Client" << "\n\n";
    
    string name; // name of the client
    unsigned VATnumber; // VAT number of client
    unsigned short familySize;  // number of family members
    
    string street; // street name
    unsigned short doorNumber; // door number
    string Floor; // Floor number ("-" is not applicable)
    string postalCode; // postal code
    string location; // site

    vector<unsigned int> packs; // vector to store client's packs bought
    unsigned  totalPurchased; // total value spent by the client

    //READ THE CLIENT
    cout << "Name: "; readline(name);
    cout << "NIF: "; cin >> VATnumber; while(!cin_test()) cin >> VATnumber;
    cout << "Number of members in household: "; cin >> familySize;
    cout << "Street name: "; readline(street);
    cout << "Door number: "; cin >> doorNumber; while(!cin_test()) cin >> doorNumber;
    cout << "Floor info: "; cin >> Floor; while(!cin_test()) cin >> Floor;
    cout << "Postal Code: "; readline(postalCode);
    cout << "Location: "; readline(location);

    int j=0, packn, cond;
    ostringstream packstring;
    string divider = " ; ";
    
    cout << "\n=== CLIENT PACKS ===";   
    cout << "\nTotal number of packs: ";    
    cin >> cond;                            

    while (!cin.eof() && j<cond)
    {
        if(j!=0) packstring << divider;
        j++;
        cout << "Pack " << j << ": "; cin >> packn; 
        packs.push_back(packn);
        if(!cin.eof()) packstring << packn;
    }

    totalPurchased = agency.determineMoneySpentByClient(packs);

    Address address(street, doorNumber, Floor, postalCode, location);
    Client c(name, VATnumber, familySize, address, packs, totalPurchased);
    agency.addClients(c);
    cout << "Client successfully added.\n"; 
}

//EDIT CLIENT
void changeClientName(Agency &agency)
{
    // DEC_WHICH ---> DECIDE WHICH OF THE FOUND CLIENTS (IN vpos aka c_list)
    string new_name; 
    int pos;
    vector<int> vpos;
    cout << "\nNew name: "; readline(new_name);
    cout << "\n\n==== SEARCH CLIENT NAME ====\n";
    //decide_search(); ---> soon
    vpos = searchClientName(agency);
    agency.changeClientName(vpos, new_name);
}

void changeClientNIF(Agency &agency)
{
    int pos, new_NIF = 0;
    vector<int> vpos;
    string new_NIFstr;

    cout << "\n\n==== SEARCHING WITH NAME ====\n";
    vpos = searchClientName(agency);
    cout << "\nNew NIF: "; readline(new_NIFstr);

    //STOINT IS DECLARED IN HELPFUL.CPP AND ALTERS THE VALUE OF new_NIF
    while (stoint(new_NIFstr, new_NIF) != 0)
    {
        cout << "New NIF input is invalid.\nTry again, this time only numbers\nNew NIF: ";
        readline(new_NIFstr);
        break;
    }
    agency.changeClientNIF(vpos, new_NIF);
}

void changeClientFamagr(Agency &agency)
{
    int pos, dec_which;
    vector<int> vpos;
    int new_NFA;
    cout << "\n\n==== SEARCH WITH NAME ====\n";
    vpos = searchClientName(agency);
    cout << "\nNew fam agr number: "; cin >> new_NFA; while(!cin_test()) cin >> new_NFA;
    agency.changeClientFAM(vpos, new_NFA);
}

void changeClientAddress(Agency &agency)
{
    int pos, dec_which;
    vector<int> vpos;
    string div = " | ";
    Address new_address;
    
    //ADDRESS COMPONENTS ---> These will be read from input
    string street, Floor, location;
    unsigned short CP1, CP2, doorNumber;

    cout << "\nType new address below\n\n";
    cout << left << setw(20) << "STREET: "; readline(street); new_address.setStreet(street);
    cout << left << setw(20) << "\nDOOR NUMBER: "; cin >> doorNumber; while(!cin_test()) cin >> doorNumber; new_address.setDoorNumber(doorNumber);
    cout << left << setw(20) << "\nFloor: "; readline(Floor); new_address.setFloor(Floor);
    cout << left << setw(20) << "\nPOSTAL CODE N1: "; cin >> CP1; while(!cin_test()) cin >> CP1;
    cout << left << setw(20) << "\nPOSTAL CODE N2: "; cin >> CP2; while(!cin_test()) cin >> CP2;
    ostringstream helpful_str;
    helpful_str << CP1 << "-" << CP2;
    new_address.setPostalCode(helpful_str.str());
    cout << left << setw(20) << "\nLOCATION: "; readline(location); new_address.setLocation(location);

    cout << "\n\n==== SEARCH ====\n";
    vpos = searchClientName(agency);
    for (int j=0; j < vpos.size(); j++)
    {
       cout << CL.at(vpos.at(j)).name << " | ADDRESS: "
            << CL.at(vpos.at(j)).address.street     << div
            << CL.at(vpos.at(j)).address.doorNumber << div
            << CL.at(vpos.at(j)).address.Floor      << div
            << CL.at(vpos.at(j)).address.CP         << div
            << CL.at(vpos.at(j)).address.location   << "\n";
    }

    cout << "\nSelect which client's ADDRESS you wish to change\n";
    dec_which = validateInterfaceInput(1, vpos.size());
    CL.at(vpos.at(dec_which - 1)).address.street = new_address.street;
    CL.at(vpos.at(dec_which - 1)).address.doorNumber = new_address.doorNumber;
    CL.at(vpos.at(dec_which - 1)).address.Floor = new_address.Floor;
    CL.at(vpos.at(dec_which - 1)).address.CP = new_address.CP;
    CL.at(vpos.at(dec_which - 1)).address.location = new_address.location;
    
}

void changeClientPacks(Agency agency)
{
    int pos, dec_which;
    vector<int> vpos;
    string new_name;
    cout << "\nNew name: "; readline(new_name);
    cout << "\n\n==== SEARCH ====\n";

    vpos = searchClientName(CL);
    for (int j = 0; j < vpos.size(); j++)
    {
       cout << CL.at(vpos.at(j)).name << "\n";
    }

    cout << "\nSelect which one you wish to delete\n";
    dec_which = validateInterfaceInput(1, vpos.size());
    CL.at(vpos.at(dec_which - 1)).name = new_name;
}

void editClient(Agency agency)
{
	int input, which;
	bool valid = false;
    while(1)
    {
        clearScreen();
        cout << "Altering client" << "\n\n";
        cout << "\n" << "== Choose what you wish to alter ==" << "\n\n"; 
        cout << "1 - Change name" << "\n";
        cout << "2 - Change NIF" << "\n";
        cout << "3 - Change Fam Agr Size" << "\n";
        cout << "4 - Change address" << "\n\n";
        cout << "5 - Back" << "\n\n";

        input = validateInterfaceInput(1, 5);
        switch(input)
        {
            case 1:
            changeClientName(CL);
            break;

            case 2:
            changeClientNIF(CL);
            break;
            
            case 3:
            changeClientFamagr(CL);            
            break;

            case 4:
            changeClientAddress(CL);            
            break;

            case 5:
            return;
        }
        writeClients(CL, clients_file);
    }
}

*/
// REMOVE CLIENT
void removeClient(Agency agency)
{
	int input, which, pos;
    vector<int> vpos;
	bool valid = false;
    while(1)
    {
        clearScreen();
        cout << "\n Removing client" << "\n\n";  
        cout << "| 1 - Search\n| 2 - Back\n\n"; 

        input = validateInterfaceInput(1, 2);
        switch(input)
        {
            case 1:
            cout << "\n\n==== SEARCH ====\n| Type 1 for NAME search.\n| Any other input will trigger NIF search: "; cin >> which;
            if (which == 1) 
            {
               int delwhich;
               vpos = searchClientName(CL);
               for(int j=0; j<vpos.size(); j++)
               {
                  cout << CL.at(vpos.at(j)).name << "\n";
               }    
               cout << "\nSelect which one you wish to delete: [1-" << vpos.size() << "]: ";
               delwhich = validateInterfaceInput(1, vpos.size());
               CL.erase(CL.begin() + vpos.at(delwhich-1));
            }
            else 
            {
               pos = searchClientNIF(CL);
               CL.erase(CL.begin() + pos);
            }
            break;


            case 2:
            return;
        }
    writeClients(CL, clients_file);
    }
}




// ===== PACKS ======

void addPack(Agency agency)
{
    Pack p;
    cout << "Adding Pack" << "\n\n";

    //CIN ONCE | THEN TEST | THEN CIN WHILE INVALID
    cout << "Pack ID: ";                    cin >> p.id;                while(!cin_test()) cin >> p.id;
    cout << "Destination: ";                readline(p.destination);
    cout << "== Start Date == \nYear: ";    cin >> p.startDate.year;    while(!cin_test()) cin >> p.startDate.year;
    cout << "Month: ";                      cin >> p.startDate.month;   while(!cin_test()) cin >> p.startDate.month;
    cout << "Day: ";                        cin >> p.startDate.day;     while(!cin_test()) cin >> p.startDate.day; 
    cout << "== End Date == \nYear: ";      cin >> p.startDate.year;    while(!cin_test()) cin >> p.startDate.year;
    cout << "Month: ";                      cin >> p.startDate.month;   while(!cin_test()) cin >> p.startDate.month;
    cout << "Day: ";                        cin >> p.startDate.day;     while(!cin_test()) cin >> p.startDate.day;
    cout << "Price per person: ";           cin >> p.price_pp;          while(!cin_test()) cin >> p.price_pp;
    cout << "Available seats: ";            cin >> p.availableSeats;    while(!cin_test()) cin >> p.availableSeats;
    cout << "Sold seats: ";                 cin >> p.soldSeats;         while(!cin_test()) cin >> p.soldSeats;

    PK.push_back(p);

    writePacks(PK, packs_file);
    cout << "Pack successfully added.\n"; 
}


void editPack(Agency agency)
{
	int input, which;
	bool valid = false;
    while(1)
    {
        clearScreen();
        cout << "Altering client" << "\n\n";
        cout << "\n" << "== Choose what you wish to alter ==" << "\n\n"; 
        cout << "1 - Change ID" << "\n";
        cout << "2 - Change Destination" << "\n";
        cout << "3 - Change Web URL" << "\n";
        cout << "4 - Change address" << "\n\n";
        cout << "5 - Back" << "\n\n";

        input = validateInterfaceInput(1, 5);
        switch(input)
        {
            case 1:
            cout << "Type 1 for name search. Any other input will trigger NIF search: "; cin >> which;
            //changeClientName(CL);
            break;

            case 5:
            return;
        }
    }
    writePacks(PK, packs_file);
}

void removePack(Agency agency)
{
	int input, pos;
	bool valid = false;
    while(1)
    {
        clearScreen();
        cout << "\n Removing pack" << "\n\n";  
        cout << "| 1 - Search\n| 2 - Back\n\n"; 

        input = validateInterfaceInput(1, 2);
        switch(input)
        {
            case 1:
            cout << "\n\n==== SEARCH ====\n";
            pos = searchPack_ID(PK);
            PK.erase(PK.begin() + pos);
            break;

            case 2:
            return;
        }
    }
    writePacks(PK, packs_file);
}


void purchasePack(Agency agency)
{
	int P_ID, input, pos, again;
    vector<int> vpos;
    int dec_which;  // DEC_WHICH ---> DECISE WHICH OF THE FOUND CLIENTS (IN vpos)
    
    while(1)
    {
        clearScreen();
        cout << "\n==== Purchasing pack for a client ====" << "\n";
        cout << "| First search for the client then type what pack he wants to get.\n\n";
        
        cout << "| 1 - Search client\n| 2 - Back\n\n"; 
        input = validateInterfaceInput(1, 2);

        switch(input)
        {
            case 1:
            cout << "\n\n==== SEARCH CLIENT ====\n";
            //decide_search(); ---> soon 
            vpos = searchClientName(CL);
            for(int j = 0; j < vpos.size(); j++)
            {
                cout << CL.at(vpos.at(j)).name << " | Packs bought: " << CL.at(vpos.at(j)).packs_str << "\n";
            }
            cout << "\nSelect which client will buy the pack\n";
            dec_which = validateInterfaceInput(1, vpos.size());

            cout << "\n| Type the ID of the pack the client wants to purchase\n";

            P_ID = searchPack_ID(PK);
            while(PK.at(P_ID).id < 0) 
            {
                cout << "Sorry, that pack is not available anymore. You can still add a different pack.\n"
                    << "| 1 - Continue searching for a pack\n| 2 - Backout of pack shopping :(\n";
                again = validateInterfaceInput(1, 2);
                switch(again)
                {
                    case 1:
                    break;
                    case 2:
                    return;
                }
                P_ID = searchPack_ID(PK);
            }
            CL.at(vpos.at(dec_which-1)).packs.push_back(PK.at(P_ID).id);
            CL.at(vpos.at(dec_which-1)).packs_str += " ; " + to_string(PK.at(P_ID).id);
            break;

            case 2:
            return;
        }
        writeClients(CL, clients_file);
    }
}

void determinePacks_money(Agency agency)
{
    float total_money=0, total_sold=0;
    for(int i=0; i<PK.size(); i++)
    {
        total_sold += PK.at(i).soldSeats;
        total_money += (PK.at(i).soldSeats * PK.at(i).pricePp);
    }

    cout << endl;
    cout << left << setw(35) << "\nTotal of packs sold: " << total_sold;
    cout << left << setw(35) << "\nTotal income from packs sold: " << total_money << "\n\n";
}