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


/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency){

  cout << agency.name << endl
       << agency.VATnumber << endl
       << agency.URL << endl
       << agency.address << endl;

}
