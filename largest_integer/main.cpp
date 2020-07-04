#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(const vector<int>& input){
    unordered_set<int> s(input.begin(),input.end());
    int max_value = 0;
    for(auto n : s){
        if((abs(n) > max_value) && (s.count(-n) != 0) ) {
            max_value = n;
        }
    }
    return max_value;
}

int main() {

    cout << solution({3, 2, -2, 5, -3}) << " Expected: 3" << endl;

    cout << solution({1, 2, 3, -4}) << " Expected: 0" << endl;

    return 0;
}

