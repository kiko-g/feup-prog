#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
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
string PacketS_FILE_NAME;

// "ADDRESS.H" BELOW
class Address
{
private:
    string street;             // street name
    unsigned short doorNumber; // door number
    string floor;              // floor number ("-" is not applicable)
    string postalCode;         // postal code
    string location;           // site

public:
    Address();
    Address(string street, unsigned short doorNumber, string floor, string postalCode, string location);

    // metodos GET
    string getStreet() const;
    unsigned short getDoorNumber() const;
    string getFloor() const;
    string getPostalCode() const;
    string getLocation() const;

    // metodos SET
    void setStreet(string street);
    void setDoorNumber(unsigned short doorNumber);
    void setFloor(string floor);
    void setPostalCode(string postalCode);
    void setLocation(string location);

    // outros */

    friend ostream &operator<<(ostream &out, const Address &address);
};

#ifdef _WIN32
#define clearScreen() system("cls");
#else
#define clearScreen() system("clear");
#endif

// INSIDE READ.CPP ----> READING AND ORGANIZING
vector<string> readAgency();
vector<string> readClients(string clients_file_str);
vector<string> readPackets(string Packets_file_str);

// CLIENT MANAGEMENT
void addClient(vector<Client> &CL);
void editClient(vector<Client> &CL);
void removeClient(vector<Client> &CL);
void changeClientName(vector<Client> &CL);
void changeClientNIF(vector<Client> &CL);
void changeClientFamagr(vector<Client> &CL);
void changeClientAddress(vector<Client> &CL);
void changeClientPackets(vector<Client> &CL);

// Packet MANAGEMENT
void addPacket(vector<Packet> &PK);
void editPacket(vector<Packet> &PK);
void removePacket(vector<Packet> &PK);
void purchasePacket(vector<Client> &CL, vector<Packet> &PK);

// WRITING TO FILES
void writeClients(vector<Client> CL, string filename);
void writePackets(vector<Packet> PK, string filename);

//SEARCH or BROWSE
//CLIENTS
vector<int> searchClientName(vector<Client> CL);
int searchClientNIF(vector<Client> CL);
void printClient(vector<Client> CL, int i);
void printAllClients(vector<Client> CL);

//SEARCH or BROWSE
//PacketS
int search_Packet_ID(vector<Packet> PK);
void print_all_Packets(vector<Packet> PK);

//INTERFACES
void init_navigation(vector<Client> CL, vector<Packet> PK);
void main_interface(vector<Client> CL, vector<Packet> PK);
void clients_interface(vector<Client> &CL, vector<Packet> &PK);
void Packets_interface(vector<Client> &CL, vector<Packet> &PK);
void browsing_interface(vector<Client> CL, vector<Packet> PK);
// ========
void browseClients_interface(vector<Client> CL, vector<Packet> PK);
void browse_Packets_interface(vector<Client> CL, vector<Packet> PK);

//CALC
void determine_Packets_money(vector<Packet> PK);

// INPUT DEALING FUNCTIONS
int stoint(const string &str, int &value);
int validate_interface_input(int a, int b);
void readline(string &str);
bool cin_test();

// Other Functions
vector<string> strtokCpp(string h, string n);
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