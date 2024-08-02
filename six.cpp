#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += (i*i*i - i*i);
    }
    cout << sum << endl;
    return 0;
}
