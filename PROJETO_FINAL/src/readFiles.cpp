#include "readFiles.h"


// ======================================
// ======================================

vector<string> readAgency(string agency_file_str)
{
    vector<string> content;
    string line;
    ifstream fin;

    fin.open(PATH_TO_DATA + AGENCY_FILE_NAME);

    if (fin.fail())
    {
        cout << "\n\nCHECK AGENCY FILENAME IN THE FOLDERS AND"
             << "COMPARE IT TO THE DEFINITION IN defs.h\nExiting now.";
        exit(1);
    }

    while (!fin.eof())
    {
        getline(fin, line);
        if (line == "") continue;
        content.push_back(line);
    }

    cout << "Content successfully read from '" << agency_file_str << "'\n";

    fin.close();
    return content;
}

// ======================================
// ======================================

vector<string> readClients(string clients_file_str)
{
    vector<string> content;
    ifstream fin;
    string line;

    fin.open(PATH_TO_DATA + clients_file_str);

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
    return content;
}

// ======================================
// ======================================

vector<string> readPacks(string packs_file_str)
{
    vector<string> content;
    string line;
    ifstream fin;

    fin.open(PATH_TO_DATA + packs_file_str);

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

    return content;
}

// ======================================
// ======================================

vector<Client> decomposeClients(vector<string> rawCL, string filename)
{
    vector<Client> CL;
    int i=0;
    vector<string> divPK;       // DIVIDING PACKS STRING INTO A VECTOR OF PACK NUMBERS OF STRING TYPE

    string name; // name of the client
    int VATnumber; // VAT number of client
    int familySize;  // number of family members
    Address address; // client's adayress
    int totalPurchased; // total value spent by the client

    // 6*i helps us advance to the correct client info
    int nrClients = numberOf(filename);
    while (i < nrClients)
    {
        int offset = 7*i;
        vector<int> packs;
        name = (rawCL.at(0 + offset));                   // PART 1
        stoint(rawCL.at(1 + offset), VATnumber);         // PART 2
        stoint(rawCL.at(2 + offset), familySize);        // PART 3
        // PART 4
        Address address = string_to_address(rawCL.at(3 + offset));
        // PART 5
        divPK = strtok_cpp(rawCL.at(4 + offset), " ; ");

        int value_pk;
        for(int j = 0; j < divPK.size(); j++)
        {
            stoint(divPK.at(j), value_pk);
            packs.push_back(value_pk);
        }
        stoint(rawCL.at(5 + offset), totalPurchased);
        Client c(name, VATnumber, familySize, address, packs, totalPurchased);
        CL.push_back(c);
        i++;
    }
    return CL;
}

// ======================================
// ======================================

vector<Pack> decomposePacks(vector<string> rawPK, string filename)
{
    int i=0;
    vector<Pack> PK;
    vector<string> divSITES; 
    vector<string> divDATE;       // DIVIDING PACKS STRING INTO A VECTOR OF PACK NUMBERS OF STRING TYPE
    int pricePerPerson; // price per person
    int maxPersons;
    int nrSold;

    // 8*i+1 helps us advance to the correct client info
    int nrPacks = numberOf(filename);
    while (i < nrPacks)
    {
        int offset = 8*i+1;
        int id;
        vector<string> sites;
        stoint(rawPK.at(0 + offset), id);                     //PART 1
        divSITES = strtok_cpp(rawPK.at(1 + offset), " - ");   //PART 2
        sites.push_back(divSITES.at(0));
        if(divSITES.size()>1)
        {
            divSITES = strtok_cpp(divSITES.at(1), ", ");       //PART 2
            for (size_t i = 0; i < divSITES.size(); i++)
            {
                sites.push_back(divSITES.at(i));
            }
        }   
        
        int year, month, day;
        divDATE = strtok_cpp(rawPK.at(2 + offset), "/");       //PART 3
        stoint(divDATE.at(0), year);
        stoint(divDATE.at(1), month);
        stoint(divDATE.at(2), day);
        Date begin(day, month, year);

        divDATE = strtok_cpp(rawPK.at(3 + offset), "/");       // PART 4
        stoint(divDATE.at(0), year);
        stoint(divDATE.at(1), month);
        stoint(divDATE.at(2), day);
        Date end(day, month, year);

        stoint(rawPK.at(4 + offset), pricePerPerson);           // PART 5
        stoint(rawPK.at(5 + offset), maxPersons);               // PART 6
        stoint(rawPK.at(6 + offset), nrSold);                   // PART 7

        Pack p(id, sites, begin, end, pricePerPerson, maxPersons, nrSold);
        PK.push_back(p);
        i++;
    }
    return PK;
}
