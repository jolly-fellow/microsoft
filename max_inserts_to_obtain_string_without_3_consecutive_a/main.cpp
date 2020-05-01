#include <iostream>
#include <string>

using namespace std;

int solution(string s) {
    int countA = 0, countOther = 0, s_len = s.length();
    for (int i = 0; i < s_len; ++i) {
        if (s[i] == 'a') {
            countA++;
        }
        else {
            countOther++;
            countA = 0;
        }
        if (countA == 3) {
            return -1;
        }
    }
    // pairs of A's as separators and bookends for the non-a characters
    return 2 * (countOther + 1) - (s_len - countOther);
}

int main() {

    cout << solution("aabab") << " Expected: 3" << endl;
    cout << solution("dog") << " Expected: 8" << endl;
    cout << solution("aa") << " Expected: 0" << endl;
    cout << solution("baaaa") << " Expected: -1" << endl;

    return 0;
}

