#include <bits/stdc++.h>

using namespace std;

//       0
//   ----------
//   |        |
// 1 |        | 2
//   |    3   |
//   ----------
//   |        |
// 4 |        | 6
//   |        |
//   ----------
//        7

int calculateTotal(vector<string> inputs, vector<string> toGuess) {
    vector<unordered_set<int>> toGuessSet(7);

    for (auto i : inputs) {
    }

    return 1;
}

int main() {
    char line;
    int total = 0;
    while (true) {
        if (cin.eof()) break;
        vector<string> inputs;
        for (int i = 0; i < 10; i++) {
            string input;
            cin >> input;
            inputs.push_back(input);
        }
        cin >> line;
        vector<string> toGuess;
        for (int i = 0; i < 4; i++) {
            string guess;
            cin >> guess;
            toGuess.push_back(guess);
        }
        total += calculateTotal(inputs, toGuess);
    }

    cout << total << endl;
}