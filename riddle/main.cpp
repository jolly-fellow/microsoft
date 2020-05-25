#include <iostream>
#include <string>

using namespace std;

/*
Since we need to check just the previous and the next characters, we can fulfil any pattern using maximum 3 characters.
We just need to check if both previous and next characters are different from 'a', 'b' or 'c' and put the one which satisfy the condition.
The C++ code is quite easy and runs in O(N):
 */

string solution(string s) {
    int s_size = s.size();
    for (int i = 0; i < s_size; ++i) {
        if (s[i] == '?') {
            for (char c = 'a'; c < 'd'; ++c) {
                if ((i == 0 || c != s[i - 1]) && (i == s_size - 1 || c != s[i + 1])) {
                    s[i] = c;
                    break;
                }
            }
        }
    }
    return s;
}

int main() {

    cout << solution("rd?e?wg??"s) << " Expected: rd e wg" << endl;
    cout << solution("ab?ac?"s) << " Expected: " << endl;
    cout << solution("????????"s) << " Expected: " << endl;

    return 0;
}

