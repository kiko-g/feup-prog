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
    readline(input_name);
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

Client preAddClient()
{
    bool valid = false;
    cout << "Adding Client"
         << "\n\n";

    string name;               // name of the client
    unsigned VATnumber;        // VAT number of client
    unsigned short familySize; // number of family members

    string street;             // street name
    unsigned short doorNumber; // door number
    string Floor;              // Floor number ("-" is not applicable)
    string postalCode;         // postal code
    string location;           // site

    vector<unsigned int> packs; // vector to store client's packs bought
    unsigned totalPurchased;    // total value spent by the client

    //READ THE CLIENT
    cout << "Name: "; readline(name);
    cout << "NIF: "; cin >> VATnumber; while (!cin_test()) cin >> VATnumber;
    cout << "Number of members in household: ";  cin >> familySize; while (!cin_test()) cin >> familySize;
    cout << "Street name: "; readline(street);
    cout << "Door number: "; cin >> doorNumber; while (!cin_test()) cin >> doorNumber;
    cout << "Floor info: "; cin >> Floor; while (!cin_test()) cin >> Floor;
    cout << "Postal Code: "; readline(postalCode);
    cout << "Location: "; readline(location);

    int j = 0, packn, cond;
    //string divider = " ; ";

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

    totalPurchased = 0;

    Address address(street, doorNumber, Floor, postalCode, location);
    Client c(name, VATnumber, familySize, address, packs, totalPurchased);
    cout << "Client successfully added.\n";
    return c;
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


