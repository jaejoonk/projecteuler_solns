#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <regex>

using namespace std;

const regex delimiter {","};
const string filename {"names.txt"};

// compute sum of letters -> digits
int wordscore(string word) {
    int score = 0;
    for (auto &ch: word) {
        if (ch != '"') {
            score += (ch - 'A' + 1);
        }
    }
    return score;
}

int name_scores() {
    int result = 0;
    vector<string> names;
    
    ifstream csvFile(filename);
    // for each line, split by each delimiter
    for (string line{}; getline(csvFile, line); ) {
        names = vector<string>(sregex_token_iterator(line.begin(),
                                                     line.end(),
                                                     delimiter, -1), {});
    }
    
    sort(names.begin(), names.end());
    
    // multiply word score by position
    for (int i = 1; i <= names.size(); i++) {
        result += (i * wordscore(names[i-1]));
    }
    
    return result;
}

int main() {
    int result = name_scores();
    cout << "Name scores: " << result << endl;
    return 0;
}