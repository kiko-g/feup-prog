#include "defs.h"

using namespace std;


// ===== CLIENT =====
// ADD CLIENT
void add_client(Agency agency)
{

    bool valid = false;
    cout << "Adding Client" << "\n\n";
    
    string name; // name of the client
    unsigned VATnumber; // VAT number of client
    unsigned short familySize;  // number of family members
    
    string street; // street name
    unsigned short doorNumber; // door number
    string floor; // floor number ("-" is not applicable)
    string postalCode; // postal code
    string location; // site

    vector<unsigned int> packets; // vector to store client's packets bought
    unsigned  totalPurchased; // total value spent by the client
    while(!valid)
    {
        cout << "Name: "; readline(name);
        cout << "NIF: "; cin >> VATnumber; while(!cin_test()) cin >> VATnumber;
        cout << "Number of members in household: "; cin >> familySize;
        cout << "Street name: "; readline(street);
        cout << "Door number: "; cin >> doorNumber; while(!cin_test()) cin >> doorNumber;
        cout << "Floor info: "; cin >> floor; while(!cin_test()) cin >> floor;
        cout << "Postal Code: "; readline(postalCode);
        cout << "Location: "; readline(location);

        int j=0, packn, cond;
        string divider = " ; ";
        ostringstream packstring;
     
        cout << "\n=== CLIENT   PACKS ===";   
        cout << "\nTotal number of packs: ";    
        cin >> cond;                            

        while (!cin.eof() && j<cond)
        {
            if(j!=0) packstring << divider;
            j++;
            cout << "Pack " << j << ": "; cin >> packn; 
            packets.push_back(packn);
            if(!cin.eof()) packstring << packn;
        }
        valid = true;
    }
    
    Address address(street, doorNumber, floor, postalCode, location);
    Client c(name, VATnumber, familySize, address, packets, 0);
    agency.addClients(c);
    cout << "Client successfully added.\n"; 
}

