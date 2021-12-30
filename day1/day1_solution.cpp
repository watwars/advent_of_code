#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    int count = 0;
    cin >> a >> b >> c;
    int sum = a + b + c;
    while (true) {
        if (cin.eof()) break;
        int d;
        cin >> d;

        int newSum = sum - a + d;
        if (newSum > sum) {
            count++;
        }

        sum = newSum;
        a = b;
        b = c;
        c = d;
    }

    cout << count << endl;

    return 0;
}