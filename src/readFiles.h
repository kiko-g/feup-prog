#include <vector>
#include <string>
#include <fstream>
#include "defs.h"
#include "utils.h"

#include "classes/Client.h"
#include "classes/Pack.h"
#include "classes/Address.h"
using namespace std;

vector<string> readAgency(string agency_file_str);

vector<string> readClients(string clients_file_str);

vector<string> readPacks(string packs_file_str);

vector<Client> decomposeClients(vector<string> rawCL, string filename);

vector<Pack> decomposePacks(vector<string> rawPK, string filename);
