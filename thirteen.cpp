#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    ifstream file { "thirteen.txt" };
    if (!file.is_open()) return -1;
    
    const int dim = 100;
    // up to 19 digits
    unsigned long long int sum = 0;
    string num;

    for (int i = 0; i < dim; i++) {
        file >> num;
        sum += stoull(num.substr(0,17));
    }

    // ends up being 5.5e19
    cout << "Sum (first 10 digits): " << sum / 1000000000 << endl;
    system("pause");
    return 0;
}
