#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    for (int a = 1; a < 1000; a++) {
        for (int b = 1; b < 1000; b++) {
            int result = 2*a*a + 2*b*b;
            result += 2*a*b + (2*a+2*b) * (1000 - a - b);
            if (result == 1000000) {
                cout << a << " * " << b << " * " << (1000 - a - b);
                cout << " = " << (a * b * (1000 - a - b)) << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
