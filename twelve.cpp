#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int nth_triangular(int n) {
	return n * (n+1) / 2;
}

// stolen from https://stackoverflow.com/questions/4424374/determining-if-a-number-is-prime

bool isPrime(int n) {
	if (n < 2) { return false; }
	if (n == 2) { return true; }
	if (n % 2 == 0) { return false; }
	
	for (int i = 3; (i*i) <= n; i += 2) {
		if (n % i == 0) { return false; }
	}
	return true;
}

int nextPrime(int j) {
	int start = j;
	while (1) {
		j++;
		if (isPrime(j)) { return j; }
	}	
}

int number_of_divisors(int n) {
	vector<int> facts;
	int div = 2;
	int fact = 0;
	int num = 1;
	
	while (n > 1) {
	    // divide by number, but don't check previous primes
		if (n % div == 0) {
			n /= div;
			fact += 1;
		}
		else {
			facts.push_back(fact);
			fact = 0;
			div = nextPrime(div);
		}
		
	}
	// also account for last divisor
	facts.push_back(fact);
	
	int k = 1;
	for (int j = 0; j < facts.size(); j++) {
		k = nextPrime(k);
		// cout << k << " ^ " << facts[j];
		num *= (facts[j] + 1);
		// if (j != facts.size() - 1) { cout << " * "; }
	}
	// cout << endl;
	
	return num;
}

int main() {
	int limit = 500;
	int i = 1;
	
	while (1) {
	    int triangular = nth_triangular(i);
		int num_of_div = number_of_divisors(triangular);
		if (num_of_div > 500) {
			cout << i << "-th triangular number (" << triangular;
			cout <<") has " << num_of_div << " divisors." << endl;
			break;
		}
		else {
			i++;
		}
	}
	
	return 0;
}
