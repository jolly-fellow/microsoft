#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...]
 find the minimum number of conference rooms required.
 This task is open on leetcode for paid users only so I have added another link to the description of the task.
 https://www.programcreek.com/2014/05/leetcode-meeting-rooms-ii-java/

    Algorithm:
    1. Sort meetings by start times.
    2. Push end time of the first meeting to priority queue.
    3. For each next meeting: If the earliest end time of a meeting happens before the current meeting starts,
    i.e. top of the priority queue <= current meeting's start time, pop the top value from the queue.
    4. Push current meeting end time to the queue.
    5. Return queue side as the number of needed rooms.
 */

using interval = vector<int>; // {start time, end time}

int test(vector<interval> & meetings) {
    int m_size = meetings.size();
    sort(meetings.begin(), meetings.end(), [](interval lhs, interval rhs) -> bool { return lhs[0] < rhs[0]; });

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    pq.push(meetings[0][1]);
    for (int i = 1; i < m_size; i++) {
        if (pq.top() <= meetings[i][0]) {
            pq.pop();
        }
        pq.push(meetings[i][1]);
    }
    return pq.size();
}


int main() {

    vector<vector<int>> v = {{2, 15}, {36, 45}, {9, 29}, {16, 23}, {4, 9}, {46, 50}, {50, 52}, {50, 55}, {51, 56}, {55, 58}, {55, 60}};

    cout << test(v) << " Expected: 3" << endl;

    return 0;
}

