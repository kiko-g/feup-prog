#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "defs.h"
#include "other.h"
#include "utils.h"

// OTHER HELPFUL FUNCTIONS THAT SUPPLY THE AGENCY METHODS
string findClientName() // SIMPLE READ NAME
{
    string input_name;
    cout << "\nSearching client name\nInput name: ";
    readline(input_name); cout << endl;
    return input_name;
}

int findClientNIF()     // SIMPLE READ NIF
{
    string NIF_str;
    int NIF;
    cout << "\nInput NIF: ";
    readline(NIF_str);
    while ((stoint(NIF_str, NIF) != 0))
    {
        cout << "Try again. Just numbers, please: ";
        readline(NIF_str);
    }
    return NIF;
}

int helpRead() // SIMPLE READ STRING THE STOI
{
    string NIF_str;
    int NIF;
    readline(NIF_str);
    while ((stoint(NIF_str, NIF) != 0))
    {
        cout << "Try again. Just numbers, please: ";
        readline(NIF_str);
    }
    return NIF;
}

int findPackID() // SIMPLE READ ID
{
    string pID_str;
    int pID;
    cout << "\nInput ID: ";
    readline(pID_str);
    while ((stoint(pID_str, pID) != 0))
    {
        cout << "Try again. Just numbers, please: ";
        readline(pID_str);
    }
    return pID;
}

string findPackLocation() // SIMPLE READ NAME
{
    string input_name="";
    cout << "=== Searching pack MAIN Destination ===\nInput name: ";
    readline(input_name);
    return input_name;
}

string findPackSpecificLocations() // SIMPLE READ NAME
{
    int howmany; cout << "\nHow many specific locations will the pack have? --> ";
    cin >> howmany;
    string result, input_name;

    if(howmany > 0) result = " - ";
    else result = "";
    for(int i=0; i<howmany; i++)
    {
        cout << "\nSPECIFIC sites\nName (site " << i << "): ";
        readline(input_name);
        result += input_name;
        if(i!=howmany-1) result+=", ";
    }
    return result;
}

Date findPackDate(string which)
{ 
    Date DATE;
    int D, M, Y;
    string dd, mm, yy;
    //========
    cout << endl << which << " DATE DAY: ";
    readline(dd);
    while ((stoint(dd, D) != 0))
    {
        cout << "(reading day) Try again.\nJust numbers, please: ";
        readline(dd);
    }
    DATE.setDay(D);
    //========
    cout << which << " DATE MONTH: ";
    readline(mm);
    while ((stoint(mm, M) != 0))
    {
        cout << "(reading month) Try again.\nJust numbers, please: ";
        readline(mm);
    }
    DATE.setMonth(M);
    //========
    cout << which << " DATE YEAR: ";
    readline(yy);
    while ((stoint(yy, Y) != 0))
    {
        cout << "(reading year) Try again.\nJust numbers, please: ";
        readline(yy);
    }
    DATE.setYear(Y);
    cout << "\n\n" << which << " DATE WAS READ AS: "
         << DATE.getDay() << "/" << DATE.getMonth() << "/" << DATE.getYear() << "\n\n";
    return DATE;
    
}

// ======

Client preAddClient()
{
    cout << "\n=== ADDING CLIENT ===\n\n";

    unsigned VATnumber;             // VAT number of client
    unsigned short PC1, PC2;        // 4130 then 283 p.e.
    unsigned short familySize;      // number of family members
    unsigned short DN;              // door number
    string name;                    // name of the client
    string street;                  // street name
    string Floor;                   // Floor number ("-" is not applicable)
    string location;                // site
    vector<int> packs;

    //READ THE CLIENT
    cout << "Name: "; readline(name);
    cout << "NIF: "; helpRead();
    cout << "Number of members in household: ";  helpRead();
    cout << "Street name: "; readline(street);
    cout << "Door number: "; helpRead();
    cout << "Floor info: "; readline(Floor);
    cout << "Postal Code 1: "; helpRead();
    cout << "Postal Code 2: "; helpRead();
    cout << "Location: "; readline(location);

    int j = 0, packn, cond;
    ostringstream PC;
    PC << PC1 << "-" << PC2;

    cout << "\n=== CLIENT PACKS ===";
    cout << "\nTotal number of packs: ";
    cin >> cond;

    while (!cin.eof() && j < cond)
    {
        j++;
        cout << "Pack " << j << ": ";
        cin >> packn;
        packs.push_back(packn);
    }

    // total purchased will be set later
    // inside the "addClients" method in Agency class

    //to_string(PC1)+"-"+to_string(PC2) alternative to PC.str()

    Address address(street, DN, Floor, PC.str(), location);
    Client c(name, VATnumber, familySize, address, packs, 0);
    cout << "Client successfully added.\n";
    return c;
}

