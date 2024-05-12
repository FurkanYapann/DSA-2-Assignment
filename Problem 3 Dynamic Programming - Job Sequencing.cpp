#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job j1, Job j2) {
    return j1.deadline < j2.deadline;
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, compare);

    vector<int> dp(n, 0);
    dp[0] = arr[0].profit;

    for (int i = 1; i < n; ++i) {
        dp[i] = max(dp[i - 1], arr[i].profit);
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j].deadline < arr[i].id) {
                dp[i] = max(dp[i], dp[j] + arr[i].profit);
                break;
            }
        }
    }

    return { n, dp[n - 1] };
}

int main() {
    Job arr[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res = JobScheduling(arr, n);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
