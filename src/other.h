#pragma once
#include "defs.h"
#include "classes/Client.h"
#include "classes/Address.h"

//reading outside of the Agency
Client preAddClient();
Pack preAddPack();
string preRemoveClient();
string findClientName();
int findClientNIF();
int helpRead();
//==========
int findPackID();
string findPackLocation();
string findPackSpecificLocations();
Date findPackDate(string which);

//edit
string preChangeClientName();
int preChangeClientNIF();
int preChangeClientFamagr();
Address preChangeClientAddress();

//other
int determineGreaterDate(Date end, Date start);