#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPalindrome(int n) {
    string s = to_string(n);
    int len = s.length();
    for (int i = 0; i < (len / 2) + 1; i++) {
        if (s[i] != s[len-i-1]) {
            return false;
        }
    }
    return true;
}
 

int main() {
    int max = 0;
    for (int i = 999; i >= 100; i--) {
        for (int j = 999; j >= 100; j--) {
            if (isPalindrome(i * j) && (i*j > max)) {
                max = i*j;
            }
        }
    }
    cout << max << endl; 
    return 0;
}
