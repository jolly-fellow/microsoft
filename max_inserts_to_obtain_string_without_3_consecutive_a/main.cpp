#include <iostream>
#include <string>

using namespace std;

/*
 If N is number of chars in the given string and all chars are not 'a' we can insert into this string 2 * (N + 1)
 chars because we can insert two As between of each two chars in the string and two As to the begin and
 to the end of the string.
 Thus in order to solve this task we need to count all non A chars. When we will know this number it will be easy
 to calculate how many As we can add. This number will be 2 * (number of possible places to insert + 1) - number of found As
 In other words 2 * (N + 1) - (N - number of As);
 */

int solution(const string & s) {
    int count_As = 0, count_others = 0, s_len = s.length();
    for (int i = 0; i < s_len; ++i) {
        if (s[i] == 'a') {
            count_As++;
        }
        else {
            count_others++;
            count_As = 0;
        }
        if (count_As == 3) {
            return -1;
        }
    }
    return 2 * (count_others + 1) - (s_len - count_others);
}

int main() {

    cout << solution("aabab") << " Expected: 3" << endl;
    cout << solution("dog") << " Expected: 8" << endl;
    cout << solution("aa") << " Expected: 0" << endl;
    cout << solution("baaaa") << " Expected: -1" << endl;

    return 0;
}

