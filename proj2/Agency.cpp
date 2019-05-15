#include "Agency.h"

Agency::Agency(string agency_file_str)
{
    vector<string> content;
    string agency_file_str, line;
    ifstream fin;

    pathToFile = pathToFile + agency_file_str;
    fin.open(pathToFile);

    int count_fails = 0;
    if (fin.fail())
    {
        if (count_fails == 4)
        {
            "\n\nCheck filename in the folders...\nExiting now.";
            exit(1);
        }
        count_fails++;
        cerr << "File not found. Type a different file name below\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Type the name of the file (agency): ";
        cin >> agency_file_str;
    }

    while (!fin.eof())
    {
        getline(fin, line);
        if (line == "")
            continue;
        content.push_back(line);
    }

    cout << "Content successfully read from '" << agency_file_str << "'\n";

    fin.close();
    reset_pathToFile();
    
    this->setName(content[0]);
    int VATnr;
    stoint(content[1], VATnr);
    this->setVATnumber(VATnr);

    string street; // street name
    unsigned short doorNumber; // door number
    string floor; // floor number ("-" is not applicable)
    string postalCode; // postal code
    string location; // site

    funcao_a_implementar(const[2], street, doorNumber, floor, postalCode, location); //FUNÇÃO QUE DIVIDE AS CENAS
    
    Address adress(street, doorNumber, floor, postalCode, location);
    
    this->setAddress(adress);
    this->setURL(content[3]);

    //FALTA
    // CRIADOR DE VETOR CLIENTES + MAX CLIENTS ID
    // CRIADOR DE VETOR PACKETS + MAX PACKETS ID

    this->setClients(vetor de clients);
    this->setPackets(vetor de packets);

    this->clientsInfoHasChanged = false;
    this->packetsInfoHasChanged = false;
    this->maxClientsId = max_clients_id;
    this->maxPacketsId = max_packets_id;
}

  // metodos GET
string Agency::getName() const
{
  //  IMPLEMENTATION REQUIRED   
}

unsigned Agency::getVATnumber() const
{
  //  IMPLEMENTATION REQUIRED 
}

Address Agency::getAddress() const
{

  //  IMPLEMENTATION REQUIRED 
}

string Agency::getURL() const
{

  //  IMPLEMENTATION REQUIRED 
}

vector<Client> Agency::getClients() const
{

  //  IMPLEMENTATION REQUIRED 
}

vector<Packet> Agency::getPackets() const
{

  //  IMPLEMENTATION REQUIRED 
}

  
  // SET Methods

void Agency::setName(string name){

  this->name = name;  
}

void Agency::setVATnumber(unsigned VATnumber){

  //  IMPLEMENTATION REQUIRED 
}

void Agency::setAddress(Address address){

  //  IMPLEMENTATION REQUIRED 
}
  void Agency::setURL(string url){

  //  IMPLEMENTATION REQUIRED 

}
  void Agency::setClients(vector<Client> & clients){

  //  IMPLEMENTATION REQUIRED 

  }
  void Agency::setPackets(vector<Packet> & packets){

  //  IMPLEMENTATION REQUIRED 

}

/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
ostream& operator<<(ostream& out, const Agency & agency){

  // A IMPLEMENTATION REQUIRED 
}
