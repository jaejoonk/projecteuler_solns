#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int k) {
    long long result = 1;
    if (k <= 1) { return result; }
    for (int i = k; i > 1; i--) {
        result *= i;
    }
    return result;
}

// 2n choose n = sum from i=0 to n of (n choose i)^2
long long square_comb(int k) {
    long long fact_k = factorial(k);
    long long result = 0;

    for (int i = 0; i <= k; i++) {
        long long nci = fact_k / (factorial(i) * factorial(k-i)); 
        result += (nci * nci);
    }
    return result;
}

int main() {
    long long result = square_comb(20);
    cout << "40 choose 20 is " << result << "." << endl;
    return 0;
}
