#include <iostream>
#include <cmath>
using namespace std;

long int max_prime_factor(long int n) {
    for (long int i = 2; i <= (long int)sqrt(n); i++) {
        if (n % i == 0) {
            return max_prime_factor(n / i);
        }
    }
    return n;
}

int main() {
    long int num = 600851475143;
    cout << max_prime_factor(num) << endl; 
    return 0;
}
