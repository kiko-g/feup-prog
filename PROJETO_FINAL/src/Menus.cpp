#include "Menus.h"

void mainMenu(Agency &agency)
{
    backToMenu();
    while(1)
    {
        clearScreen();
        cout << "============== AGENCY INFO ==============\n";
        cout << agency << endl;
        cout << "=============== MAIN MENU ===============\n";
        cout << "| 1 - "; cout << "Browse / Search\n";
        cout << "| 2 - "; cout << "Manage CLIENT data\n";
        cout << "| 3 - "; cout << "Manage PACK data\n\n";
        cout << "| 4 - "; cout << "EXIT AND SAVE ALL CHANGES\n";
        cout << "| 5 - "; cout << "EXIT WITHOUT SAVING\n";
        
        int input = validateInterfaceInput(1,5);

        switch(input)
        {
         case 1:
            browsingInterface(agency);
            break;

         case 2:
            clientsInterface(agency);
            break;

         case 3:
            packsInterface(agency);
            break;

         case 4:
            clearScreen();
            cout << "===== Saving all changes made =====\n";
            if(agency.getClientsIHC()) agency.saveClientsInfo("clientsnew.txt");
            if(agency.getPacksIHC()) agency.savePacksInfo("packsnew.txt");
            
            cout << "\nExited with success.\n\n";
            exit(1);
            break;

        case 5:
            clearScreen();
            cout << "===== Exiting without saving =====";
            cout << "\nExited with success.\n\n";
            exit(1);
            break;
        }
    }
}

void browsingInterface(Agency agency)
{
    int input;
    while (1)
    {
        clearScreen();
        cout << "=========== BROWSING MENU ===========\n";
        cout << "| 1 - Clients\n";
        cout << "| 2 - Packs\n";
        cout << "| 3 - Status View amount of packs sold and profit\n\n";
        cout << "| 4 - BACK\n";
        input = validateInterfaceInput(0, 3);

        switch (input)
        {
        case 1:
            browseClientsInterface(agency);
            break;

        case 2:
            browsePacksInterface(agency);
            break;

        case 3:
            agency.packSaleStatus();
            return;

        case 0:
            return;
        }
    }
}

void browseClientsInterface(Agency agency)
{
    vector<int> res;
    int verif;
    int input;
    while (1)
    {
        clearScreen();
        cout << "=== CLIENT BROWSING ENGINE OPTIONS ===\n";
        cout << "| 1 - Search Client Name\n";
        cout << "| 2 - Search Client NIF\n";
        cout << "| 3 - View All Clients\n\n";
        cout << "| 4 - BACK\n";
        cout << "| 0 - MAIN MENU\n";

        input = validateInterfaceInput(0, 4);
        switch (input)
        {
        case 1:
            res = agency.searchClientName();
            agency.printSomeClients(res);
            backToMenu();
            break;

        case 2:
            verif=agency.searchClientNIF(findClientNIF());
            if(verif != -1) agency.printOneClient(verif);
            backToMenu();
            break;

        case 3:
            agency.printAllClients();
            backToMenu();
            break;

        case 4:
            return;

        case 0:
            mainMenu(agency);            
        }
    }
}

void browsePacksInterface(Agency agency)
{
    vector<int> h, g, f;
    vector<Client> h2;
    int input, which;
    while (1)
    {
        h.clear(); g.clear(); h2.clear();
        clearScreen();
        cout << "=== PACK BROWSING ENGINE OPTIONS ===\n";
        cout << "| 1 - Search Pack ID\n";
        cout << "| 2 - Search Pack MAIN DESTINATION\n";
        cout << "| 3 - Search Pack Between DATES\n";
        cout << "| 4 - View All Packs\n";
        cout << "| 5 - View SOLD Packs to ONE CLIENT\n";
        cout << "| 6 - View ALL SOLD Packs to ALL clients\n";
        cout << "| 7 - BACK\n";
        cout << "| 0 - MAIN MENU\n";

        input = validateInterfaceInput(0, 7);
        switch (input)
        {
        case 1:
            agency.printOnePack(agency.searchPackID(findPackID()));
            backToMenu();
            break;

        case 2:
            h = agency.searchPackMainLocation();
            agency.printSomePacks(h);
            
            backToMenu();
            break;

        case 3:
            agency.printSomePacks(agency.searchPacksBetweenDates(findPackDate("END"), findPackDate("START")));
            backToMenu();
            break;

        case 4:
            agency.printAllPacks();
            backToMenu();
            break;

        case 5:
            h=agency.searchClientName();
            agency.printSomeClients(h);
            which = validateInterfaceInput(1, h.size());
            //f gets pack IDs
            f=agency.getClients().at(h.at(which-1)).getPackList();
            //g transforms IDs into positions
            g=agency.getPacksPos(f);
            agency.printSomePacks(g);
            backToMenu();
            return;

        case 6:
            agency.printSomePacks(agency.allPacksSold());
            backToMenu();
            return;

        case 7:
            return;

        case 0:
            mainMenu(agency);
        }
    }
}


