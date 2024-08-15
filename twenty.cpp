#include <iostream>
#include <map>
#include <vector>

using namespace std;

int digitsum_factorial(int n) {
    vector<int> digits = {1};
    int digit = 0;
    int carry_digit = 0;
    int updated_digit = 0;
    int result = 0;
    
    for (int k = 1; k <= n; k++) {
        
        digit = 0;
        carry_digit = 0;
        updated_digit = 0;
        
        for (int i = 0; i < digits.size(); i++) {
            digit = digits[i];
            updated_digit = (digit * k + carry_digit) % 10;
            carry_digit = (digit * k + carry_digit) / 10;
            digits[i] = updated_digit;
        }
        while (carry_digit > 0) {
            digits.push_back(carry_digit % 10);
            carry_digit /= 10;
        }
    }
    
    for (auto &digit: digits) {
        result += digit;
    }
    
    return result;
    
}

int main() {
    int n = 100;
    cout << "100! sum of digits: " << digitsum_factorial(n) << endl;
    
    return 0;
}
