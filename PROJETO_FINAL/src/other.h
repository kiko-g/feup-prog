#pragma once
#include "defs.h"
#include "classes/Client.h"
#include "classes/Address.h"

//reading outside of the Agency
Client preAddClient();
string preRemoveClient();
int findClientNIF();        
string findClientName();

//edit
string preChangeClientName();
int preChangeClientNIF();
int preChangeClientFamagr();
Address preChangeClientAddress();