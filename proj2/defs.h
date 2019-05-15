#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <limits>

#include "read.cpp"

#include "Agency.h"
#include "Client.h"
#include "Date.h"
#include "Packet.h"
#include "Address.h"

using namespace std;

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
vector<string> read_agency(string agency_file_str);
vector<string> read_clients(string clients_file_str);
vector<string> read_packs(string packs_file_str);
vector<Client> decompose_clients(vector<string> rawCL, string filename);
Address string_to_address(string address_str);


// CLIENT MANAGEMENT
void add_client(vector<Client> &CL);
void edit_client(vector<Client> &CL);
void remove_client(vector<Client> &CL);
void change_client_name(vector<Client> &CL);
void change_client_NIF(vector<Client> &CL);
void change_client_famagr(vector<Client> &CL);
void change_client_address(vector<Client> &CL);
void change_client_packs(vector<Client> &CL);

// PACK MANAGEMENT
void add_pack(vector<Pack> &PK);
void edit_pack(vector<Pack> &PK);
void remove_pack(vector<Pack> &PK);
void purchase_pack(vector<Client> &CL, vector<Pack> &PK);

// WRITING TO FILES
void write_clients(vector<Client> CL, string filename);
void write_packs(vector<Pack> PK, string filename);

//SEARCH or BROWSE
//CLIENTS
vector<int> search_client_name(vector<Client> CL);
int search_client_NIF(vector<Client> CL);
void print_client(vector<Client> CL, int i);
void print_all_clients(vector<Client> CL);

//SEARCH or BROWSE
//PACKS
int search_pack_ID(vector<Pack> PK);
void print_all_packs(vector<Pack> PK);

//INTERFACES
void init_navigation(vector<Client> CL, vector<Pack> PK);
void main_interface(vector<Client> CL, vector<Pack> PK);
void clients_interface(vector<Client> &CL, vector<Pack> &PK);
void packs_interface(vector<Client> &CL, vector<Pack> &PK);
void browsing_interface(vector<Client> CL, vector<Pack> PK);
// ========
void browse_clients_interface(vector<Client> CL, vector<Pack> PK);
void browse_packs_interface(vector<Client> CL, vector<Pack> PK);

//CALC
void determine_packs_money(vector<Pack> PK);

// INPUT DEALING FUNCTIONS
int stoint(const string &str, int &value);
int validate_interface_input(int a, int b);
void readline(string &str);
bool cin_test();

// Other Functions
vector<string> strtok_cpp(string h, string n);
void reset_pathToFile();
int numberOf(string fileName);
int numberOfR(string fileName); //useless for now at least

// STYLE BASED FUNCTIONS

/* 
void start(int color);
void end(int color);
    void setcolor(int color); (see below)
COLOR REFERS TO:
1_DARK BLUE | 2_GREEN | 3_BLUE | 4_RED
5_PURPLE | 6_YELLOW | 7_WHITE

#ifdef _WIN32
	#include <windows.h>
    #define setcolor(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
	#define setcolor(color) void
#endif

*/