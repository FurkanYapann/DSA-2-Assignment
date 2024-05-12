#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

vector<int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, compare);

    vector<int> result(n, -1);
    int count = 0, profit = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; --j) {
            if (result[j] == -1) {
                result[j] = arr[i].id;
                count++;
                profit += arr[i].profit;
                break;
            }
        }
    }

    return { count, profit };
}

int main() {
    Job arr[] = { {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res = JobScheduling(arr, n);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
