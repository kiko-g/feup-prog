#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Address
{
 private:
  string street; // street name
  unsigned short doorNumber; // door number
  string Floor; // Floor number ("-" is not applicable)
  string postalCode; // postal code
  string location; // site

 public:
  Address();
  Address(string street, unsigned short doorNumber, string Floor, string postalCode, string location);

  // metodos GET
  string getStreet() const;
  unsigned short getDoorNumber() const;
  string getFloor() const;
  string getPostalCode() const;
  string getLocation() const;
  
  // metodos SET
  void setStreet(string street);
  void setDoorNumber(unsigned short doorNumber);
  void setFloor(string Floor);
  void setPostalCode(string postalCode);
  void setLocation(string  location);

  // outros */
  
  friend ostream& operator<<(ostream& out, const Address & address);

};
