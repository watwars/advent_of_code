#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int convertBinaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

void partOne(vector<string> binaries) {
    int length = binaries[0].length();

    string gamma = "";
    string epsilon = "";

    for (int i = 0; i < length; i++) {
        int one = 0;
        int zero = 0;

        for (unsigned int j = 0; j < binaries.size(); j++) {
            if (binaries[j][i] == '1') {
                one++;
            } else {
                zero++;
            }
        }

        gamma += (one > zero) ? '1' : '0';
        epsilon += (one > zero) ? '0' : '1';
    }

    cout << gamma << " " << epsilon << endl;

    int gammaNumber = convertBinaryToDecimal(gamma);
    int epsilonNumber = convertBinaryToDecimal(epsilon);

    cout << gammaNumber << " " << epsilonNumber << endl;
    cout << gammaNumber * epsilonNumber << endl;
}

void partTwo(vector<string> binaries) {
    vector<string> copy;
    for (auto binary : binaries) {
        copy.push_back(binary.c_str());
    }

    int length = binaries[0].length();

    string oxygenRating;
    string co2Rating;

    for (int i = 0; i < length; i++) {
        int one = 0;
        int zero = 0;

        for (unsigned int j = 0; j < binaries.size(); j++) {
            if (binaries[j][i] == '1') {
                one++;
            } else {
                zero++;
            }
        }

        vector<string> newBinaries;
        char good = (one >= zero) ? '1' : '0';
        for (unsigned int j = 0; j < binaries.size(); j++) {
            if (binaries[j][i] == good) {
                newBinaries.push_back(binaries[j]);
            }
        }

        binaries.clear();
        for (auto newBinary : newBinaries) {
            cout << newBinary << endl;
            binaries.push_back(newBinary);
        }

        oxygenRating = binaries[0];

        one = 0;
        zero = 0;
        for (unsigned int j = 0; j < copy.size(); j++) {
            if (copy[j][i] == '1') {
                one++;
            } else {
                zero++;
            }
        }

        newBinaries.clear();
        good = (one >= zero) ? '0' : '1';
        for (unsigned int j = 0; j < copy.size(); j++) {
            if (copy[j][i] == good) {
                newBinaries.push_back(copy[j]);
            }
        }

        copy.clear();
        for (auto newBinary : newBinaries) {
            // cout << newBinary << endl;
            copy.push_back(newBinary);
        }

        oxygenRating = binaries[0];
        co2Rating = copy[0];
        cout << "------------------------------------" << endl;
    }
    cout << "Oxygen Rating " << oxygenRating << endl;
    cout << "CO2 Rating " << co2Rating << endl;

    cout << convertBinaryToDecimal(oxygenRating) * convertBinaryToDecimal(co2Rating) << endl;
}

int main() {
    vector<string> binaries;
    while (true) {
        if (cin.eof()) break;
        string binary;
        cin >> binary;
        binaries.push_back(binary);
    }

    partTwo(binaries);

    return 0;
}