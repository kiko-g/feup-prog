#include "Address.h"

Address::Address(){}
Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location)
{
    this->setStreet(street);
    this->setDoorNumber(doorNumber);
    this->setFloor(floor);
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
    return this->floor;
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
    this->street = street;
}

void Address::setDoorNumber(unsigned short doorNumber)
{
      if(doorNumber > 10000)
    {
        cout << "Invalid doorNumber";
        exit(1); 
    }
    else
    {
        this->doorNumber = doorNumber;
    }
}

void Address::setFloor(string floor)
{   
    this->floor = floor;
}

void Address::setPostalCode(string postalCode)
{
    this->postalCode = postalCode;
}

void Address::setLocation(string location)
{
    this->location = location;
}


/*********************************
 *       Mostrar Address
 ********************************/  

// displays an address in a nice format
ostream& operator<<(ostream& out, const Address & address)
{
    out << address.street       << " | "
        << address.doorNumber   << " | "
        << address.floor        << " | "
        << address.postalCode   << " | "
        << address.location;
    return out;  
}
