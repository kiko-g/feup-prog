#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "defs.h"
#include "Address.h"
#include "Client.h"
#include "Pack.h"
using namespace std;

class Agency
{
 private:
  string name; // name of the  agency
  unsigned int VATnumber; // VAT number of the agency aka NIF
  Address address; // address of the agency
  string URL; // URL of the agency Web site
  vector<Client> clients; // vector to store the existing clients
  vector<Pack> packs; // vector to store the existing Packs
  
  bool clientsInfoHasChanged; //\ flag that is set to "true" if at least one client has been changed/added/deleted
  bool packsInfoHasChanged; // flag that is set to "true" if at least one Pack has been changed/added/deleted
  unsigned int maxClientsId; // maximum value among all clients identifiers
  unsigned int maxPacksId; // maximum value among all Packs identifiers

 public:
  Agency(string agency_file_str);

  // GET methods
  string getName() const;
  unsigned getVATnumber() const;
  Address getAddress() const;
  string getURL() const;
  vector<Client> getClients() const;
  vector<Pack> getPacks() const;

    // SET methods
  void setName(string name);
  void setVATnumber(unsigned VATnumber);
  void setAddress(Address address);
  void setURL(string url);
  void setClients(vector<Client> & clients);
  void setPacks(vector<Pack> & packs);
  
  // EDIT METHODS
  void addClients(Client client);
  void addPacks(Pack pack);
  void rmClients(int clientPos);
  void rmPacks(int packPos);
  // ============
  void changeClientName(vector<int> c_list, string new_name);
  void changeClientNIF(vector<int> c_list, int NIF);
  void changeClientFAM(vector<int> c_list, int familyPeopleNr);
  void changeClientAddress(vector<int> c_list, Address A);

  // SEARCH METHODS
  vector<int> searchClientName(string name);
  int searchClientNIF(int NIF);

  //OTHER
  int Agency::determineMoneySpentByClient(vector <unsigned int> packs_bought);

  friend ostream& operator<<(ostream& out, const Agency & agency);

};