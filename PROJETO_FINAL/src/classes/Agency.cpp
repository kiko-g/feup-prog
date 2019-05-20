#include "Agency.h"
Agency::Agency(string agency_file_str)
{
    vector<string> agencyContent;
    vector<string> clientContent;
    vector<string> packContent;
    agencyContent = readAgency(agency_file_str);
    clientContent = readClients(agencyContent[4]);
    packContent = readPacks(agencyContent[5]);

    vector<Client> clients = decomposeClients(clientContent, agencyContent[4]);
    vector<Pack> packs = decomposePacks(packContent, agencyContent[5]);

    this->setName(agencyContent[0]);
    int VATnr;
    stoint(agencyContent[1], VATnr);
    this->setVATnumber(VATnr);
    
    this->setURL(agencyContent[2]);

    string street; // street name
    unsigned short doorNumber; // door number
    string Floor; // Floor number ("-" means not applicable)
    string postalCode; // postal code
    string location; // site

    Address address = string_to_address(agencyContent[3]);
    this->setAddress(address);

    this->setClients(clients);
    this->setPacks(packs);
    for (int k = 0; k < clients.size(); k++)
        this->clients.at(k).setTotalPurchased(determineMoneySpentByClient(clients.at(k).getPackList()));
        
    this->clientsInfoHasChanged = false;
    this->packsInfoHasChanged = false;
    
    this->maxClientsId = determineMaxClientID(); //max_clients_id;
    this->maxPacksId = determineMaxPacksID();   //maxPacks_id;
}

// metodos GET
string Agency::getName() const
{
    return this->name;    
}

unsigned Agency::getVATnumber() const
{
    return this->VATnumber;
}

Address Agency::getAddress() const
{
    return this->address;
}

string Agency::getURL() const
{
    return this->URL;  
}

vector<Client> Agency::getClients() const
{
    return this->clients;  
}

vector<Pack> Agency::getPacks() const
{
    return this->packs; 
}


bool Agency::getClientsIHC() const
{
    return this->clientsInfoHasChanged;
}

bool Agency::getPacksIHC() const
{
    return this->packsInfoHasChanged;
}

void Agency::setClientsIHC(bool d)
{
    this->clientsInfoHasChanged = d;
}

void Agency::setPacksIHC(bool d)
{
    this->packsInfoHasChanged = d;
}



vector<int> Agency::allPacksSold()
{
    int cont=0;
    vector<int> result;
    result.push_back(-1);
    for(int i=0; i<clients.size(); i++)
    {
        vector<int> pkl = clients.at(i).getPackList();
        for(int j=0; j<pkl.size(); j++)
        {
            for(int k=0; k<result.size(); k++)
            {
                cont = 0;
                if(pkl.at(j) == result.at(k)) cont++;
            }
            if(result.at(0)==-1) result.at(0) = pkl.at(j);
            if(cont==0 && result.at(0)!=-1) result.push_back(pkl.at(j));
        }
    }
    cout << "\n\n=== ALL PACKS SOLD UNORDERED ===\n(includes repeated packs)\n\n";
    return result;
}




// SET METHODS
void Agency::setName(string name)
{
    this->name = name;  
}

void Agency::setVATnumber(unsigned VATnumber)
{  
    if(VATnumber > 999999999 || VATnumber < 100000000)
    {
        cout << "Invalid Agency VAT Number";
        exit(1); 
    }
    else
    {
        this->VATnumber = VATnumber;
    }
}

void Agency::setAddress(Address address)
{
    this->address = address;
}

void Agency::setURL(string url)
{
    this->URL = url; 
}

void Agency::setClients(vector<Client> &clients)
{
    this->clients = clients; 
}

void Agency::setPacks(vector<Pack> & packs)
{
    this->packs = packs;
}


//====================
//SAVING FILES METHODS
void Agency::saveClientsInfo(string filename)
{
    ofstream fout;
    fout.open(PATH_TO_DATA + filename);

    for (int i=0; i < clients.size(); i++)
    fout << clients.at(i);

    maxClientsId = determineMaxClientID();
    fout.close();
}

