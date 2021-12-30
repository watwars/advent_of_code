#include <iostream>
#include <string>

using namespace std;

int main() {
    int horizontal = 0;
    int vertical = 0;
    int aim = 0;
    string cmd;
    int move;

    while (true) {
        if (!cin || cin.eof()) break;
        cin >> cmd >> move;
        cout << cmd << move << endl;

        if (cmd == "forward") {
            horizontal += move;
            vertical += move * aim;
        } else if (cmd == "down")
            aim += move;
        else
            aim -= move;
    }

    cout << horizontal << " " << vertical << endl;
    cout << vertical * horizontal << endl;
    return 0;
}