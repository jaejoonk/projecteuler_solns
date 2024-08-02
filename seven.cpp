#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int nthPrime = 10001;

    int num = 2;
    int count = 0;
    bool isPrime = true;
    
    vector<int> primes;
    while (count < nthPrime) {
        for (const int& i : primes) {
            if (num % i == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {
            primes.push_back(num);
            count += 1;
        }
        
        num += 1;
        isPrime = true;
    }
    
    cout << "Prime #" << nthPrime << ": " << num-1 << endl;
    return 0;
}
