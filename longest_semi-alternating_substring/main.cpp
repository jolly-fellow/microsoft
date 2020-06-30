#include <iostream>
#include <string>

using namespace std;

int solution(const string & s) {
    const int MAX_COUNT = 3;
    int s_len = s.length();
    if(s_len < MAX_COUNT) { return s_len; }
    int count = 1, result = 1;
    // Scan whole string and count it's characters.
    for(int i = 1; i < s_len - 1; ++i) {
        // If we meet 3 consecutive characters
        if((s[i-1] == s[i]) && (s[i+1] == s[i])) {
            // save the counter as result if it is bigger than the previous result
            result = max(result,count+1);
            // and drop the counter to 1
            count = 1;
        }
        else { count++; }
    }
    // return maximal result
    return max(result,count+1);
}

int main() {
    cout << solution("baaabbabbb") << " Expected: 7" << endl;
    cout << solution("babba") << " Expected: 5" << endl;
    cout << solution("abaaaa") << " Expected: 4" << endl;


    cout << solution("eedaaad") << endl;
    cout << solution("xxxtxxx") << endl;
    cout << solution("uuuuxaaaaxuuu") << endl;
    return 0;
}