#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <iterator>
#include <unordered_map>

using namespace std;
/*
int solution(const vector<int> & v) {

    priority_queue<int> pq(v.begin(), v.end());
    int tallest_num = 0;
    int steps = 0;
    while ( ! pq.empty()) {
        int tallest = pq.top(); pq.pop();
        if (pq.empty()) { return steps; }
        if (tallest == pq.top()) {
            ++ tallest_num;
        }
        else {
            steps += tallest_num;
        }
    }
    return steps;
}
*/


int solution3(const vector<int> & v) {
    int v_size = v.size();
    int result = 0;
    int min_num = *std::min_element(v.begin(), v.end());
    std::unordered_map<int, int> um;

    for(auto i : v) {
        ++ um[i];
    }

    for(auto i: um) {
        result += i.second;
    }
    return result;
}

int solution2(vector<int> v) {
    int v_size = v.size();
    int result = 0;

    unordered_set<int> us(v.begin(), v.end());
    unordered_multiset<int> ums(v.begin(), v.end());
    for(auto i : us) {
        result += ums.count(i);
    }
    return result;
}

int solution(vector<int> v) {
    int v_size = v.size();
    if(v_size < 2) { return 0; }
    std::sort(v.begin(), v.end());
//    std::copy(v.begin(), v.end(),  std::ostream_iterator<int>(std::cout, " "));
    int sum = 0;
    for (int i = 1; i < v_size; ++i) {
        if (v[v_size - i - 1] != v[v_size - i]) {
            sum += i;
        }
    }
    return sum;
}

int main() {

    cout << solution({5,2,1}) << " Expected: 3" << endl;
    cout << solution({5,5,2,2,1,1}) << " Expected: 6" << endl;
    cout << solution({5,5,1}) << " Expected: 2" << endl;
    cout << solution({5,5,5,5,1}) << " Expected: 4" << endl;
    cout << solution({3,2,2}) << " Expected: 1" << endl;

    return 0;
}

