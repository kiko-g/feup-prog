//Read and organize the contents of the text files
#include "myLib.h"

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

vector<string> read_agency()
{
    vector<string> content;
    string agency_file_str, line;
    ifstream fin;
    cout << "\nType the name of the file (agency): ";
    
    cin >> agency_file_str; 
    
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

Agency decompose_agency(vector<string> rawAG)
{
    Agency AG;
    int NIF;
    vector<string> divAD = strtok_cpp(rawAG.at(3), " | ");  // LINE 4 HOLDS ADDRESS
    vector<string> divCP = strtok_cpp(divAD.at(3), "-");    // SECTION 4 OF LINE 4 HOLD CP 

    //PART 1
    AG.name = rawAG.at(0);
    //PART 2
    stoint(rawAG.at(1), AG.NIF);
    //PART 3
    AG.webURL = rawAG.at(2);
    //PART 4
    AG.address.street = divAD.at(0);            // 4.0
    stoint(divAD.at(1), AG.address.doorNumber); // 4.1
    AG.address.floor = divAD.at(2);             // 4.2
    AG.address.CP = divAD.at(3);                // 4.3
    AG.address.CP1 = stoi(divCP.at(0));         
    AG.address.CP2 = stoi(divCP.at(1));
    AG.address.location = divAD.at(4);          // 4.4
    return AG;
}

// ======================================
// ======================================

vector<Client> decompose_clients(vector<string> rawCL, string filename)
{
    vector<Client> CL;
    int i=0, client_number = numberOf(filename);
    vector<string> divAD;       // DIVIDING ADDRESS,     LINE 4 HOLDS ADDRESS
    vector<string> divCP;       // DIVIDING POSTAL CODE, SECTION 4 OF LINE 4 HOLD CP
    vector<string> divPK;       // DIVIDING PACKS STRING INTO A VECTOR OF PACK NUMBERS OF STRING TYPE

    // 6*i helps us advance to the correct client info
    while(i < client_number)
    {
        Client c;
        c.name = rawCL.at(0 + 6*i);                 // PART 1
        stoint(rawCL.at(1 + 6*i), c.NIF);            // PART 2
        stoint(rawCL.at(2 + 6*i), c.nFamAgr);        // PART 3
        // PART 4
        divAD = strtok_cpp(rawCL.at(3 + 6*i), " | ");
        divCP = strtok_cpp(divAD.at(3), "-");

        c.address.street = divAD.at(0);             // 4.0
        stoint(divAD.at(1), c.address.doorNumber);  // 4.1
        c.address.floor = divAD.at(2);              // 4.2
        c.address.CP = divAD.at(3);                 // 4.3
        stoint(divCP.at(0), c.address.CP1);         // 4.3
        stoint(divCP.at(1), c.address.CP2);         // 4.3
        c.address.location = divAD.at(4);           // 4.4
        // PART 5
        c.packs_str = rawCL.at(4 + 6*i);
        divPK = strtok_cpp(c.packs_str, " ; ");

        int value_pk;
        for(int j = 0; j < divPK.size(); j++)
        {
            stoint(divPK.at(j), value_pk);
            c.packs.push_back(value_pk);
        }
        CL.push_back(c);
        i++;
    }
    return CL;
}

// ======================================
// ======================================

vector<Pack> decompose_packs(vector<string> rawPK, string filename)
{
    int i=0, pack_number = numberOf(filename);
    vector<Pack> PK;
    vector<string> divDATE;       // DIVIDING PACKS STRING INTO A VECTOR OF PACK NUMBERS OF STRING TYPE

    // 8*i helps us advance to the correct client info
    while(i < pack_number)
    {
        Pack p;
        p.id = stoi(rawPK.at(1 + 8*i));                 //PART 1
        p.destination = rawPK.at(2 + 8*i);              //PART 2
        divDATE = strtok_cpp(rawPK.at(3 + 8*i), "/");   //PART 3
        p.startDate.year = stoi(divDATE.at(0));
        p.startDate.month = stoi(divDATE.at(1));
        p.startDate.day  = stoi(divDATE.at(2));
        divDATE = strtok_cpp(rawPK.at(4 + 8*i), "/");   // PART 4
        p.endDate.year = stoi(divDATE.at(0));
        p.endDate.month = stoi(divDATE.at(1));
        p.endDate.day = stoi(divDATE.at(2));
        p.price_pp = stoi(rawPK.at(5 + 8*i));           // PART 5
        p.availableSeats = stoi(rawPK.at(6 + 8*i));     // PART 6
        p.soldSeats = stoi(rawPK.at(7 + 8*i));          // PART 7

        PK.push_back(p);
        i++;
    }
    return PK;
}