void clientsInterface(Agency &agency)
{
    int input;
    while(1)
    {
        clearScreen();
        cout << "=============== CLIENTS MENU ===============\n";
        cout << "| 1 - Add client\n";
        cout << "| 2 - Edit client\n";
        cout << "| 3 - Remove client\n";
        cout << "| 4 - Buy pack for a client\n\n";
        cout << "| 5 - BACK\n";
        cout << "| 0 - MAIN MENU\n";

        input = validateInterfaceInput(0,5);

        switch(input)
        {
         case 1:
            agency.addClients();
            break;

         case 2:
            editClients(agency); 
            break;

         case 3:
            agency.rmClients();
            break;

         case 4:
            agency.purchasePack();
            break;

         case 5:
            return;

         case 0:
             mainMenu(agency);
        }
    }
}


void editClients(Agency &agency)
{
    int input;
    while(1)
    {
        clearScreen();
        cout << "=============== EDIT CLIENTS MENU ===============\n";
        cout << "| 1 - Change client name\n";
        cout << "| 2 - Change client NIF/VAT (identifier)\n";
        cout << "| 3 - Change client FAN (Family Aggregate Number)\n";
        cout << "| 4 - Change client ADDRESS\n\n";
        cout << "| 5 - BACK\n";
        cout << "| 0 - MAIN MENU\n";

        input = validateInterfaceInput(0,5);

        switch(input)
        {
         case 1:
            agency.changeClientName();
            break;

         case 2:
            agency.changeClientNIF();
            break;

         case 3:
            agency.changeClientFAM();
            break;

         case 4:
            agency.changeClientAddress();
            break;

         case 5:
            return;

         case 0:
            mainMenu(agency);
        }
    }
}

void packsInterface(Agency &agency)
{
    vector<int> pk;
    int input;
    while (1)
    {
        clearScreen();
        cout << "=============== PACKS MENU ===============\n";
        cout << "| 1 - Add pack\n";
        cout << "| 2 - Edit pack\n";
        cout << "| 3 - Remove pack\n";
        cout << "| 4 - Buy pack for a client\n\n";
        cout << "| 5 - BACK\n";
        cout << "| 0 - MAIN MENU\n";

        input = validateInterfaceInput(0, 5);

        switch (input)
        {
        case 1:
            agency.addPacks();
            backToMenu();
            break;

        case 2:
            editPacks(agency);
            break;

        case 3:
            pk = agency.searchPackMainLocation();
            agency.printSomePacks(pk);
            agency.rmPacks(pk.at(validateInterfaceInput(1, pk.size())-1));
            backToMenu();
            break;

        case 4:
            agency.purchasePack();
            backToMenu();
            break;

        case 5:
            return;

        case 0:
            mainMenu(agency);
        }
    }
}

void editPacks(Agency &agency)
{
    vector<int> pk;
    vector<string> r;
    int which, input;
    while (1)
    {
        clearScreen();
        cout << "=============== EDIT PACKS MENU ===============\n";
        cout << "| 1 - Change pack begin date\n";
        cout << "| 2 - Change pack end date\n";
        cout << "| 3 - Change pack destination (full string)\n";
        cout << "| 4 - Change pack price per person\n";
        cout << "| 5 - Change pack max seats\n";
        cout << "| 6 - Change pack sold/reserved seats\n\n";
        cout << "| 7 - BACK\n";
        cout << "| 0 - MAIN MENU\n";

        input = validateInterfaceInput(0, 7);

        switch(input)
        {
        case 1:
            pk = agency.searchPackMainLocation();
            agency.printSomePacks(pk);
            which = validateInterfaceInput(1, pk.size());
            agency.getPacks().at(pk.at(which - 1)).setBeginDate(findPackDate("NEW BEGIN"));
            backToMenu();
            break;
        case 2:
            pk = agency.searchPackMainLocation();
            agency.printSomePacks(pk);
            which = validateInterfaceInput(1, pk.size());
            agency.getPacks().at(pk.at(which - 1)).setEndDate(findPackDate("NEW END"));
            backToMenu();
            break;

        case 3:
            pk = agency.searchPackMainLocation();
            agency.printSomePacks(pk);
            which = validateInterfaceInput(1, pk.size());
            r.push_back(findPackLocation());
            agency.getPacks().at(pk.at(which - 1)).setSites(r);
            backToMenu();
            break;

        case 4:
            agency.changeClientAddress();
            backToMenu();
            break;

        case 5:
            return;

        case 6:
            return;

        case 7:
            return;

        case 0:
            mainMenu(agency);
        }
    }
}
