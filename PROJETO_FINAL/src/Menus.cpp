#include "Menus.h"

//Definition of private functions
void browsingInterface(Agency agency);
void browseClientsInterface(Agency agency);
void browsePacksInterface(Agency agency);
void clearScreenTemp(int n);
int validateInterfaceInput(int a, int b);

unsigned mainMenu(Agency agency)
{

    while(1)
    {
        clearScreenTemp(50);
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
            clearScreenTemp(50);
            cout << "\nExited with success.\n\n";
            exit(1);
            break;
        } 

    }
    return 0;
}

void browsingInterface(Agency agency)
{
    int input;
    while (1)
    {
        clearScreenTemp(50);
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
        clearScreenTemp(50);
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
        clearScreenTemp(50);
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

int validateInterfaceInput(int a, int b)
{
	int n;
	bool valid = false;

	while (!valid)
	{
		cout << "Type your option [" << a << "-" << b << "]: ";
        cin >> n;
        if (a<=n && b>=n && !cin.fail())
        {
			valid = true;
			cin.ignore(1000, '\n');
		}
        
		else 
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Try again. Number should be between " << a << " and " << b << "\n\n"; 
		}
	}
	return n;
}

void clearScreenTemp(int n){
    for (size_t i = 0; i < n; i++)
    {
        cout << endl;
    }
    
}
    
