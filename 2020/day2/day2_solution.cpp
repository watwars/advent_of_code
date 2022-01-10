#include <bits/stdc++.h>

using namespace std;

void partOne() {
    int count = 0;
    while (true) {
        if (cin.eof()) break;
        int a, b;
        char del;
        cin >> a >> del >> b;
        char good;
        cin >> good >> del;
        string line;
        cin >> line;

        int stringLength = line.length();
        int freq = 0;
        for (int i = 0; i < stringLength; i++) {
            if (line[i] == good) {
                freq++;
            }
        }
        if (freq >= a && freq <= b) {
            cout << line << endl;
            count++;
        }
    }
    cout << count << endl;
}

void partTwo() {
    int count = 0;
    while (true) {
        if (cin.eof()) break;
        int a, b;
        char del;
        cin >> a >> del >> b;
        char good;
        cin >> good >> del;
        string line;
        cin >> line;

        a--;
        b--;

        int stringLength = line.length();
        if (a < 0 || b < 0 || a >= stringLength || b >= stringLength) {
            continue;
        }
        cout << line[a] << " " << line[b] << endl;
        if ((line[a] == good || line[b] == good) && !(line[a] == good && line[b] == good)) {
            cout << line << endl;
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    // partOne();
    partTwo();
    return 0;
}
