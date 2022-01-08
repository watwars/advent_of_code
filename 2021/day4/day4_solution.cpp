#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<int>> board) {
    for (auto row : board) {
        for (auto cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool fillAndCheck(vector<vector<int>> &board, int move) {
    for (unsigned int i = 0; i < board.size(); i++) {
        for (unsigned int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == move) {
                board[i][j] = -1;
                bool finished = true;
                // check row
                for (unsigned int k = 0; k < board.size(); k++) {
                    if (board[i][k] != -1) {
                        finished = false;
                        break;
                    }
                }
                if (finished) {
                    return true;
                }
                finished = true;
                // check column
                for (unsigned int k = 0; k < board[i].size(); k++) {
                    if (board[k][j] != -1) {
                        finished = false;
                        break;
                    }
                }
                if (finished) {
                    return true;
                }
            }
        }
    }
    return false;
}

int calculateScore(vector<vector<int>> board, int move) {
    printBoard(board);
    int sum = 0;
    for (auto row : board) {
        for (auto cell : row) {
            if (cell != -1) {
                sum += cell;
            }
        }
    }

    cout << "SUM: " << sum << endl;
    return sum * move;
}

int main() {
    vector<int> steps;
    vector<vector<vector<int>>> boards;

    string moves;
    cin >> moves;
    int movesLength = moves.length();
    string move = "";
    for (int i = 0; i < movesLength; i++) {
        if (moves[i] == ',') {
            steps.push_back(stoi(move));
            move = "";
        } else {
            move += moves[i];
        }
    }
    steps.push_back(stoi(move));

    while (true) {
        if (cin.eof()) break;
        vector<vector<int>> board;
        for (int i = 0; i < 5; i++) {
            vector<int> row;
            for (int j = 0; j < 5; j++) {
                int num;
                cin >> num;
                row.push_back(num);
            }
            board.push_back(row);
        }
        boards.push_back(board);
    }

    int numBoards = boards.size();

    for (auto move : steps) {
        cout << move << endl;
        for (auto &board : boards) {
            if (board.size() == 0) continue;
            bool finish = fillAndCheck(board, move);
            if (finish) {
                numBoards--;
                if (numBoards == 0) {
                    cout << move << endl;
                    cout << calculateScore(board, move) << endl;
                    return 0;
                } else {
                    board.clear();
                }
            };

            // printBoard(board);
            // cout << "----" << endl;
        }
        // cout << "-----------------" << endl;
    }

    return 0;
}