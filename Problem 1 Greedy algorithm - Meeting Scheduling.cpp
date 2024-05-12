#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start, end, pos;
};

bool compare(Meeting m1, Meeting m2) {
    return m1.end < m2.end;
}

int maxMeetings(int start[], int end[], int n) {
    vector<Meeting> meetings(n);
    for (int i = 0; i < n; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1;
    }

    sort(meetings.begin(), meetings.end(), compare);

    int answer = 1;
    int limit = meetings[0].end;

    for (int i = 1; i < n; ++i) {
        if (meetings[i].start > limit) {
            limit = meetings[i].end;
            answer++;
        }
    }

    return answer;
}

int main() {
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };
    int n = sizeof(start) / sizeof(start[0]);
    cout << maxMeetings(start, end, n) << endl;
    return 0;
}
