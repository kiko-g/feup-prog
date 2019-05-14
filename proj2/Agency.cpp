#include "Agency.h"
#include "myLib.h"

Agency::Agency(string fileName){
    
    ifstream fp;
    fp.open(fileName);
  
    if(!fp.is_open()) {
      cout << "Error, "<< fileName <<" file not found" << endl;
      exit(1);
    }





}

  // metodos GET
string Agency::getName() const
{
  //  IMPLEMENTATION REQUIRED 
}

unsigned Agency::getVATnumber() const
{
  //  IMPLEMENTATION REQUIRED 
}

Address Agency::getAddress() const
{

  //  IMPLEMENTATION REQUIRED 
}

string Agency::getURL() const
{

  //  IMPLEMENTATION REQUIRED 
}

vector<Client> Agency::getClients() const
{

  //  IMPLEMENTATION REQUIRED 
}

vector<Packet> Agency::getPackets() const
{

  //  IMPLEMENTATION REQUIRED 
}

  
  // SET Methods

void Agency::setName(string name){

  //  IMPLEMENTATION REQUIRED 
}

void Agency::setVATnumber(unsigned VATnumber){

  //  IMPLEMENTATION REQUIRED 
}

void Agency::setAddress(Address address){

  //  IMPLEMENTATION REQUIRED 
}
  void Agency::setURL(string url){

  //  IMPLEMENTATION REQUIRED 

}
  void Agency::setClients(vector<Client> & clients){

  //  IMPLEMENTATION REQUIRED 

  }
  void Agency::setPackets(vector<Packet> & packets){

  //  IMPLEMENTATION REQUIRED 

}

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency){

  // A IMPLEMENTATION REQUIRED 
}