void Agency::savePacksInfo(string filename)
{
    ofstream fout;
    fout.open(PATH_TO_DATA + filename);
    // ID OF THE LAST PACK TO BE ADDED ON THE TOP OF THE FILE 
    fout << packs.at(packs.size()-1).getId() << "\n"; 

    for (int i=0; i < packs.size(); i++)
        fout << packs.at(i);
    
    maxPacksId = determineMaxPacksID();
    fout.close();
}


//=============
// EDIT METHODS
void Agency::addClients()
{
    Client c = preAddClient();
    c.setTotalPurchased(determineMoneySpentByClient(c.getPackList()));
    this->clients.push_back(c);
    this->clientsInfoHasChanged = true;
}

void Agency::addPacks()
{
    Pack pack = preAddPack();
    this->packs.push_back(pack);
    this->packsInfoHasChanged = true;
}

void Agency::rmClients()
{
    // DEC_WHICH ---> DECISE WHICH OF THE FOUND CLIENTS (IN vpos)
    cout << "\n\n==== SEARCH CLIENT NAME ====\n";
    vector<int> c_list = searchClientName();

    cout << "\nSelect which client's NIF you wish to change\n";
    for (int j = 0; j < c_list.size(); j++)
        cout << clients.at(c_list.at(j)).getName() << "\n";

    int dec_which = validateInterfaceInput(1, c_list.size());
    int clientPos = c_list.at(dec_which-1);

    this->clients.erase(this->clients.begin()+clientPos);
    this->clientsInfoHasChanged = true;
}

void Agency::rmPacks(int packPos)
{
    // REMOVING A PACK MEANS MAKING IT UNAVAILABLE
    // UNAVAILABLE PACKS HAVE NEGATIVE IDs
    this->packs.at(packPos).setId(-this->packs.at(packPos).getId());
    this->packsInfoHasChanged = true;
}

void Agency::printAllClients()
{
    for (size_t i = 0; i < this->clients.size(); i++)
        cout << this->clients.at(i);  
}

void Agency::printAllPacks()
{
    for (size_t i = 0; i < this->packs.size(); i++)
    {
        cout << this->packs.at(i);
    }
}

//somepacks as the indices!!!
//print only those (indices != packID)
void Agency::printSomePacks(vector<int> somepacks)
{
    for (int j=0; j < somepacks.size(); j++)
    {
        cout << this->packs.at(somepacks.at(j)) << endl;
    }
}

//somepacks as the indices!!!
//print only those (indices != packID)
void Agency::printSomeClients(vector<int> someclients)
{
    for (size_t i = 0; i < someclients.size(); i++)
    {
        cout << "=== CLIENT" << i+1 << " ===\n" << this->clients.at(someclients.at(i)) << endl;
    }
}

void Agency::printOneClient(int pos)
{
    cout << this->clients.at(pos) << endl;
}

void Agency::printOnePack(int pos)
{
    cout << this->packs.at(pos) << endl;
}

//get the position
vector<int> Agency::getPacksPos(vector<int> p)
{
    vector<int> res;
    res.clear();
    for(int i=0; i < p.size(); i++)
    {
        for (int j=0; j < this->packs.size(); j++)
        {
            if(p.at(i) == abs(this->packs.at(j).getId()))
            res.push_back(j);
        }
    }
    return res;
}

//=================
// ==== SEARCH ====

vector<int> Agency::searchClientName()
{
    bool valid = false;
    vector<int> found;
    string inputname;

    while (!valid)
    {
        found.clear();
        found.push_back(-1);
        inputname = findClientName();
        for(int j = 0; j < clients.size(); j++)
        {
            const string h = clients.at(j).getName();
            if (h.find(inputname) != string::npos)
            {
                if (found.at(0) == -1) found.at(0) = j;
                else found.push_back(j);
            }
        }

        if(found.at(0) == -1)
        {
            cout << "\nThere isn't a client with that name.\nTry again\n";
        }
        else valid=true;
    }
    return found;
}

int Agency::searchClientNIF(int NIF)
{
    int found = -1;
    while (found == -1)
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (NIF == clients.at(i).getVATnumber())
            {
                found = i;
                return found;
            }
        }
        if (found == -1)
        {
            cout << "There isn't a client with that VAT/NIF number. Continue trying?\n";
            cout << "1 - YES\n2 - LEAVE\n";
            int w = validateInterfaceInput(1, 2);
            switch (w)
            {
            case 1:
                searchClientNIF(findClientNIF());
                break;
            case 2:
                return found;
            }
        }
    }
    return found;
}

