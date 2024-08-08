#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> dict = {
        {1, 3}, {2, 3}, {3, 5}, {4, 4}, {5, 4},
        {6, 3}, {7, 5}, {8, 5}, {9, 4}, {10, 3},
        {11, 6}, {12, 6}, {13, 8}, {14, 8}, {15, 7},
        {16, 7}, {17, 9}, {18, 8}, {19, 8}, {20, 6},
        {30, 6}, {40, 5}, {50, 5}, {60, 5}, {70, 7}, 
        {80, 6}, {90, 6}, {100, 7}
    };

    int sum = 0;
    int sum_to_hundred = 0;
    int thousand = 11;
    // add the under hundreds
    for (int i = 1; i < 100; i++) {
        if (i <= 20) { sum_to_hundred += dict[i]; }
        else {
            if (i % 10 == 0) { sum_to_hundred += dict[i]; }
            else { sum_to_hundred += (dict[i % 10] + dict[10 * (i / 10)]); }
        }

    }
    
    sum += sum_to_hundred;
    
    // add the hundreds
    for (int j = 1; j <= 9; j++) {
        sum += (dict[j] + dict[100]);
        // ___ hundred and ___
        sum += (99 * (dict[j] + dict[100] + 3) + sum_to_hundred);
    }
    
    sum += thousand;
    cout << "Number letter counts: " << sum << endl;

    return 0;
}