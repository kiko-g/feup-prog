#include "Packet.h"

Packet::Packet(unsigned int id, vector<string> sites, Date inicio, Date fim, double precoPessoa, unsigned maxPessoas, unsigned nrSold){

  this->setId(id);
  this->setSites(sites);
  this->setBeginDate(begin);
  this->setEndDate(end);
  this->setPricePerPerson(pricePerPerson);
  this->setMaxPersons(maxPersons);
  this->setNrSold(nrSold);
}

  // metodos GET

unsigned Packet::getId() const
{
  return this->id;
}

vector<string> Packet::getSites() const
{
  return this->sites;
}

Date Packet::getBeginDate() const
{
  return this->begin;
}

Date Packet::getEndDate() const
{
  return this->end;
}

double Packet::getPricePerPerson() const
{
  return this->pricePerPerson;
}

unsigned Packet::getMaxPersons() const{

  return this->maxPersons;
}

unsigned Packet::getNrSold() const{

  return this->nrSold;
}

  // metodos SET

void Packet::setId(unsigned id){
  this->id = id;
}

void Packet::setSites(vector<string> sites){

  this->sites = sites;
}

void Packet::setBeginDate(Date begin){

  this->begin = begin;
}

void Packet::setEndDate(Date end){

  this->end = end;
}

void Packet::setPricePerPerson(double pricePerPerson){

  this->pricePerPerson=pricePerPerson;
}

void Packet::setMaxPersons(unsigned maxPersons){

  this->maxPersons=maxPersons;
}

void Packet::setNrSold(unsigned nrSold){

  this->nrSold=nrSold;
}


/*********************************
 * Show Packet information
 ********************************/  

// shows a packet content 
ostream& operator<<(ostream& out, const Packet & packet){

  // REQUIRES IMPLEMENTATION
}
