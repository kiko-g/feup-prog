//Read and organize the contents of the text files
#include "defs.h"

using namespace std;

int numberOf(string fileName)
{
    reset_pathToFile();
    pathToFile = pathToFile + fileName;
    string line;
    // N represents the of and occurance in a file (number of clients, for instance)
    int N = 0;
    ifstream fin;
    fin.open(pathToFile);
    while (!fin.eof())
    {
        getline(fin, line);
        if (line == limit) N++;
        if (line == "") continue;
    }

    return N;
}

// ======================================
// ======================================

vector<string> read_agency(string agency_file_str)
{
    vector<string> content;
    string line;
    ifstream fin;

    pathToFile = pathToFile + agency_file_str;
    fin.open(pathToFile);

    int count_fails = 0;
    if (fin.fail())
    {
        if(count_fails == 4)
        {
            "\n\nCheck filename in the folders...\nExiting now.";
            exit(1);
        }
        count_fails++;
        cerr << "File not found. Type a different file name below\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Type the name of the file (agency): ";
        cin >> agency_file_str;
    }

    while (!fin.eof())
    {
        getline(fin, line);
        if (line == "") continue;
        content.push_back(line);
    }

    
    cout << "Content successfully read from '" << agency_file_str << "'\n";
    
    fin.close();
    reset_pathToFile();
    return content;
}

// ======================================
// ======================================

vector<string> read_clients(string clients_file_str)
{
    vector<string> content;
    ifstream fin;
    string line;
    pathToFile = pathToFile + clients_file_str;
    fin.open(pathToFile);

    if (fin.fail())
    {
        "\n\nCheck filename in the folders...\nExiting now.";   
        exit(1);
    }

    while (!fin.eof())
    {
        getline(fin, line);
        if (line == "") continue;
        content.push_back(line);
    }

    
    cout << "Content successfully read from '" << clients_file_str << "'\n";
    
    fin.close();
    reset_pathToFile();
    return content;
}

// ======================================
// ======================================

vector<string> read_packs(string packs_file_str)
{
    vector<string> content;
    string line;
    ifstream fin;
    pathToFile = pathToFile + packs_file_str;
    fin.open(pathToFile);

    if (fin.fail())
    {
        "\n\nCheck filename in the agency text file...\nExiting now.\n";   
        exit(1);
    }

    while (!fin.eof())
    {
        getline(fin, line);
        if (line == "") continue;
        content.push_back(line);
    }

    
    cout << "Content successfully read from '" << packs_file_str << "'\n";
    
    fin.close();
    reset_pathToFile();
    return content;
}

// ======================================
// ======================================

vector<Client> decompose_clients(vector<string> rawCL, string filename)
{
    vector<Client> CL;
    int i=0, client_number = numberOf(filename);
    vector<string> divPK;       // DIVIDING PACKS STRING INTO A VECTOR OF PACK NUMBERS OF STRING TYPE

    string name; // name of the client
    int VATnumber; // VAT number of client
    int familySize;  // number of family members
    Address address; // client's address
    vector<Packet> packets; // vector to store client's packets bought
    int totalPurchased; // total value spent by the client

    // 6*i helps us advance to the correct client info
    while(i < client_number)
    {
        
        name = (rawCL.at(0 + 6*i));                 // PART 1
        stoint(rawCL.at(1 + 6*i), VATnumber);            // PART 2
        stoint(rawCL.at(2 + 6*i), familySize);        // PART 3
        // PART 4
        Address address = string_to_address(rawCL.at(2 + 6*i));
        // PART 5
        divPK = strtok_cpp(rawCL.at(4 + 6*i), " ; ");
/*
        int value_pk;
        for(int j = 0; j < divPK.size(); j++)
        {
            stoint(divPK.at(j), value_pk);
            c.packs.push_back(value_pk);
        }
        */
       //NOT IMPLEMENTED PACKETS PURCHASED BY CLIENTS
        Client c(name, VATnumber, familySize, address);
        CL.push_back(c);
        i++;
    }
    return CL;
}

// ======================================
// ======================================

vector<Packet> decompose_packs(vector<string> rawPK, string filename)
{
    int i=0, pack_number = numberOf(filename);
    vector<Packet> PK;
    vector<string> divSITES; 
    vector<string> divDATE;       // DIVIDING PACKS STRING INTO A VECTOR OF PACK NUMBERS OF STRING TYPE

    unsigned id; // packet unique identifier
    vector<string> sites; // touristic sites to visit
    double pricePerPerson; // price per person
    unsigned maxPersons;
    unsigned nrSold;

    // 8*i helps us advance to the correct client info
    while(i < pack_number)
    {

        id = stoi(rawPK.at(1 + 8*i));                 //PART 1
        divSITES = strtok_cpp(rawPK.at(3 + 8*i), "-");              //PART 2
        sites.push_back(divSITES.at(0));
        divSITES = strtok_cpp(divSITES.at(1), ";");              //PART 2

        for (size_t i = 0; i < divSITES.size(); i++)
        {
            sites.push_back(divSITES.at(i));
        }
        
        divDATE = strtok_cpp(rawPK.at(3 + 8*i), "/");   //PART 3
        Date begin(stoi(divDATE.at(2)),stoi(divDATE.at(1)),stoi(divDATE.at(0)));
   
        divDATE = strtok_cpp(rawPK.at(4 + 8*i), "/");   // PART 4
        Date end(stoi(divDATE.at(2)),stoi(divDATE.at(1)),stoi(divDATE.at(0)));

        pricePerPerson = stoi(rawPK.at(5 + 8*i));           // PART 5
        maxPersons = stoi(rawPK.at(6 + 8*i));     // PART 6
        nrSold = stoi(rawPK.at(7 + 8*i));          // PART 7

        Packet p(id, sites, begin, end, pricePerPerson, maxPersons, nrSold);
        PK.push_back(p);
        i++;
    }
    return PK;
}

Address string_to_adress(string address_str){
    
    vector<string> divAD;  

    string street;
    int doorNumber;
    string floor;
    string postalCode;
    string location;

    divAD = strtok_cpp(address_str, " | ");

    street = divAD.at(0);             // 4.0
    stoint(divAD.at(1), doorNumber);  // 4.1
    floor = divAD.at(2);              // 4.2
    postalCode = divAD.at(3);                 // 4.3
    location = divAD.at(4);           // 4.4
    Address address(street, doorNumber, floor, postalCode, location);
    return address;
}