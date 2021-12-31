#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    vector<int> positions;
    int largest = 0;
    while (true) {
        if (cin.eof()) break;
        int pos;
        largest = max(largest, pos);
        char comma;
        cin >> pos;
        positions.push_back(pos);
        cin >> comma;
    }
    cout << largest << endl;
    // return 0;

    long minVal = largest * (largest + 1) / 2 * positions.size();
    for (int i = 0; i < largest; i++) {
        cout << i << " " << largest << endl;
        long sum = 0;
        for (auto j : positions) {
            long diff = abs(i - j);
            sum += (diff * (diff + 1)) / 2;
            cout << j << " to " << i << " ";
            cout << (diff * (diff + 1)) / 2 << endl;
        }
        cout << "SUM: " << sum << endl;
        cout << "-------------------" << endl;
        minVal = min(minVal, sum);
    }
    cout << largest << endl;
    cout << minVal << endl;

    return 0;
}