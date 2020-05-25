#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
int solution(const string &S, const vector<int> &C) {
    int count = 0, s_len = S.length();

    for (int i = 1; i < s_len; ++i) {
        if (S[i - 1] == S[i]) {
            count += std::min(C[i - 1], C[i]);
        }
    }
    return count;
}
*/

/*
 Find maximum value in the sequence of the same characters and
 subtract it from the sum of all previous values. Or is the sum is bigger than
 the maximal value remove the sum but not the value.

 Actually we adding up all the values in the sequence and finding the maximum value
 then we compare them and leaving the biggest one.

 */
int solution(const string &s, const vector<int> &nums) {
    int res = 0, s_len = s.length();
    int sum = nums[0], max_value = nums[0];
    for (int i = 1; i < s_len; ++i) {
        if (s[i] != s[i - 1]) {
            res += sum - max_value;
            sum = nums[i];
            max_value = nums[i];
        }
        else {
            sum += nums[i];
            max_value = std::max(max_value, nums[i]);
        }
    }
    res += sum - max_value;
    return res;
}

int main() {

    cout << solution("abccbd",{0, 1, 2, 3, 4, 5}) << " Expected: 2" << endl;
    cout << solution("a",{9001}) << " Expected: 0" << endl;
    cout << solution("ab",{9001,9001}) << " Expected: 0" << endl;
    cout << solution("aab",{9001, 1, 9002}) << " Expected: 1" << endl;
    cout << solution("aabbcc",{1, 2, 1, 2, 1, 2}) << " Expected: 3" << endl;
    cout << solution("aaa",{1, 2, 1}) << " Expected: 2" << endl;

    cout << solution("aaaa",{3, 4, 5, 6}) << " Expected: 12" << endl;
    cout << solution("ababa",{10, 5, 10, 5, 10}) << " Expected: 0" << endl;
    cout << solution("abccccc",{1, 2, 4, 3, 6, 2, 1}) << " Expected: 10" << endl;

    return 0;
}

