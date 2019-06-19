#include "Pack.h"

Pack::Pack(int id, vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned maxPersons, unsigned nrSold)
{
  this->setId(id);
  this->setSites(sites);
  this->setBeginDate(begin);
  this->setEndDate(end);
  this->setPricePerPerson(pricePerPerson);
  this->setMaxPersons(maxPersons);
  this->setNrSold(nrSold);
}

  // metodos GET

int Pack::getId() const
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

void Pack::setId(int id)
{
    this->id = id;
}

void Pack::setSites(vector<string> sites)
{
    this->sites = sites;
}

void Pack::setBeginDate(Date begin)
{
    this->begin = begin;
}

void Pack::setEndDate(Date end)
{
    this->end = end;
}

void Pack::setPricePerPerson(double pricePerPerson)
{
    this->pricePerPerson = pricePerPerson;
}

void Pack::setMaxPersons(unsigned maxPersons)
{
    this->maxPersons = maxPersons;
}

void Pack::setNrSold(unsigned nrSold)
{
  this->nrSold = nrSold;
}


/*********************************
 * Show Pack information
 ********************************/  

// shows a Pack content ---> correct format 
ostream& operator<<(ostream& out, const Pack & pack)
{
    out << pack.id << endl << pack.sites.at(0);
    if(pack.sites.size()>1) out << " - "; 

    for (size_t i = 1; i < pack.sites.size(); i++)
    {
        out << pack.sites.at(i);
        if (i != pack.sites.size() - 1)
            out << ", ";
    }
    out << endl
        << pack.begin << endl
        << pack.end << endl
        << pack.pricePerPerson << endl
        << pack.maxPersons << endl
        << pack.nrSold << endl
        << LIMIT_STRING << endl;

    return out;
}