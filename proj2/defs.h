#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include "Agency.h"
using namespace std;
//DEFINITIONS AND MAIN LIB FOR HELPFUL FUNCTIONS

#ifdef _WIN32
#define clearScreen() system("cls");
#else
#define clearScreen() system("clear");
#endif

string pathToFile = "textfiles/";
string limit = "::::::::::";
const string AGENCY_FILE_NAME = "agency.txt";
string CLIENTS_FILE_NAME;
string PACKS_FILE_NAME;

// INSIDE READ.CPP ----> READING AND ORGANIZING
vector<string> readAgency(string agency_file_str);
vector<string> readClients(string clients_file_str);
vector<string> readPacks(string packs_file_str);
vector<Client> decomposeClients(vector<string> rawCL, string filename);
vector<Pack> decomposePacks(vector<string> rawPK, string filename);
Address string_to_address(string address_str);


// CLIENT MANAGEMENT
void addClient(vector<Client> &CL);
void editClient(vector<Client> &CL);
void removeClient(vector<Client> &CL);
void changeClientName(vector<Client> &CL);
void changeClientNIF(vector<Client> &CL);
void changeClient_famagr(vector<Client> &CL);
void changeClient_address(vector<Client> &CL);
void changeClientPacks(vector<Client> &CL);

// Pack MANAGEMENT
void addPack(vector<Pack> &PK);
void editPack(vector<Pack> &PK);
void removePack(vector<Pack> &PK);
void purchasePack(vector<Client> &CL, vector<Pack> &PK);

// WRITING TO FILES
void writeClients(vector<Client> CL, string filename);
void writePacks(vector<Pack> PK, string filename);

// INSIDE SEARCH or BROWSE
vector<int> searchClientName(vector<Client> CL);
int searchClientNIF(vector<Client> CL);
void printClient(vector<Client> CL, int i);
void printAllClients(vector<Client> CL);

int searchPack_ID(vector<Pack> PK);
void printAllPacks(vector<Pack> PK);

//CALC
void determinePacksMoney(vector<Pack> PK);

// INPUT DEALING FUNCTIONS
int stoint(const string &str, int &value);
int validateInterfaceInput(int a, int b);
void readline(string &str);
bool cin_test();

// Other Functions
vector<string> strtok_cpp(string h, string n);
void reset_pathToFile();
int numberOf(string fileName);
int numberOfR(string fileName); //useless for now at least
