#pragma once
using namespace std;

void invert_vect(vector<int> &v);               // Inverts vector
void print_vect(vector<int> v);                 // Shows vector inside [ ]
void fill_vec_rand(vector<int> &v, int n);      // Numbers from 0 to (n-1)

void start(int color); //3 --> blue             // Peachy start
void end(int color);                            // Peachy ending
void setcolor(int color);                       // Change terminal print color, uses windows.h
vector<string> strtok_cpp(string h, string n);
int stoint(const string &str, int &value);