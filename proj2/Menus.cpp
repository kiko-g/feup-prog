#include "Menus.h"
#include "defs.h"
<<<<<<< HEAD
=======
/*
unsigned mainMenu(Agency agency){
>>>>>>> 6de247dca1988c2a3f195e70c3f283e10d7b3f96

unsigned mainMenu(Agency agency)
{
    int input;
    while(1)
    {
        clearScreen();
        cout << "=============== MAIN MENU ===============\n";
        cout << "| 1 - "; cout << "Browse / Search\n";
        cout << "| 2 - "; cout << "Manage CLIENT data\n";
        cout << "| 3 - "; cout << "Manage PACK data\n\n";
        cout << "| 4 - "; cout << "EXIT\n";
        
        input = validate_interface_input(1,4);

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
            cout << "\nExited with success.\n\n";
            exit(1);
            break;
        } 

    }
}


// DEALING WITH OPTION 1
void browsingInterface(Agency agency)
{
    int input;
    while (1)
    {
        clearScreen();
        cout << "=========== BROWSING MENU ===========\n";
        cout << "| 1 - Clients\n";
        cout << "| 2 - Packs\n\n";
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
    int condition = -1;
    vector<int> vpos;
    while (1)
    {
        if(condition != 0) clearScreen();
        condition = -1;
        cout << "=== Client search engine options ===\n";
        cout << "| 1 - Name\n";
        cout << "| 2 - NIF\n";
        cout << "| 3 - View All Clients\n\n";
        cout << "| 4 - BACK\n";

        input = validateInterfaceInput(1, 4);
        switch (input)
        {
        case 1:
            cout << "\n== SEARCH NAME ==\n";
            int decwhich;
            vpos = searchClientName(CL);

            for (int j = 0; j < vpos.size(); j++)
            {
                cout << CL.at(vpos.at(j)).name << "\n";
            }
            cout << "\nSelect which one you wish to view, ";
            decwhich = validateInterfaceInput(1, vpos.size());
            printClient(CL, decwhich - 1);
            cout << "\nType '0' (zero) to see just the recent MENU: ";
            cin >> condition; while(!cin_test) cin >> condition;
            break;

        case 2:
            printClient(CL, searchClientNIF(CL));
            cout << "\nType '0' (zero) to see just the recent MENU: ";
            cin >> condition; while(!cin_test) cin >> condition;
            break;

        case 3:
            print_all_clients(CL);
            cout << "\nType '0' (zero) to see just the recent MENU: ";
            cin >> condition; while(!cin_test) cin >> condition;
            break;

        case 4:
            return;
        }
    }
}

void browse_packs_interface(Agency agency)
{
    int input;
    clearScreen();
    cout << "=== Pack search engine options ===\n";
    cout << "| 1 - View All Packs\n";
    cout << "| 2 - View All Packs\n";
    cout << "| 3 - View All Packs\n";
    cout << "| 4 - View All Packs\n";
    cout << "| 5 - BACK\n";

    input = validate_interface_input(1, 3);
    switch (input)
    {
    case 1:
        search_pack_ID(PK);
        break;

    case 2:
        return;
    }
}



// DEALING WITH OPTION 2
void clients_interface(Agency agency)
{
    int input;
    while(1)
    {
        clearScreen();
        cout << "=============== CLIENTS MENU ===============\n";
        cout << "| 1 - Add client\n";
        cout << "| 2 - Edit client\n";
        cout << "| 3 - Remove client\n";
        cout << "| 4 - Client pack purchase\n\n";
        cout << "| 5 - BACK\n";

        input = validate_interface_input(1,5);

        switch(input)
        {
         case 1:
            add_client(CL);
            break;

         case 2:
            edit_client(CL);
            break;

         case 3:
            remove_client(CL);
            break;

         case 4:
            purchase_pack(CL, PK);
            break;

         case 5:
            return;
        }
    }
}



// DEALING WITH OPTION 3
void packs_interface(Agency agency)
{
    int input = -1;
    while(1)
    {
        if(input != 4) clearScreen();
        cout << "=============== PACKS MENU ===============\n";
        cout << "| 1 - "; cout << "Add pack\n";
        cout << "| 2 - "; cout << "Edit pack\n";
        cout << "| 3 - "; cout << "Remove pack\n";
        cout << "| 4 - "; cout << "View agency pack profit\n\n";
        cout << "| 5 - "; cout << "BACK\n";

        input = validate_interface_input(1,4);

        switch(input)
        {
            case 1:
            add_pack(PK);
            break;

            case 2:
            edit_pack(PK);
            break;

            case 3:
            remove_pack(PK);
            break;

            case 4:
            determine_packs_money(PK);
            break;

            case 5:
            return;
        }
        write_packs(PK, packs_file);
    }
}
*/