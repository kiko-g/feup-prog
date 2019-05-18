#include "Agency.h"
#include "defs.h"


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

    string street; // street name
    unsigned short doorNumber; // door number
    string Floor; // Floor number ("-" means not applicable)
    string postalCode; // postal code
    string location; // site

    Address address = string_to_address(agencyContent[2]);
    this->setAddress(address);
    
    this->setURL(agencyContent[3]);

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

  
// SET Methods
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
    this->name = name; 
}

void Agency::setClients(vector<Client> & clients)
{
    this->clients = clients; 
}

void Agency::setPacks(vector<Pack> & packs)
{
  this->packs = packs;
}


// OTHER METHODS
void Agency::addClients(Client client)
{
    this->clients.push_back(client);
    this->clientsInfoHasChanged = true;
}

void Agency::addPacks(Pack pack)
{
   this->packs.push_back(pack);
   this->packsInfoHasChanged = true;
}

void Agency::rmClients(int clientPos)
{
    this->clients.erase(this->clients.begin()+clientPos);
    this->clientsInfoHasChanged = true;
}
void Agency::rmPacks(int packPos)
{
    this->packs.erase(this->packs.begin()+packPos);
    this->packsInfoHasChanged = true;
}

//=================
// ==== SEARCH ====
//=================
vector<int> Agency::searchClientName(string inputname)
{
    vector<int> found;
    found.push_back(-1);
    while (found.at(0) == -1)
    {
        for (int j = 0; j < clients.size(); j++)
        {
            if (clients.at(j).getName().find(inputname) != string::npos)
            {
                if (found.at(0) == -1) found.at(0) = j;
                else found.push_back(j);
            }
        }

        if (found.at(0) == -1)
            cout << "There isn't a client with that name.\nTry again.";
    }
    return found;
}

int Agency::searchClientNIF(int NIF)
{
    int NIF;
    int found = -1;
    while(found == -1)
    {
        for(int i=0; i < clients.size(); i++)
        {
           if(NIF == clients.at(i).getVATnumber()) 
           {
              found = i;
              break;
           }
        }
        if(found == -1) cout << "There isn't a client with that VAT/NIF number. Try again";
    }
    return found;
}

//==========================
// ==== EDIT AND CHANGE ====
//==========================
void Agency::changeClientName(vector<int> c_list, string new_name)
{
    // DEC_WHICH ---> DECISE WHICH OF THE FOUND CLIENTS (IN vpos)
    int pos, dec_which;
    vector<int> vpos;
    cout << "\n\n==== SEARCH CLIENT NAME ====\n";
    //decide_search(); ---> soon
    vpos = searchClientName();
    for (int j = 0; j < vpos.size(); j++)
    {
        cout << clients.at(vpos.at(j)).getName() << "\n";
    }
    cout << "\nSelect which client's name you wish to change\n";
    dec_which = validateInterfaceInput(1, vpos.size());
    //
    clients.at(vpos.at(dec_which - 1)).getName() = new_name;

    for (int j = 0; j < c_list.size(); j++)
        cout << clients.at(c_list.at(j)).getName() << "\n";
    
    clients.at(c_list.at(dec_which - 1)).setName(new_name);
}




void Agency::changeClientNIF(vector<int> c_list, int NIF)
{
    int dec_which;
    cout << "\nSelect which client's NIF you wish to change\n";
    dec_which = validateInterfaceInput(1, c_list.size());
    for (int j = 0; j < c_list.size(); j++)
       cout << clients.at(c_list.at(j)).getName() << " | NIF: "
            << clients.at(c_list.at(j)).getVATnumber() << "\n";

    clients.at(c_list.at(dec_which - 1)).setVATnumber(NIF);
}




void Agency::changeClientFAM(vector<int> c_list, int familyPeopleNr)
{
    int dec_which;
    for (int j=0; j < c_list.size(); j++)
      cout << clients.at(c_list.at(j)).getName() << " | N FAM AGR: " << clients.at(c_list.at(j)).getFamilySize() << "\n";

    cout << "\nSelect which client's Family Agregate Number you wish to change\n";
    dec_which = validateInterfaceInput(1, c_list.size());
    clients.at(c_list.at(dec_which - 1)).setFamilySize(familyPeopleNr);
}

void Agency::changeClientAddress(vector<int> c_list, Address A)
{
    int dec_which;
    cout << "\nSelect which client's ADDRESS you wish to change\n";
    dec_which = validateInterfaceInput(1, c_list.size());
    clients.at(c_list.at(dec_which - 1)).setAddress(A);
}    





//OTHER
int Agency::determineMoneySpentByClient(vector<unsigned int> packs_bought)
{
    packs_bought.at(0);
}

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream &out, const Agency &agency)
{
    //A IMPLEMENTATION REQUIRED 
}