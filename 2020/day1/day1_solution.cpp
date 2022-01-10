#include <bits/stdc++.h>

using namespace std;

void partOne() {
    unordered_map<int, int> seen;

    int n;
    while (true) {
        if (cin.eof()) break;
        cin >> n;

        int diff = 2020 - n;
        if (seen.find(diff) != seen.end()) {
            cout << diff << " " << n << endl;
            cout << diff * n << endl;
            break;
        }
        seen[n] = diff;
    }
}

void partTwo() {
    vector<int> numbers;
    int n;
    while (true) {
        if (cin.eof()) break;
        cin >> n;
        numbers.push_back(n);
    }

    sort(numbers.begin(), numbers.end());
    for (unsigned int i = 0; i < numbers.size(); i++) {
        int left = i + 1;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[i] + numbers[left] + numbers[right];
            if (sum == 2020) {
                cout << numbers[i] * numbers[left] * numbers[right] << endl;
                return;
            } else if (sum < 2020) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main() {
    // partOne();
    partTwo();
    return 0;
}
