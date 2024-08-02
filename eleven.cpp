#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
    ifstream file { "eleven.txt" };
    if (!file.is_open()) return -1;

    int dim = 20;
    int arr[dim][dim];
    
    int prod_len = 4;
    
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            file >> arr[i][j];
        }
    } 

    int max = 0;
    int value = 1;
    
    // check horizontal:
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < (dim - prod_len); j++) {
            value = arr[i][j];
            for (int k = 1; k < prod_len; k++) { value *= arr[i][j+k]; }
            if (value > max) { max = value; }
        }
    }
    
    // check vertical:
    for (int i = 0; i < (dim - prod_len); i++) {
        for (int j = 0; j < dim; j++) {
            value = arr[i][j];
            for (int k = 1; k < prod_len; k++) { value *= arr[i+k][j]; }
            if (value > max) { max = value; }
        }
    }
    
    // check descending diagonal:
    for (int i = 0; i < (dim - prod_len); i++) {
        for (int j = 0; j < (dim - prod_len); j++) {
            value = arr[i][j];
            for (int k = 1; k < prod_len; k++) { value *= arr[i+k][j+k]; }
            if (value > max) { max = value; }
        }
    }
    
    // check ascending diagonal:
    for (int i = 0; i < (dim - prod_len); i++) {
        for (int j = prod_len-1; j < dim; j++) {
            value = arr[i][j];
            for (int k = 1; k < prod_len; k++) {value *= arr[i+k][j-k]; }
            if (value > max) { max = value; }
        }
    }

    cout << "Maximum: " << max << endl;
    
    return 0;
}



