#include "Client.h"

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address)
{  
    this->setName(name);
    this->setVATnumber(VATnumber);
    this->setFamilySize(familySize);
    this->setAddress(address);
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<int> packs, unsigned totalPurchased)
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

vector<int> Client::getPackList() const
{ return this->packs; }

unsigned Client::getTotalPurchased() const
{ return this->totalPurchased; }


//===== metodos SET =====
void Client::setName(string name)
{ this->name = name; }

void Client::setVATnumber(unsigned VATnumber)
{ this->VATnumber = VATnumber; }

void Client::setFamilySize(unsigned short familySize)
{ this->familySize = familySize; }

void Client::setAddress(Address address)
{ this->address = address; } 

void Client::setPackList(vector<int> &packs)
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
    out << client.name       << endl   
        << client.VATnumber  << endl
        << client.familySize << endl
        << client.address    << endl;
    for (size_t i = 0; i < client.packs.size(); i++)
    {
        out << client.packs.at(i);
        if(i != client.packs.size()-1) out << " ; ";
        
    }
    out << endl << client.totalPurchased;
    out << endl << LIMIT_STRING << endl;
    return out;
}
