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

    //this->maxClientsId = max_clients_id;
    //this->maxPacksId = maxPacks_id;
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

void Agency::addClients(Client client)
{
    this->clients.push_back(client);
    this->clientsInfoHasChanged = true;
}
void Agency::addPacks(Pack Pack)
{
   this->packs.push_back(Pack);
   this->packsInfoHasChanged = true;
}

void Agency::rmClients(int clientPos){
  this->clients.erase(this->clients.begin()+clientPos);
  this->clientsInfoHasChanged = true;
}
void Agency::rmPackets(int packetPos){
   this->packets.erase(this->packets.begin()+packetPos);
   this->packetsInfoHasChanged = true;
}

// ==== SEARCH ====
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
        if(found == -1) cout << "There isn't a client with that VAT number. Try again";
    }
    return found;    
}



/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream &out, const Agency &agency)
{
    //A IMPLEMENTATION REQUIRED 
}