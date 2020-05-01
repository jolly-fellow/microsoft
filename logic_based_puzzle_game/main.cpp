#include <iostream>
#include <vector>

using namespace std;

void replace(string &s, int i) {
    int r;
    char c;
    int s_len = s.length();
    do {
        r = rand()%26;
        c = 'a' + r;
    } while ((i > 0 && s[i-1] == c) || (i < s_len-1 && s[i+1] == c));

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

int main() {

    cout << "Result: " << solution("xy?xz?") << " Expected: xycxza, xyzxzd, xyfxzf or similar" << endl;
    cout << "Result: " << solution("ab?e?mr??") << " Expected: abveamrab or similar" << endl;
    cout << "Result: " << solution("??????") << " Expected: any string with length 6 chars" << endl;

    return 0;
}

