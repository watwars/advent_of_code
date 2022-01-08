#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void separateString(vector<int> &vect, string str) {
    string s = "";
    for (unsigned int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            vect.push_back(stoi(s));
            s = "";
        } else {
            s += str[i];
        }
    }
    vect.push_back(stoi(s));
}

int main() {
    // individual vector are formatted as x1,y1,x2,y2
    vector<vector<int>> vents;

    while (true) {
        if (cin.eof()) break;
        string start, arrow, end;
        cin >> start >> arrow >> end;
        vector<int> vect;
        separateString(vect, start);
        separateString(vect, end);
        vents.push_back(vect);
    }

    vector<vector<int>> board;
    int width = 0;
    int height = 0;
    for (auto vent : vents) {
        width = max(width, vent[0]);
        width = max(width, vent[2]);
        height = max(height, vent[1]);
        height = max(height, vent[3]);
    }

    for (int i = 0; i < height + 1; i++) {
        vector<int> row;
        for (int j = 0; j < width + 1; j++) {
            row.push_back(0);
        }
        board.push_back(row);
    }

    for (auto vent : vents) {
        int x1 = vent[0];
        int y1 = vent[1];
        int x2 = vent[2];
        int y2 = vent[3];
        if (x1 != x2 && y1 != y2) {
            int xDiff = x2 - x1;
            int yDiff = y2 - y1;
            if (abs(xDiff) != abs(yDiff)) continue;
            for (int i = 0; i <= abs(xDiff); i++) {
                int x = xDiff >= 0 ? x1 + i : x1 - i;
                int y = yDiff >= 0 ? y1 + i : y1 - i;
                cout << x << " " << y << endl;
                board[y][x]++;
            }
        } else if (x1 == x2) {
            for (int i = min(y1, y2); i <= max(y1, y2); i++) {
                cout << x1 << " " << i << endl;
                board[i][x1]++;
            }
        } else {
            for (int i = min(x1, x2); i <= max(x1, x2); i++) {
                cout << i << " " << y1 << endl;
                board[y1][i]++;
            }
        }

        cout << "----------------" << endl;
    }

    int count = 0;
    for (auto row : board) {
        for (auto cell : row) {
            if (cell >= 2) count++;
            cout << cell << " ";
        }
        cout << endl;
    }

    cout << count << endl;

    return 0;
}