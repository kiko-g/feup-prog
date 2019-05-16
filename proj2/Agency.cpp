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
    vector<Packet> packets = decomposePacks(packContent, agencyContent[5]);

    this->setName(agencyContent[0]);
    int VATnr;
    stoint(agencyContent[1], VATnr);
    this->setVATnumber(VATnr);

    string street; // street name
    unsigned short doorNumber; // door number
    string Floor; // Floor number ("-" is not applicable)
    string postalCode; // postal code
    string location; // site

    Address address = string_to_address(agencyContent[2]);
    
    this->setAddress(address);
    this->setURL(agencyContent[3]);

    this->setClients(clients);
    this->setPackets(packets);

    this->clientsInfoHasChanged = false;
    this->packetsInfoHasChanged = false;

    //this->maxClientsId = max_clients_id;
    //this->maxPacketsId = maxPackets_id;
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

vector<Packet> Agency::getPackets() const
{
    return this->packets; 
}

  
  // SET Methods

void Agency::setName(string name)
{
    this->name = name;  
}

void Agency::setVATnumber(unsigned VATnumber){
  
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

void Agency::setPackets(vector<Packet> & packets)
{
  this->packets = packets;
}

void Agency::addClients(Client client){
  this->clients.push_back(client);
  this->clientsInfoHasChanged = true;
}
void Agency::addPackets(Packet packet){
   this->packets.push_back(packet);
   this->packetsInfoHasChanged = true;
}

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency)
{
    //A IMPLEMENTATION REQUIRED 
}