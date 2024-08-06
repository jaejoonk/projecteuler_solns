#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    map<int, int> dict;

    for (int i = 1; i < 1000000; i++) {
        // this can overflow!
        unsigned int col = i;
        int counter = 1;
        while (col != 1) {
            if (dict.count(col) > 0) {
                dict[i] = counter + dict[col] - 1;
                break;
            }
            if (col % 2 == 0) {
                col /= 2;
            }
            else {
                col = col * 3 + 1;
            }
            counter++;
        }

        if (col == 1) {
            dict[i] = counter;
        }
    }

    int max = 0;
    int max_starter = 1;

    for (int i = 1; i < 1000000; i++) {
        if (dict[i] > max) {
            max = dict[i];
            max_starter = i;
        }
    }

    cout << "Number " << max_starter << " has a Collatz chain of ";
    cout << max << "." << endl;
    return 0;
}