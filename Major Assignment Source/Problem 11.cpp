#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool isPossible(vector<int>& A, int N, int M, int pages) {
    int students = 1;
    int currSum = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] > pages) {
            return false;
        }
        if (currSum + A[i] > pages) {
            students++;
            currSum = A[i];
            if (students > M) {
                return false;
            }
        }
        else {
            currSum += A[i];
        }
    }

    return true;
}

int findPages(int N, int M, vector<int>& A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    int low = 0, high = sum;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(A, N, M, mid)) {
            result = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int N = 4;
    vector<int> A = { 12, 34, 67, 90 };
    int M = 2;
    cout << findPages(N, M, A) << endl;
    return 0;
}
