#include <iostream>
#include <vector>

using namespace std;

void replace(string &s, int i) {
    int r;
    char c = 'a';
    int s_len = s.length();
    while (c <='z' && ((i > 0 && s[i-1] == c) || (i < s_len-1 && s[i+1] == c))) {
        ++c;
    }
    s[i] = c;
}

string solution(string s) {
    int s_len = s.length();

    if (0 == s_len) { return s; }

    for (int i = 0; i < s_len; i++) {
        if (s[i] == '?') {
            replace(s, i);
        }
    }
    return s;
}

string solution2(string s) {
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

    cout << "Result: " << solution2("xy?xz?") << " Expected: xycxza, xyzxzd, xyfxzf or similar" << endl;
    cout << "Result: " << solution2("ab?e?mr??") << " Expected: abveamrab or similar" << endl;
    cout << "Result: " << solution2("??????") << " Expected: any string with length 6 chars" << endl;

    return 0;
}

