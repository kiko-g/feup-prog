#include "Client.h"

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address)
{  
  this->setName(name);
  this->setVATnumber(VATnumber);
  this->setFamilySize(familySize);
  this->setAddress(address);
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> & packets, unsigned totalPurchased)
{  
  this->setName(name);
  this->setVATnumber(VATnumber);
  this->setFamilySize(familySize);
  this->setAddress(address);
  this->setPacketList(packets);
  this->setTotalPurchased(totalPurchased);
}

//GET methods

string Client::getName() const
{  
  return this->name; 
}
  
unsigned Client::getVATnumber() const
{ 
  return this->VATnumber;
}

unsigned short Client::getFamilySize() const
{  
  return this->familySize;
}

Address Client::getAddress() const
{  
  return this->address;
}

vector<Packet> Client::getPacketList() const
{  
  return this->packets;
}

unsigned Client::getTotalPurchased() const{
  
  return this->totalPurchased;
}
  
  // metodos SET
	  
void Client::setName(string nome){
  
  // REQUIRES IMPLEMENTATION 
}

void Client::setVATnumber(unsigned VATnumber){
  
  // REQUIRES IMPLEMENTATION 
}

void Client::setFamilySize(unsigned short familySize){
  
  // REQUIRES IMPLEMENTATION 
}
void Client::setAddress(Address address){
  
  // REQUIRES IMPLEMENTATION 
}
void Client::setPacketList(vector<Packet> & packets){
  
  // REQUIRES IMPLEMENTATION 
}
unsigned Client::setTotalPurchased(unsigned totalPurchased){
  
  // REQUIRES IMPLEMENTATION 
}
  
  // outros metodos

ostream& operator<<(ostream& out, const Client & client){

  // REQUIRES IMPLEMENTATION 

}
