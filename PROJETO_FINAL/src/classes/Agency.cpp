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

    this->clientsInfoHasChanged = false;
    this->packsInfoHasChanged = false;

    this->maxClientsId = 0;//max_clients_id;
    this->maxPacksId = 0; //maxPacks_id;
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

void Agency::setClients(vector<Client> & clients)
{
    this->clients = clients; 
}

void Agency::setPacks(vector<Pack> & packs)
{
  this->packs = packs;
}


//SAVING FILES METHODS
void Agency::saveClientsInfo(string filename)
{
    ofstream fout;
    fout.open(PATH_TO_DATA + filename);

    for (int i=0; i < clients.size(); i++)
    fout << clients.at(i);

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

    fout.close();
}

// OTHER METHODS
void Agency::addClients(Client client)
{
    this->clients.push_back(preAddClient());
    this->clientsInfoHasChanged = true;
}

void Agency::addPacks(Pack pack)
{
   this->packs.push_back(pack);
   this->packsInfoHasChanged = true;
}

void Agency::rmClients()
{
    // DEC_WHICH ---> DECISE WHICH OF THE FOUND CLIENTS (IN vpos)
    cout << "\n\n==== SEARCH CLIENT NAME ====\n";
    vector<int> c_list = searchClientName(findClientName());

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
    this->packs.erase(this->packs.begin()+packPos);
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

//=================
// ==== SEARCH ====
//=================
vector<int> Agency::searchClientName(string inputname)
{
    vector<int> found;
    found.clear();
    found.push_back(-1);
    while (found.at(0) == -1)
    {
        for (int j = 0; j < clients.size(); j++)
        {
            if (clients.at(j).getName().find(inputname) != string::npos)
            {
                if (found.at(0) == -1)
                    found.at(0) = j;
                else
                    found.push_back(j);
            }
        }

        if (found.at(0) == -1)
        {
            cout << "There isn't a client with that name.\nTry again.";
            searchClientName(findClientName());
        }
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
                break;
            }
        }
        if (found == -1)
        {
            cout << "There isn't a client with that VAT/NIF number. Try again\n";
            searchClientNIF(findClientNIF());
        }
    }
    return found;
}

//==========================
// ==== EDIT AND CHANGE ====
//==========================
//WILL USE OTHER FUNCTIONS IN OTHER.CPP
void Agency::changeClientName()
{
    // DEC_WHICH ---> DECISE WHICH OF THE FOUND CLIENTS (IN vpos)
    cout << "\n\n==== SEARCH CLIENT NAME ====\n";
    vector<int> c_list = searchClientName(findClientName());

    cout << "\nSelect which client's NIF you wish to change\n";
    for (int j = 0; j < c_list.size(); j++)
        cout << clients.at(c_list.at(j)).getName() << "\n";
        
    int dec_which = validateInterfaceInput(1, c_list.size());
    clients.at(c_list.at(dec_which - 1)).setName(preChangeClientName());
}




void Agency::changeClientNIF()
{
    cout << "\n\n==== SEARCHING WITH NAME ====\n";
    vector<int> c_list = searchClientName(findClientName());
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
    vector<int> c_list = searchClientName(findClientName());
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
    vector<int> c_list = searchClientName(findClientName());
    cout << "\nSelect which client's ADDRESS you wish to change\n";
    int dec_which = validateInterfaceInput(1, c_list.size());
    clients.at(c_list.at(dec_which - 1)).setAddress(preChangeClientAddress());
}

//OTHER
int Agency::determineMoneySpentByClient(vector<unsigned int> packs_bought)
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

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency &agency)
{
    out << agency.name << endl
        << agency.VATnumber << endl
        << agency.URL << endl
        << agency.address << endl;

    return out;
}
