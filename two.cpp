#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int j = 1;
    int total = 0;

    while ((i < 4000000) || (j < 4000000)) {
        if (i % 2 == 0 && i < 4000000) { total += i; }
        if (j % 2 == 0 && j < 4000000) { total += j; }
        i = i + j;
        j = i + j;
    }
    cout << total << endl;
}