Pack preAddPack()
{
    cout << "\n=== ADDING PACK ===\n\n";
    int ID, pricePP, maxSeats, reserved;
    string sitelist, first;
    Date start, end;
    vector<string> h1, h2, sites;
    //READ THE CLIENT
    cout << "Dont add a repeated ID please\nID: "; cin >> ID; while(!cin_test()) cin >> ID;
    cout << "DATES\n\n"; start = findPackDate("START"); end = findPackDate("END");
    cout << "Price per person: "; cin >> pricePP; while(!cin_test()) cin >> pricePP;
    cout << "Max seats: "; cin >> maxSeats; while(!cin_test()) cin >> maxSeats; 
    reserved = maxSeats+1;
    cout << "Booked seats (< Max Seats): "; while(!cin_test() || maxSeats<reserved) cin >> reserved;
    cout << "Reading full location\n\n"; 

    sites.clear();
    string h;
    sites.push_back(findPackLocation());
    sitelist = findPackSpecificLocations();
    h = sites.at(0) + sitelist;
    h1 = strtok_cpp(h, " - "); //PART 2
    //cout << second.at(0);
    //cout << second.at(1);
    first.clear();
    h2 = strtok_cpp(h1.at(1), ", ");
    for (int i = 0; i < first.size(); i++)
    {
       sites.push_back(h2.at(i));
    }
    
    Pack p(ID, sites, start, end, pricePP, maxSeats, reserved);
    cout << "\nPack successfully added.\n";
    return p;
}

string preRemoveClient()
{
    string name;
    cout << "\nNew name: ";
    readline(name);
    return name;
}

string preChangeClientName()
{
    string new_name;
    cout << "\nNew name: "; readline(new_name);
    return new_name;
}

int preChangeClientNIF()
{
    int pos, new_NIF = 0;
    string new_NIFstr;

    cout << "\nNew NIF: "; readline(new_NIFstr);

    //STOINT IS DECLARED IN HELPFUL.CPP AND ALTERS THE VALUE OF new_NIF
    while (stoint(new_NIFstr, new_NIF) != 0)
    {
        cout << "New NIF input is invalid.\nTry again, this time only numbers\nNew NIF: ";
        readline(new_NIFstr);
        break;
    }
    return new_NIF;
}

int preChangeClientFamagr()
{
    int new_NFA;
    cout << "\nNew family aggregate (family size) number: "; cin >> new_NFA;
    while (!cin_test()) cin >> new_NFA;

    return new_NFA;
}

Address preChangeClientAddress()
{
    string street, Floor, location, CP;
    unsigned short CP1, CP2, doorNumber;

    //ADDRESS COMPONENTS ---> These will be read from input
    cout << "\nType new address below\n\n";
    cout << left << setw(20) << "STREET: ";  readline(street);
    cout << left << setw(20) << "\nDOOR NUMBER: "; cin >> doorNumber;  while (!cin_test()) cin >> doorNumber;
    cout << left << setw(20) << "\nFloor: "; readline(Floor);
    cout << left << setw(20) << "\nPOSTAL CODE N1: "; cin >> CP1; while (!cin_test()) cin >> CP1;
    cout << left << setw(20) << "\nPOSTAL CODE N2: "; cin >> CP2; while (!cin_test()) cin >> CP2;
    cout << left << setw(20) << "\nLOCATION: "; readline(location);

    ostringstream join;
    join << CP1 << "-" << CP2;
    //to_string(CP1) + "-" + to_string(CP2)
    Address A(street, doorNumber, Floor, join.str(), location);
    return A;
}

//return 1 if start date is lower   (should be)
//return 0 if start date is greater (bad input dates...)
// 1 means b > a 
// 0 means b < a ----> ABSURD

int determineGreaterDate(Date b, Date a)
{
    if(a.getYear() < b.getYear()) return 1;
    if(a.getYear() == b.getYear() && a.getMonth() < b.getMonth()) return 1;
    if(a.getYear()==b.getYear() && a.getMonth()==b.getMonth() && a.getDay()<=b.getDay()) return 1;

    else return 0;
}
