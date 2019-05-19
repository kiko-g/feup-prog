#include "Menus.h"
//Definition of private functions

void mainMenu(Agency agency)
{
    while(1)
    {
        clearScreen();
        cout << "============== AGENCY INFO ==============\n";
        cout << agency;
        cout << "=============== MAIN MENU ===============\n";
        cout << "| 1 - "; cout << "Browse / Search\n";
        cout << "| 2 - "; cout << "Manage CLIENT data\n";
        cout << "| 3 - "; cout << "Manage PACK data\n";
        cout << "| 4 - "; cout << "EXIT\n";
        
        int input = validateInterfaceInput(1,4);

        switch(input)
        {
         case 1:
            browsingInterface(agency);
            break;

         case 2:
            //clientsInterface(agency);
            break;

         case 3:
            //packsInterface(agency);
            break;

         case 4:
            clearScreen();
            char vld;
            cout << "\nDo you wish to save all changes made? (Y/N)"; cin >> vld;
            if(vld == 'Y' || vld == 'y')
            {
                cout << "===== Saving all changes made =====\n";
                if(agency.getClientsIHC()) agency.saveClientsInfo("clientsnew.txt");
                if(agency.getPacksIHC()) agency.savePacksInfo("packsnew.txt");
            }
            
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
        cout << "| 3 - BACK\n";
        input = validateInterfaceInput(1, 3);

        switch (input)
        {
        case 1:
            browseClientsInterface(agency);
            break;

        case 2:
            browsePacksInterface(agency);
            break;

        case 3:
            return;
        }
    }
}

void browseClientsInterface(Agency agency)
{
    int input;
    while (1)
    {
        clearScreen();
        cout << "=== Client search engine options ===\n";
        cout << "| 1 - Name\n";
        cout << "| 2 - NIF\n";
        cout << "| 3 - View All Clients\n";
        cout << "| 4 - BACK\n";

        input = validateInterfaceInput(1, 4);
        switch (input)
        {
        case 1:
            // COISAS
            cout << "\nType '0' (zero) to go back to the MENU: ";
            while(input != 0){ 
                cin >> input;
                cin.ignore(1000, '\n');
            }
            break;

        case 2:
           // COISAS
            cout << "\nType '0' (zero) to go back to the MENU: ";
            while(input != 0){ 
                cin >> input;
                cin.ignore(1000, '\n');
            }
            break;

        case 3:
            agency.printAllClients();
            cout << "\nType '0' (zero) to go back to the MENU: ";
            while(input != 0){ 
                cin >> input;
                cin.ignore(1000, '\n');
            }
            break;

        case 4:
            return;
        }
    }
}

void browsePacksInterface(Agency agency)
{
    int input;
    while (1)
    {
        clearScreen();
        cout << "=== Pack search engine options ===\n";
        cout << "| 1 - \n";
        cout << "| 2 - \n";
        cout << "| 3 - View All Packs\n";
        cout << "| 4 - BACK\n";

        input = validateInterfaceInput(1, 4);
        switch (input)
        {
        case 1:
            // COISAS
            cout << "\nType '0' (zero) to go back to the MENU: ";
            while(input != 0){ 
                cin >> input;
                cin.ignore(1000, '\n');
            }
            break;

        case 2:
           // COISAS
            cout << "\nType '0' (zero) to go back to the MENU: ";
            while(input != 0){ 
                cin >> input;
                cin.ignore(1000, '\n');
            }
            break;

        case 3:
            agency.printAllPacks();
            cout << "\nType '0' (zero) to go back to the MENU: ";
            while(input != 0){ 
                cin >> input;
                cin.ignore(1000, '\n');
            }
            break;

        case 4:
            return;
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

        input = validateInterfaceInput(1,5);

        switch(input)
        {
         case 1:
            agency.addClients(preAddClient());
            break;

         case 2:
            editClients(agency); //menus
            break;

         case 3:
            agency.rmClients();
            break;

         case 4:
            //purchasePack(agency);
            break;

         case 5:
            return;
        }
    }
}


void editClients(Agency &agency)

