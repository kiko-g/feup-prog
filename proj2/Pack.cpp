#include "Pack.h"

Pack::Pack(unsigned int id, vector<string> sites, Date inicio, Date fim, double precoPessoa, unsigned maxPessoas, unsigned nrSold){

  this->setId(id);
  this->setSites(sites);
  this->setBeginDate(begin);
  this->setEndDate(end);
  this->setPricePerPerson(pricePerPerson);
  this->setMaxPersons(maxPersons);
  this->setNrSold(nrSold);
}

  // metodos GET

unsigned Pack::getId() const
{
  return this->id;
}

vector<string> Pack::getSites() const
{
  return this->sites;
}

Date Pack::getBeginDate() const
{
  return this->begin;
}

Date Pack::getEndDate() const
{
  return this->end;
}

double Pack::getPricePerPerson() const
{
  return this->pricePerPerson;
}

unsigned Pack::getMaxPersons() const{

  return this->maxPersons;
}

unsigned Pack::getNrSold() const{

  return this->nrSold;
}

  // metodos SET

void Pack::setId(unsigned id){
  this->id = id;
}

void Pack::setSites(vector<string> sites){

  this->sites = sites;
}

void Pack::setBeginDate(Date begin){

  this->begin = begin;
}

void Pack::setEndDate(Date end){

  this->end = end;
}

void Pack::setPricePerPerson(double pricePerPerson){

  this->pricePerPerson=pricePerPerson;
}

void Pack::setMaxPersons(unsigned maxPersons){

  this->maxPersons=maxPersons;
}

void Pack::setNrSold(unsigned nrSold){

  this->nrSold=nrSold;
}


/*********************************
 * Show Pack information
 ********************************/  

// shows a Pack content 
ostream& operator<<(ostream& out, const Pack & pack){

  // REQUIRES IMPLEMENTATION
}