/*
//EDIT CLIENT
void change_client_name(Agency agency)
{
    // DEC_WHICH ---> DECISE WHICH OF THE FOUND CLIENTS (IN vpos)
    int pos, dec_which;
    vector<int> vpos;
    string new_name; 
    cout << "\nNew name: "; readline(new_name);
    cout << "\n\n==== SEARCH ====\n";
    //decide_search(); ---> soon 
    vpos = search_client_name(CL); 
    //
    for (int j = 0; j < vpos.size(); j++)
    {
       cout << CL.at(vpos.at(j)).name << "\n";
    }
    cout << "\nSelect which client's name you wish to change\n";
    dec_which = validate_interface_input(1, vpos.size());
    //
    CL.at(vpos.at(dec_which - 1)).name = new_name;
}

void change_client_NIF(Agency agency)
{
    int pos, dec_which;
    vector<int> vpos;
    string new_NIFstr;
    int new_NIF = 0;

    cout << "\nNew NIF: "; readline(new_NIFstr);
    cout << "\n\n==== SEARCH ====\n";

    vpos = search_client_name(CL);
    for (int j = 0; j < vpos.size(); j++)
    {
       cout << CL.at(vpos.at(j)).name << " | NIF: "
            << CL.at(vpos.at(j)).NIF << "\n";
    }

    cout << "\nSelect which client's NIF you wish to change\n";
    dec_which = validate_interface_input(1, vpos.size());
    //STOINT IS DECLARED IN HELPFUL.CPP AND ALTERS THE VALUE OF new_NIF
    while(stoint(new_NIFstr, new_NIF)!=0)
    {
        cout << "New NIF input is invalid.\nTry again, this only numbers\nNew NIF: ";
        readline(new_NIFstr);
        break;
    }

    CL.at(vpos.at(dec_which - 1)).NIF = new_NIF;
}

void change_client_famagr(Agency agency)
{
    int pos, dec_which;
    vector<int> vpos;
    int new_NFA;
    cout << "\nNew fam agr number: "; cin >> new_NFA; while(!cin_test()) cin >> new_NFA;
    cout << "\n\n==== SEARCH ====\n";

    vpos = search_client_name(CL);
    for (int j=0; j < vpos.size(); j++)
    {
        cout << CL.at(vpos.at(j)).name << " | N FAM AGR: "
             << CL.at(vpos.at(j)).nFamAgr << "\n";
    }

    cout << "\nSelect which client's Family Agregate Number you wish to change\n";
    dec_which = validate_interface_input(1, vpos.size());
    CL.at(vpos.at(dec_which - 1)).nFamAgr = new_NFA;
}

void change_client_address(Agency agency)
{
    int pos, dec_which;
    vector<int> vpos;
    string div = " | ";
    Address new_address; 

    cout << "\nType new address below\n\n";
    cout << left << setw(20) << "STREET: "; readline(new_address.street);
    cout << left << setw(20) << "\nDOOR NUMBER: "; cin >> new_address.doorNumber; while(!cin_test()) cin >> new_address.doorNumber;
    cout << left << setw(20) << "\nFLOOR: "; readline(new_address.floor);
    cout << left << setw(20) << "\nPOSTAL CODE N1: "; cin >> new_address.CP1; while(!cin_test()) cin >> new_address.CP1;
    cout << left << setw(20) << "\nPOSTAL CODE N2: "; cin >> new_address.CP2; while(!cin_test()) cin >> new_address.CP2;
    ostringstream helpful_str;
    helpful_str << new_address.CP1 << "-" << new_address.CP2;
    new_address.CP = helpful_str.str();
    cout << left << setw(20) << "\nLOCATION: "; readline(new_address.location);

    cout << "\n\n==== SEARCH ====\n";
    vpos = search_client_name(CL);
    for (int j=0; j < vpos.size(); j++)
    {
       cout << CL.at(vpos.at(j)).name << " | ADDRESS: "
            << CL.at(vpos.at(j)).address.street     << div
            << CL.at(vpos.at(j)).address.doorNumber << div
            << CL.at(vpos.at(j)).address.floor      << div
            << CL.at(vpos.at(j)).address.CP         << div
            << CL.at(vpos.at(j)).address.location   << "\n";
    }

    cout << "\nSelect which client's ADDRESS you wish to change\n";
    dec_which = validate_interface_input(1, vpos.size());
    CL.at(vpos.at(dec_which - 1)).address.street = new_address.street;
    CL.at(vpos.at(dec_which - 1)).address.doorNumber = new_address.doorNumber;
    CL.at(vpos.at(dec_which - 1)).address.floor = new_address.floor;
    CL.at(vpos.at(dec_which - 1)).address.CP = new_address.CP;
    CL.at(vpos.at(dec_which - 1)).address.location = new_address.location;
}

void change_client_packs(Agency agency)
{
    int pos, dec_which;
    vector<int> vpos;
    string new_name;
    cout << "\nNew name: "; readline(new_name);
    cout << "\n\n==== SEARCH ====\n";

    vpos = search_client_name(CL);
    for (int j = 0; j < vpos.size(); j++)
    {
       cout << CL.at(vpos.at(j)).name << "\n";
    }

    cout << "\nSelect which one you wish to delete\n";
    dec_which = validate_interface_input(1, vpos.size());
    CL.at(vpos.at(dec_which - 1)).name = new_name;
}
*/

void edit_client(Agency agency)
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

        input = validate_interface_input(1, 5);
        switch(input)
        {
            case 1:
            change_client_name(CL);
            break;

            case 2:
            change_client_NIF(CL);
            break;
            
            case 3:
            change_client_famagr(CL);            
            break;

            case 4:
            change_client_address(CL);            
            break;

            case 5:
            return;
        }
        write_clients(CL, clients_file);
    }
}


