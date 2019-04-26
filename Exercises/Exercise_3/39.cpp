#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double f(double x) { return sqrt(4 - x*x); }	// f(x) = x^2 - 4*x + 3.5
double trapezio(const double a , const double b , const double h)
{
	const int n = abs(b-a)/h;
	double integral = 0;
	vector<double> values;

	for (int i=0 ; i<=n ; i++)
	{
		values.push_back(f(a + i*h));
	}
	
	for (int i=1 ; i<n ; i++)	integral += values.at(i);

	// The middle terms have coeficient 2
	integral *= 2;

	integral += values.at(0);	// y0
	integral += values.at(n);	// yn
	integral *= h/2;
	return integral;
}



int main()
{
	cout << fixed;
	cout.precision(6);

	const double a = -2;
	const double b = 2;
	double h = 0.1;

	double integral1 = trapezio(a , b , h);
	cout << "Using h as " << h << endl;
	cout << "Integral: " << integral1 << endl << endl;

	h /= 2;	// Diminish the step
	double integral2 = trapezio(a , b , h);
	cout << "Using h as " << h << endl;
	cout << "Integral: " << integral2 << endl << endl;

	h /= 2;	// Diminish the step
	double integral3 = trapezio(a , b , h);
	cout << "Using h as " << h << endl;
	cout << "Integral: " << integral3 << endl << endl;
    string ast;
	return 0;
}
