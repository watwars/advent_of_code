#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void printVector(vector<int> fishes) {
    for (unsigned int i = 0; i < fishes.size(); i++) {
        cout << fishes[i] << " ";
    }
}

void slowSolution(char **argv) {
    vector<int> cache;
    for (int i = 0; i < 6; i++) {
        cache.push_back(-1);
    }
    vector<int> fishes;
    while (true) {
        if (cin.eof()) break;
        int fish;
        char comma;
        cin >> fish;
        fishes.push_back(fish);
        cin >> comma;
    }
    int days = stoi(argv[1]);
    int numFishes = 0;
    for (auto fish : fishes) {
        cout << cache[fish] << " " << endl;
        if (cache[fish] != -1) {
            numFishes += cache[fish];
        } else {
            vector<int> temp{fish};
            for (int i = 0; i < days; i++) {
                cout << i << ": " << temp.size() << endl;
                for (unsigned int j = 0; j < temp.size(); j++) {
                    temp[j]--;
                    if (temp[j] == -1) {
                        temp[j] = 6;
                        temp.push_back(9);
                    }
                }
            }
            numFishes += temp.size();
            cache[fish] = temp.size();
        }
    }
    cout << numFishes << endl;
}

const int DAY_TO_CACHE = 1;

long long calculateFish(long long fish, int days, unordered_map<int, long long> &cache) {
    if (days < 0) return 1;
    cout << "Fish: " << fish << " Days: " << days << endl;
    if (fish != DAY_TO_CACHE) {
        return calculateFish(DAY_TO_CACHE, days - (fish - DAY_TO_CACHE), cache);
    }
    if (cache.find(days) != cache.end()) {
        cout << "Found in cache" << endl;
        return cache[days];
    }
    // Fish = 1, Days = ?
    long long numFishes = 1;
    int current = DAY_TO_CACHE;
    for (int i = 0; i < days; i++) {
        current--;
        if (current == -1) {
            current = 6;
            numFishes += calculateFish(8, days - i - 1, cache);
        }
    }

    cache[days] = numFishes;
    return numFishes;
}

void fastSolution(char **argv) {
    unordered_map<int, long long> cache;
    vector<int> fishes;
    while (true) {
        if (cin.eof()) break;
        int fish;
        char comma;
        cin >> fish;
        fishes.push_back(fish);
        cin >> comma;
    }
    int days = stoi(argv[1]);
    long long numFishes = 0;
    for (auto fish : fishes) {
        long long newFishes = calculateFish(fish, days, cache);
        numFishes += newFishes;
        cout << "New Fishes: " << newFishes << endl;
        cout << "----------------------------------------" << endl;
    }
    cout << numFishes << endl;
}

int main(int argc, char **argv) {
    // slowSolution(argv);
    fastSolution(argv);
    return 0;
}