#include "utils.h"

int validateInterfaceInput(int a, int b)
{
    int n;
    bool valid = false;

    while (!valid)
    {
        cout << "Type your option [" << a << "-" << b << "]: ";
        cin >> n;
        if (a <= n && b >= n && !cin.fail())
        {
            valid = true;
            cin.ignore(1000, '\n');
        }

        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Try again. Number should be between " << a << " and " << b << "\n\n";
        }
    }
    return n;
}

int stoint(const string& str, int &value)
{
    int base = 10;
    size_t* pos = 0;
    // wrapping stoi because it may throw an exception

    try
    {
        value = stoi(str, pos, base);
        return 0;
    }

    catch (const invalid_argument& ia)
    {
        //cerr << "Invalid argument: " << ia.what() << endl;
        return -1;
    }

    catch (const out_of_range& oor)
    {
        //cerr << "Out of Range error: " << oor.what() << endl;
        return -2;
    }

    catch (const exception& e)
    {
        //cerr << "Undefined error: " << e.what() << endl;
        return -3;
    }
}

int numberOf(string fileName)
{
    string line;
    // N represents the of and occurance in a file (number of clients, for instance)
    int N = 0;
    ifstream fin;
    fin.open(PATH_TO_DATA + fileName);
    while (!fin.eof())
    {
        getline(fin, line);
        if (line == LIMIT_STRING) N++;
        if (line == "") continue;
    }

    return N;
}

vector<string> strtok_cpp(string h, string n)
{
    // h is haystack, n is needle
    vector<string> ret;
    size_t startPos = 0, endPos = 0;
    while (endPos<h.length())
    {
        endPos=h.find(n,startPos);
        if(endPos==h.npos)
        {
            ret.push_back(h.substr(startPos));
            break;
        } 
        else ret.push_back(h.substr(startPos,endPos-startPos));
        startPos=endPos + n.length();
    }
    return ret;
}


Address string_to_address(string address_str)
{    
    vector<string> divAD; //vector of string, divAD = divide Address 
    string street;
    int doorNumber;
    string floor;
    string postalCode;
    string location;

    divAD = strtok_cpp(address_str, " | ");

    street = divAD.at(0);             // 4.0
    stoint(divAD.at(1), doorNumber);  // 4.1
    floor = divAD.at(2);              // 4.2
    postalCode = divAD.at(3);         // 4.3
    location = divAD.at(4);           // 4.4
    Address address(street, doorNumber, floor, postalCode, location);
    return address;
}


bool cin_test()
{
    bool ret = false;
    if(!cin.fail())
    {
        ret = true;
        return ret;
    }
    
    if(cin.fail())
    {    
       cin.clear();
       cin.ignore(1000, '\n');
    }
    return ret;
}
    

void readline(string &str)
{
    cin.clear();
    fflush(stdin);
    getline(cin, str);
    while(str.size() == 0)
    {
        getline(cin, str);
    }
}