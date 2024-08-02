#include <iostream>
using namespace std;

int main() {
    int total = 0;
    for (int i = 0; i < 1000; i++) {
        bool check = !((i % 3) && (i % 5));
        if (check) {
            total += i;
        }
    }
    cout << total << endl;
}