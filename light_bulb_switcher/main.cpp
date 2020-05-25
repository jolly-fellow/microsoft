#include <iostream>
#include <vector>

using namespace std;

/*
 For any bulb to shine at position k (not array index, but the actual position in the line), all the bulbs 1 through k
 must be turned on at a given instance. Now, if A[i] = p such that it makes all the bulbs 1 through k to shine, then p
 must be in the range [1, k-1], inclusive and no other position in that range should be missing.

 This means that the sum of the positions of the turned on bulbs must be 1+2+3+...+k.
 This sum also has to be equal to 1+2+3+ ... +i (1 based index) because no other bulb after position k must not be
 turned on according to given condition. Time O(N), Space O(1).
 */

int solution(const vector<int> & v) {
    int v_size = v.size();
    int ans = 0, sum = 0, target = 0;

    for(int i = 1; i<= v_size; i++) {
        sum += v[i - 1];
        target += i ; //Sum from 1 to i
        if(sum == target) ans++;
    }
    return ans;
}

int main() {
    vector<int> arr1 = {2, 1, 3, 5, 4};
    vector<int> arr2 = {2, 3, 4, 1, 5};
    vector<int> arr3 = {5, 4, 3, 2, 1};
    vector<int> arr4 = {1, 2, 3, 4, 5, 6};

    cout << solution(arr1) << " Expected 3" << endl;
    cout << solution(arr2) << " Expected 2" << endl;
    cout << solution(arr3) << " Expected 1" << endl;
    cout << solution(arr4) << " Expected 6" << endl;

    return 0;
}