int Agency::searchPackID(int ID)
{
    int found = -1;
    while (found == -1)
    {
        for (int i = 0; i < packs.size(); i++)
        {
            if (ID == packs.at(i).getId())
            {
                found = i;
                break;
            }
        }
        if (found == -1)
        {
            cout << "There isn't a pack with that ID number. Try again\n";
            searchClientNIF(findClientNIF());
        }
    }
    return found;
}

vector<int> Agency::searchPackMainLocation()
{
    bool valid = false;
    vector<int> found;
    string inputname;

    while (!valid)
    {
        found.clear();
        found.push_back(-1);
        inputname = findPackLocation();
        cout << "\nAll 'main' destinations are listed below:\n\n";
        for (int j = 0; j < packs.size(); j++)
        {
            const string h = packs.at(j).getSites().at(0);
            cout << packs.at(j).getSites().at(0) << "\t"; if(j!=0 && j%4 == 0) cout << endl;

            if(h.find(inputname) != string::npos)
            {
                if (found.at(0) == -1) found.at(0) = j;
                else found.push_back(j);
            }
        }

        if (found.at(0) == -1)
        {
            cout << "\n\nThere isn't a pack with that Main Destination.\nTry again.\n";
        }
        else valid=true;
    }
    cout << "\n===== FOUND =====\n";
    return found;
}

vector<int> Agency::searchPacksBetweenDates(Date end, Date start)
{
    while(!determineGreaterDate(end, start))
    {
        cout << "The dates you input are absurd (start date is AFTER end date)\n"
             << "Insert two new dates:\n\n";
        start = findPackDate("START");
        end = findPackDate("END");
    }

    vector<int> found;
    found.clear();
    found.push_back(-1);
    while (found.at(0) == -1)
    {
        for (int j = 0; j < packs.size(); j++)
        {
            if (!determineGreaterDate(start, packs.at(j).getBeginDate())
            && determineGreaterDate(end, packs.at(j).getEndDate()))
            {
                if (found.at(0) == -1) found.at(0) = j;
                else found.push_back(j);
            }
        }

        if (found.at(0) == -1)
        {
            cout << "There aren't any packs between those dates\n\n";
            cout << "Enter 1 if you want to enter new dates\n";
            cout << "Enter 2 if you want to exit this search\n";
            int w = validateInterfaceInput(1,2);
            if(w==1) searchPacksBetweenDates(findPackDate("END"), findPackDate("START"));
            else break;
        }
    }
    return found;
}

//==========================
// ==== EDIT AND CHANGE ====
//WILL USE OTHER FUNCTIONS IN OTHER.CPP ("find" functions are simple reads)
void Agency::changeClientName()
{
    cout << "\n\n==== SEARCH CLIENT NAME ====\n";
    vector<int> c_list = searchClientName();

    cout << "\nSelect which client's NAME you wish to change\n";
    for (int j = 0; j < c_list.size(); j++)
        cout << clients.at(c_list.at(j)).getName() << "\n";
        
    // DEC_WHICH ---> DECIDE WHICH OF THE FOUND CLIENTS
    int dec_which = validateInterfaceInput(1, c_list.size());
    clients.at(c_list.at(dec_which - 1)).setName(preChangeClientName());
}


void Agency::changeClientNIF()
{
    cout << "\n\n==== SEARCHING WITH NAME ====\n";
    vector<int> c_list = searchClientName();
    cout << "\nSelect which client's NIF you wish to change\n";
    for (int j = 0; j < c_list.size(); j++)
        cout << clients.at(c_list.at(j)).getName() << " | NIF: "
             << clients.at(c_list.at(j)).getVATnumber() << "\n";

    int dec_which;
    dec_which = validateInterfaceInput(1, c_list.size());

    clients.at(c_list.at(dec_which - 1)).setVATnumber(preChangeClientNIF());
}

