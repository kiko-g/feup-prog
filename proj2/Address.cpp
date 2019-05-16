#include "Address.h"

Address::Address(){}
Address::Address(string street, unsigned short doorNumber, string Floor, string postalCode, string location)
{
  this->setStreet(street);
  this->setDoorNumber(doorNumber);
  this->setFloor(Floor);
  this->setPostalCode(postalCode);
  this->setLocation(location);
}

  // metodos GET

string Address::getStreet() const
{
  return this->street;
}

unsigned short Address::getDoorNumber() const
{
  return this->doorNumber;
}

string Address::getFloor() const
{
  return this->Floor;
}

string Address::getPostalCode() const
{
  return this->postalCode;
}

string Address::getLocation() const
{
  return this->location;
}

  // metodos SET

void Address::setStreet(string street)
{
  // REQUIRES IMPLEMENTATION
}

void Address::setDoorNumber(unsigned short doorNumber)
{
  // REQUIRES IMPLEMENTATION
}

void Address::setFloor(string Floor)
{
  // REQUIRES IMPLEMENTATION
}

void Address::setPostalCode(string postalCode)
{
  // REQUIRES IMPLEMENTATION
}

void Address::setLocation(string  location)
{
  // REQUIRES IMPLEMENTATION
}


/*********************************
 * Mostrar Address
 ********************************/  

// discplyes an address in a nice format
ostream& operator<<(ostream& out, const Address & address)
{
  // REQUIRES IMPLEMENTATION
}
