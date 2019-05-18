/*#include "defs.h"
#include "writeFiles.h"

void write_clients(vector<Client> list, string filename)
{
    ofstream fout;

    fout.open(PATH_TO_DATA+filename);

    for (int i = 0; i < list.size(); i++)
    {
        fout << list.at(i).name << "\n";
        fout << list.at(i).NIF << "\n";
        fout << list.at(i).nFamAgr << "\n";
        fout << list.at(i).address.street << " | ";
        fout << list.at(i).address.doorNumber << " | ";
        fout << list.at(i).address.floor << " | ";
        fout << list.at(i).address.CP << " | ";
        fout << list.at(i).address.location << "\n";
        fout << list.at(i).packs_str << "\n";
        fout << limit << "\n";
    }
    fout.close();
}

void write_packs(vector<Pack> list, string filename)
{
    ofstream fout;
    reset_pathToFile();
    pathToFile += filename;
    fout.open(pathToFile);

    fout << list.at(list.size() - 1).id << "\n";
    for (int i = 0; i < list.size(); i++)
    {
        if (i != 0)
            fout << "\n";
        fout << list.at(i).id << "\n";
        fout << list.at(i).destination << "\n";
        fout << list.at(i).startDate.year << "/" << list.at(i).startDate.month << "/" << list.at(i).startDate.day << "\n";
        fout << list.at(i).endDate.year << "/" << list.at(i).endDate.month << "/" << list.at(i).endDate.day << "\n";
        fout << list.at(i).price_pp << "\n";
        fout << list.at(i).availableSeats << "\n";
        fout << list.at(i).soldSeats << "\n";
        fout << limit;
    }
    fout.close();
}
*/