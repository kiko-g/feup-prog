#pragma once

#include <iostream>
#include <string>
#include <vector>


#include "../defs.h"
#include "Date.h"

using namespace std;

class Pack
{
 private:
  unsigned id; // pack unique identifier
  vector<string> sites; // touristic sites to visit
  Date begin;  // begin date
  Date end;  // end date
  double pricePerPerson; // price per person
  unsigned maxPersons; // number of persons still available in the pack (updated whenever the pack is sold to a new client)
  unsigned nrSold;
 public:
  Pack(unsigned int id, vector<string> sites, Date begin, Date end, double pricePerPerson, unsigned maxPersons,unsigned nrSold);

  // GET methods
  unsigned getId() const;
  vector<string> getSites() const;
  Date getBeginDate() const;
  Date getEndDate() const;
  double getPricePerPerson() const;
  unsigned getMaxPersons() const;
  unsigned getNrSold() const;

  // SET methods
  void setId(unsigned id);  // to set negatve if "deprecated"
  void setSites(vector<string> sites);
  void setBeginDate(Date begin);
  void setEndDate(Date end);
  void setPricePerPerson(double pricePerPerson);
  void setMaxPersons(unsigned maxPersons);
  void setNrSold(unsigned nrSold);

  // other methods

  friend ostream& operator<<(ostream& out, const Pack & pack);
};
