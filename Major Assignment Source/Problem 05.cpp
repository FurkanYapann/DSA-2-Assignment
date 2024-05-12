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

    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i].first > arr[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    Pair pairs[] = { {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int n = sizeof(pairs) / sizeof(pairs[0]);
    cout << maxChainLen(pairs, n) << endl;
    return 0;
}
