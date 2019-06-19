#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <cmath>

//#include "../utils.h"
#include "../other.h"
#include "../defs.h"
#include "../readFiles.h"
#include "Address.h"
#include "Client.h"
#include "Pack.h"
using namespace std;

class Agency
{
 private:
  string name; // name of the  agency
  unsigned VATnumber; // VAT number of the agency
  Address address; // address of the agency
  string URL; // URL of the agency Web site
  vector<Client> clients; // vector to store the existing clients
  vector<Pack> packs; // vector to store the existing Packs
  
  vector<string> theNMostVisited;
  bool clientsInfoHasChanged; // flag that is set to "true" if at least one client has been changed/added/deleted
  bool packsInfoHasChanged; // flag that is set to "true" if at least one Pack has been changed/added/deleted
  unsigned maxClientsId; // maximum value among all clients identifiers
  unsigned maxPacksId; // maximum value among all Packs identifiers

 public:
  Agency(string agency_file_str);

  // GET methods
  string getName() const;
  unsigned getVATnumber() const;
  Address getAddress() const;
  string getURL() const;
  vector<Client> getClients() const;
  vector<Pack> getPacks() const;
  bool getClientsIHC() const; //IHC = Info Has Changed
  bool getPacksIHC() const;   //IHC = Info Has Changed
  vector<int> allPacksSold();
  vector<string> getMostVisited();

  // SET methods
  void setName(string name);
  void setClientsIHC(bool d);
  void setPacksIHC(bool d);
  void setVATnumber(unsigned VATnumber);
  void setAddress(Address address);
  void setURL(string url);
  void setClients(vector<Client> &clients);
  void setPacks(vector<Pack> &packs);
  void setMostVisited(vector<string> v);
  
  // SAVING FILES METHODS
  void saveClientsInfo(string filename);
  void savePacksInfo(string filename);

  // EDIT METHODS
  void addClients();
  void addPacks();
  void rmClients();
  void rmPacks(int packPos);
  void printAllClients();
  void printAllPacks();
  void printSomePacks(vector<int> somepacks);
  void printSomeClients(vector<int> someclients);
  void printOneClient(int client_pos);
  void printOnePack(int pack_pos);
  vector<int> getPacksPos(vector<int> p);
  // ============
  void changeClientName();
  void changeClientNIF();
  void changeClientFAM();
  void changeClientAddress();
  void purchasePack();
  void changePackDate(string which);
  void changePackSites();
  void changePricePerPerson();
  void changeMaxSeats();
  void changeSoldSeats();

  // SEARCH METHODS
  vector<int> searchClientName();
  int searchClientNIF(int NIF);

  int searchPackID(int ID);
  vector<int> searchPackMainLocation();
  vector<int> searchPacksBetweenDates(Date start, Date end);
  

  //OTHER
  int determineMaxClientID();
  int determineMaxPacksID();
  int determineMoneySpentByClient(vector<int> packs_bought);
  vector<int> packSaleStatus();
  void mostVisited(int n);
  void displayUnvisited();
  vector<string> getSitesVec(bool order);
  multimap<int,string> places_people();
  //int whichOfThese(int list_size);

  friend ostream& operator<<(ostream& out, const Agency &agency);

};
