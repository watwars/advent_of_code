#include <bits/stdc++.h>

using namespace std;

void partOne() {
    vector<string> grid;
    while (true) {
        if (cin.eof()) break;
        string line;
        cin >> line;
        grid.push_back(line);
    }
    int width = grid[0].length();
    int height = grid.size();
    int desiredWidth = height * 3 + 1;
    while (width < desiredWidth) {
        for (int i = 0; i < height; i++) {
            grid[i] += grid[i];
        }
        width *= 2;
    }

    int row = 1;
    int col = 3;
    int count = 0;
    while (row < height) {
        if (grid[row][col] == '#') {
            count++;
        }
        row += 1;
        col += 3;
    }
    cout << count << endl;
}

void partTwo() {
    vector<string> grid;
    while (true) {
        if (cin.eof()) break;
        string line;
        cin >> line;
        grid.push_back(line);
    }
    int width = grid[0].length();
    int height = grid.size();
    int desiredWidth = height * 10 + 1;
    while (width < desiredWidth) {
        for (int i = 0; i < height; i++) {
            grid[i] += grid[i];
        }
        width *= 2;
    }

    vector<vector<int>> moves;
    moves.push_back({1, 1});
    moves.push_back({1, 3});
    moves.push_back({1, 5});
    moves.push_back({1, 7});
    moves.push_back({2, 1});

    int finalCount = 1;
    for (auto i : moves) {
        int row = i[0];
        int col = i[1];
        int count = 0;
        while (row < height) {
            if (grid[row][col] == '#') {
                count++;
            }
            row += i[0];
            col += i[1];
        }
        cout << count << endl;
        finalCount *= count;
    }
    cout << "Final count: " << finalCount << endl;
}

int main() {
    // partOne();
    partTwo();
    return 0;
}