void Agency::changeClientFAM()
{
    cout << "\n\n==== SEARCH WITH NAME ====\n";
    vector<int> c_list = searchClientName();
    for (int j = 0; j < c_list.size(); j++)
       cout << clients.at(c_list.at(j)).getName() << " | N FAM AGR: " 
            << clients.at(c_list.at(j)).getFamilySize() << "\n";

    cout << "\nSelect which client's Family Agregate Number (FAN) you wish to change\n";
    
    int dec_which = validateInterfaceInput(1, c_list.size());
    clients.at(c_list.at(dec_which - 1)).setFamilySize(preChangeClientFamagr());
}

void Agency::changeClientAddress()
{
    cout << "\n\n==== SEARCH WITH NAME ====\n";
    vector<int> c_list = searchClientName();
    cout << "\nSelect which client's ADDRESS you wish to change\n";
    int dec_which = validateInterfaceInput(1, c_list.size());
    clients.at(c_list.at(dec_which - 1)).setAddress(preChangeClientAddress());
}

void Agency::purchasePack()
{
    vector<int> c_list=searchClientName();
    if(c_list.at(0) != -1)
    {
        cout << "\n\nSELECT WHICH CLIENT WILL BUY A PACK\n";
        printSomeClients(c_list);
    }
    else return;
    cout << "\n\n" << c_list.size()+1 << " - BACK\n";
    int input = validateInterfaceInput(1, c_list.size()+1);
    if(input == c_list.size()+1) return;
}   

void Agency::changePackDate(string which)
{
    vector<int> pk;
    pk = searchPackMainLocation();
    printSomePacks(pk);
    int decision = validateInterfaceInput(1, pk.size());
    getPacks().at(pk.at(decision - 1)).setBeginDate(findPackDate(which));
}

void Agency::changePackSites()
{
    vector<int> pk;
    vector<string> r;
    pk = searchPackMainLocation();
    printSomePacks(pk);
    int which = validateInterfaceInput(1, pk.size());
    r.push_back(findPackLocation());
    getPacks().at(pk.at(which - 1)).setSites(r);
}


void Agency::changePricePerPerson()
{
    vector<int> pk;
    pk = searchPackMainLocation();
    printSomePacks(pk);
    int input, which = validateInterfaceInput(1, pk.size());
    cout << "\nNEW PRICE PER PERSON: ";  cin >> input;
    getPacks().at(which - 1).setPricePerPerson(input);
}


//OTHER
int Agency::determineMaxClientID()
{
    int maxID=0;
    for(size_t i=0; i<clients.size(); i++)
    {
        if(clients.at(i).getVATnumber() > maxID)
            maxID = clients.at(i).getVATnumber();
    }
    return maxID;
}

int Agency::determineMaxPacksID()
{
    int maxID=0;
    for(int i=0; i<packs.size(); i++)
    {
        if(packs.at(i).getId() > maxID) maxID = packs.at(i).getId();
    }
    return maxID;
}

int Agency::determineMoneySpentByClient(vector<int> packs_bought)
{
    int result=0;
    for(int i=0; i<packs_bought.size(); i++)
    {
        int h = packs_bought.at(i);
        for(int j=0; j<packs.size(); j++)
          if(packs.at(j).getId() == h)
          {
            result += packs.at(j).getPricePerPerson();
            break;
          }
    }
    return result;
}

vector<int> Agency::packSaleStatus()
{
    vector<int> result, prices, nrSold;
    int sold=0, profit=0;
    for(int i=0; i < this->packs.size(); i++)
    {
        prices.push_back(packs.at(i).getPricePerPerson());
        nrSold.push_back(packs.at(i).getNrSold());
        profit += prices.at(i) * nrSold.at(i);
    }

    for(int i=0; i < this->clients.size(); i++)
    {
        result = this->clients.at(i).getPackList();
        sold += result.size();
    }
    result.clear();
    result.push_back(sold); result.push_back(profit);

    cout << "\nPACK SALE STATUS (OBJ 8)\n";
    cout << "TOTAL NUMBER OF SOLD PACKS: " << sold << "\n";
    cout << "INCOME MONEY FROM ALL SOLD PACKS: " << profit << "\n";

    return result;
}

/*********************************
 *          Mostrar Loja
 ********************************/

    // mostra o conteudo de uma agencia
ostream &operator<<(ostream &out, const Agency &agency)
{
    out << agency.name << endl
        << agency.VATnumber << endl
        << agency.URL << endl
        << agency.address << endl;

    return out;
}
