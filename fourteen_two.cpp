#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int max_starter = 1;
    int max = 0;

    for (int i = 1; i < 1000000; i++) {
        // this can overflow!
        unsigned int col = i;
        int counter = 1;
        while (col != 1) {
            if (col % 2 == 0) {
                col /= 2;
            }
            else {
                col = col * 3 + 1;
            }
            counter++;
        }
        if (counter > max) {
            max = counter;
            max_starter = i;
        }
    }

    cout << "Number " << max_starter << " has a Collatz chain of ";
    cout << max << "." << endl;
    return 0;
}