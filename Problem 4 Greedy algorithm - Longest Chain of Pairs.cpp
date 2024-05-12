#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool comparePairs(Pair p1, Pair p2) {
    return p1.second < p2.second;
}

int maxChainLen(Pair arr[], int n) {
    sort(arr, arr + n, comparePairs);

    int maxLength = 1;
    int currentEnd = arr[0].second;

    for (int i = 1; i < n; ++i) {
        if (arr[i].first > currentEnd) {
            maxLength++;
            currentEnd = arr[i].second;
        }
    }

    return maxLength;
}

int main() {
    Pair pairs[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = sizeof(pairs) / sizeof(pairs[0]);
    cout << maxChainLen(pairs, n) << endl;
    return 0;
}