// REMOVE CLIENT
void remove_client(Agency agency)
{
	int input, which, pos;
    vector<int> vpos;
	bool valid = false;
    while(1)
    {
        clearScreen();
        cout << "\n Removing client" << "\n\n";  
        cout << "| 1 - Search\n| 2 - Back\n\n"; 

        input = validate_interface_input(1, 2);
        switch(input)
        {
            case 1:
            cout << "\n\n==== SEARCH ====\n| Type 1 for NAME search.\n| Any other input will trigger NIF search: "; cin >> which;
            if (which == 1) 
            {
               int delwhich;
               vpos = search_client_name(CL);
               for(int j=0; j<vpos.size(); j++)
               {
                  cout << CL.at(vpos.at(j)).name << "\n";
               }    
               cout << "\nSelect which one you wish to delete: [1-" << vpos.size() << "]: ";
               delwhich = validate_interface_input(1, vpos.size());
               CL.erase(CL.begin() + vpos.at(delwhich-1));
            }
            else 
            {
               pos = search_client_NIF(CL);
               CL.erase(CL.begin() + pos);
            }
            break;


            case 2:
            return;
        }
    write_clients(CL, clients_file);
    }
}




// ===== PACKS ======

void add_pack(Agency agency)
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

    write_packs(PK, packs_file);
    cout << "Pack successfully added.\n"; 
}


void edit_pack(Agency agency)
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

        input = validate_interface_input(1, 5);
        switch(input)
        {
            case 1:
            cout << "Type 1 for name search. Any other input will trigger NIF search: "; cin >> which;
            //change_client_name(CL);
            break;

            case 5:
            return;
        }
    }
    write_packs(PK, packs_file);
}

void remove_pack(Agency agency)
{
	int input, pos;
	bool valid = false;
    while(1)
    {
        clearScreen();
        cout << "\n Removing pack" << "\n\n";  
        cout << "| 1 - Search\n| 2 - Back\n\n"; 

        input = validate_interface_input(1, 2);
        switch(input)
        {
            case 1:
            cout << "\n\n==== SEARCH ====\n";
            pos = search_pack_ID(PK);
            PK.erase(PK.begin() + pos);
            break;

            case 2:
            return;
        }
    }
    write_packs(PK, packs_file);
}


void purchase_pack(Agency agency)
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
        input = validate_interface_input(1, 2);

        switch(input)
        {
            case 1:
            cout << "\n\n==== SEARCH CLIENT ====\n";
            //decide_search(); ---> soon 
            vpos = search_client_name(CL);
            for(int j = 0; j < vpos.size(); j++)
            {
                cout << CL.at(vpos.at(j)).name << " | Packs bought: " << CL.at(vpos.at(j)).packs_str << "\n";
            }
            cout << "\nSelect which client will buy the pack\n";
            dec_which = validate_interface_input(1, vpos.size());

            cout << "\n| Type the ID of the pack the client wants to purchase\n";

            P_ID = search_pack_ID(PK);
            while(PK.at(P_ID).id < 0) 
            {
                cout << "Sorry, that pack is not available anymore. You can still add a different pack.\n"
                    << "| 1 - Continue searching for a pack\n| 2 - Backout of pack shopping :(\n";
                again = validate_interface_input(1, 2);
                switch(again)
                {
                    case 1:
                    break;
                    case 2:
                    return;
                }
                P_ID = search_pack_ID(PK);
            }
            CL.at(vpos.at(dec_which-1)).packs.push_back(PK.at(P_ID).id);
            CL.at(vpos.at(dec_which-1)).packs_str += " ; " + to_string(PK.at(P_ID).id);
            break;

            case 2:
            return;
        }
        write_clients(CL, clients_file);
    }
}

void determine_packs_money(Agency agency)
{
    float total_money=0, total_sold=0;
    for(int i=0; i<PK.size(); i++)
    {
        total_sold += PK.at(i).soldSeats;
        total_money += (PK.at(i).soldSeats * PK.at(i).price_pp);
    }

    cout << endl;
    cout << left << setw(35) << "\nTotal of packs sold: " << total_sold;
    cout << left << setw(35) << "\nTotal income from packs sold: " << total_money << "\n\n";
}