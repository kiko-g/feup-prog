#include <iostream>  
#include <string>
#include <iomanip>
#include <vector>   
using namespace std;

char int_to_ascii(int a)
{
    char b = a;
    return b;
}

vector<char> inttoascii_vec(vector<int> v)
{
    vector<char> charv;
    for(int i=0; i<v.size(); i++)
    {
        charv.push_back(int_to_ascii(v.at(i)));
    }
    return charv;
}

int main()
{
    cout << endl;

    vector <int> v;
    vector <char> charv;
    v.push_back(65);
    v.push_back(66);
    v.push_back(67);
    v.push_back(68);
    charv = inttoascii_vec(v);

    int i=0;
    int sz = v.size();

    cout << "Vector V (int): [ ";
    for(i=0; i<sz; ++i)
    {
       cout << v.at(i) << " "; 
    }
    cout << "]\nVector V (char): [ ";
    for(i=0; i<sz; ++i)
    {
       cout << charv.at(i) << " "; 
    }    
    cout << "]" << endl << endl;
}

/*
    string str = "7F05";
    string str1 = "ABC";
    size_t sz; 

    int i_dec = stoi (str, &sz, 16);
    cout << "\nstring: " << str << "\ni_dec: " << i_dec << "\n" << "sizez: " << sz << "\n";
*/