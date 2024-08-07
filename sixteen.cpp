#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int power = 1000;
    vector<int> digits = {1};
    bool carry = false;
    int sum = 0;
    int next_value;
    
    // make an array that has the digits of 2^n backwards
    for (int i = 1; i <= power; i++) {
        for (int k = 0; k < digits.size(); k++) {
            next_value = carry ? 2 * digits[k] + 1 : 2 * digits[k];
            if (next_value < 10) {
                digits[k] = next_value;
                carry = false;
            } else {
                digits[k] = next_value % 10;
                carry = true;
            }
            
        }
        if (carry) {
            digits.push_back(1);
            carry = false;
        }
        
    }
    // sum up digits
    
    for (const int& i : digits) { sum += i; }
    cout << "Total sum: " << sum << endl;
	return 0;
}