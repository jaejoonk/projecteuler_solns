#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int isPrime(int n) {
    if (n == 2) { return 1; }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) { return 0; }
    }
    return 1;
}

int main() {
    int num = 2;
    long long sum = 0;
    int max = 2000000;
    
    while (num < max) {
        if (isPrime(num)) {
            sum += (long long)num;
        }
        
        num += 1;
    }
    
    cout << "Prime sum under " << max << ": " << sum << endl;
    return 0;
}
