#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidPart(const string& s) {
    if (s.length() > 3 || s.length() == 0 || (s.length() > 1 && s[0] == '0')) {
        return false;
    }
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

void genIpHelper(string s, int part, vector<string>& result, string& current) {
    if (part == 4) {
        if (s.empty()) {
            result.push_back(current);
        }
        return;
    }

    for (int i = 1; i <= 3 && i <= s.length(); ++i) {
        string partStr = s.substr(0, i);
        if (isValidPart(partStr)) {
            string newCurrent = current + partStr;
            if (part < 3) {
                newCurrent += '.';
            }
            genIpHelper(s.substr(i), part + 1, result, newCurrent);
        }
    }
}

vector<string> genIp(string s) {
    vector<string> result;
    string current = "";
    genIpHelper(s, 0, result, current);
    return result.empty() ? vector<string>{ "-1" } : result;
}

int main() {
    string s = "11211";
    vector<string> result = genIp(s);
    for (const auto& ip : result) {
        cout << ip << endl;
    }
    return 0;
}
