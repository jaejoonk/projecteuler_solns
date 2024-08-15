#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int amicable_sum(int n) {
    vector<int> facts;
	int divisor = 2;
	int sum = 0;
	
	if (n < 2) { return 0; }
	
	// not including 1
	while (divisor * divisor <= n) {
	    if (n % divisor == 0) {
	        facts.push_back(divisor);
	        facts.push_back(n / divisor);
	    }
	    divisor++;
	}
	
    for (auto &fact: facts) {
        sum += fact;
    }
    
    // include 1
	return ++sum;
}


int main() {
    int total_sum = 0;
    int max_num = 10000;
    
    map<int, int> d;
    
    for (int n = 1; n < max_num; n++) {
        d[n] = amicable_sum(n);
    }
    
    for (int n = 1; n < max_num; n++) {
        if ((d[n] != n) && (d[d[n]] == n)) {
            total_sum += n;
        }
    }
    
    cout << "Total amicable # sum under " << max_num << ": " << total_sum;
    cout << endl;
	return 0;
}
