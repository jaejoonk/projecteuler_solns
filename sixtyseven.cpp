#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

// same solution as problem 18

// create a vector that takes a row higher up and combines it
// with its lower row to show the max path it would find from
// that row onwards
vector<int> traverse_up(vector<int> higher, vector<int> lower) {
    vector<int> result (higher.size(), 0);
    int higher_size = higher.size();
    int lower_size = lower.size();
    if ((higher_size + 1) != lower_size) {
        return vector<int>(0,0);
    }
    
    for (int i = 0; i < higher.size(); i++) {
        if (lower[i+1] > lower[i]) {
            result[i] = higher[i] + lower[i+1];
        } else {
            result[i] = higher[i] + lower[i];
        }
    }
    
    return result;
}

int max_path_sum(string filename) {
    ifstream f (filename);
    vector<vector<int>> arr;
    vector<int> arr_line;
    vector<string> arr_line_string;
    const regex delimiter{" "};
    
    vector<int> result;
    
    for (string line; getline(f, line); ) {
        arr_line = {};
        // parse a line into a set of delimiter split strings
        arr_line_string = vector<string>(
                            sregex_token_iterator(line.begin(), line.end(),
                                                  delimiter, -1), {}
                          );
        // turn vector of string into vector of ints
        for (const string& s : arr_line_string) {
            arr_line.push_back(stoi(s));
        }
        arr.push_back(arr_line);
    }
    
    result = arr[arr.size()-1];
    
    for (int i = arr.size()-2; i >= 0; --i) {
        result = traverse_up(arr[i], result);
    }
    
    return result[0];
}

int main() {
    int result = max_path_sum("sixtyseven.txt");
    cout << "Max path sum: " << result << endl;
    return 0;
}