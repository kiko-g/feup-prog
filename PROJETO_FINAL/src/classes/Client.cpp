#include "Client.h"

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address)
{  
    this->setName(name);
    this->setVATnumber(VATnumber);
    this->setFamilySize(familySize);
    this->setAddress(address);
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<unsigned int> packs, unsigned totalPurchased)
{  
    this->setName(name);
    this->setVATnumber(VATnumber);
    this->setFamilySize(familySize);
    this->setAddress(address);
    this->setPackList(packs);
    this->setTotalPurchased(totalPurchased);
}

//===== GET methods =====
string Client::getName() const
{ return this->name; }
  
unsigned Client::getVATnumber() const
{ return this->VATnumber; }

unsigned short Client::getFamilySize() const
{ return this->familySize; }

Address Client::getAddress() const
{ return this->address; }

vector<unsigned int> Client::getPackList() const
{ return this->packs; }

unsigned Client::getTotalPurchased() const
{ return this->totalPurchased; }
  

//===== metodos SET =====
void Client::setName(string name)
{ this->name = name; }

void Client::setVATnumber(unsigned VATnumber)
{  
    if(VATnumber > 999999999 || VATnumber < 100000000)
    {
        cout << "Invalid Client VAT Number";
        exit(1); 
    }
    else
    {
        this->VATnumber = VATnumber;
    }
}

void Client::setFamilySize(unsigned short familySize)
{  
    if(familySize > 100 || familySize < 0)
    {
        cout << "Invalid Family Size";
        exit(1); 
    }
    else
    {
        this->familySize = familySize;
    } 
}
void Client::setAddress(Address address)
{ this->address = address; } 

void Client::setPackList(vector<unsigned int> & packs)
{ this->packs = packs; } 

void Client::setTotalPurchased(unsigned totalPurchased)
{  
    if(totalPurchased < 0)
    {
        cout << "Invalid client purchases";
        //return 0;
        exit(1);
    }
    else
    {
        this->totalPurchased = totalPurchased;
    }
}

// ===== OTHER METHODS =====
ostream& operator<<(ostream& out, const Client & client)
{
      cout << client.name << endl
       << client.VATnumber << endl
       << client.familySize << endl
       << client.address << endl;
    for (size_t i = 0; i < client.packs.size(); i++)
    {
        cout << client.packs.at(i);
        if(i != client.packs.size()-1) cout << " ; ";
        
    }
    cout << endl
    << LIMIT_STRING <<endl;
}
