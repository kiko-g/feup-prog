#include "Client.h"

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address){
  
  this->setName(name);
  this->setVATnumber(VATnumber);
  this->setFamilySize(familySize);
  this->setAddress(address);
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<Packet> & packets, unsigned totalPurchased){
  
  this->setName(name);
  this->setVATnumber(VATnumber);
  this->setFamilySize(familySize);
  this->setAddress(address);
  this->setPacketList(packets);
  this->setTotalPurchased(totalPurchased);
}

  // GET methods

string Client::getName() const{
  return this->name; 
}
  
unsigned Client::getVATnumber() const{
  
  return this->VATnumber;
}

unsigned short Client::getFamilySize() const{
  
  return this->familySize;
}

Address Client::getAddress() const{
  
  return this->address;
}

vector<Packet> Client::getPacketList() const{
  
  return this->packets;
}

unsigned Client::getTotalPurchased() const{
  
  return this->totalPurchased;
}
  
  // metodos SET
	  
void Client::setName(string nome){
  
  this->name = name; 
}

void Client::setVATnumber(unsigned VATnumber){
  
  if(VATnumber > 999999999 || VATnumber < 100000000){
    cout << "Invalid Client VAT Number";
    exit(-1); 
  }
  else{
    this->VATnumber = VATnumber;
  }
}

void Client::setFamilySize(unsigned short familySize){
  
  if(VATnumber > 100 || VATnumber < 0){
    cout << "Invalid Family Size";
    exit(-1); 
  }
  else{
    this->VATnumber = VATnumber;
  } 
}
void Client::setAddress(Address address){
 
  this->address = address;  
}
void Client::setPacketList(vector<Packet> & packets){

  this->packets = packets;  
}
unsigned Client::setTotalPurchased(unsigned totalPurchased){
  
  if(totalPurchased < 0){
    cout << "Invalid client purchases";
    exit(-1); 
  }
  else{
    this->totalPurchased = totalPurchased;
  } 
}
  
  // outros metodos

ostream& operator<<(ostream& out, const Client & client){

  // REQUIRES IMPLEMENTATION 

}
