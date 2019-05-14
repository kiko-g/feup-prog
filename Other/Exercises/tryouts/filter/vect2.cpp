#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "p.h"
using namespace std;

void fill_vec_rand(vector<int> &v, int n)
{
    srand((unsigned)time(NULL));
    int i = 0;
    int b;
    while (i < 6)
    {
        b = rand() % n;
        v.push_back(b);
        i++;
    }
}

int main()
{
    start(2);
    vector<int> v;
    fill_vec_rand(v, 10);

    cout << "Before inversion: "; print_vect(v);
    cout << "Front: " << v.front();
    cout << "\nBack: " << v.back();

    invert_vect(v);

    cout << "\n\nAfter inversion: "; print_vect(v);
    cout << "Front: " << v.front();
    cout << "\nBack: " << v.back();

    end(2);
}