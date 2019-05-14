#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int nletstr_count(string str, char letter)
{
    static int ct = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str.at(i) == letter) ct++;
    }
    return ct;
}

int main()
{
    cout << "\n";
    vector<vector<int>> v;
    srand((unsigned)time(NULL));
    int i, j;
    int b; 
    for (i = 0; i < 5; i++)
    {
        v.push_back(vector<int>());
        cout << "SUBVECTOR "<< i+1 << ":\t"; 
        for(j = 0; j < 5; j++)
        {
            int b = rand() % 20 + 1;
            v.at(i).push_back(b);
            cout << v.at(i).at(j) << "\t";
        }
        cout << endl;
    }
    cout << "\n";
}