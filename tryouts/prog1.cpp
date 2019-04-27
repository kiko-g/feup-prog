#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "p.h"
using namespace std;

class Rect
{
   private:
    double width;
    double height;

   public:
    Rect(double w, double h) { width = w; height = h; }
    double circum() { return width * height; }
};

int main()
{
    start(3);
    Rect foo (10, 5);      // functional form
    Rect baz {3, 15};      // uniform init.
    Rect qux = {4, 12};    // POD-like

    cout << "FOO: " << foo.circum() << "\n";
    cout << "BAZ: " << baz.circum() << "\n";
    cout << "QUX: " << qux.circum();
    end(3);
    return 0;
}