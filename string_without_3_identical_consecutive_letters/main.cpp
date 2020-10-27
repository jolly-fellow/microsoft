#include <iostream>
#include <string>

using namespace std;

string solution2(const string & s) {
    const int MAX_COUNT = 3;
    int s_len = s.length();
    int prev_count = 1;
    string res;
    res.push_back(s[0]);

    for (int i = 1; i < s_len; ++i) {

        if(s[i] == s[i-1]) {
            prev_count++;
        }
        else {
            prev_count = 1;
        }
        if(prev_count < MAX_COUNT) {
            res.push_back(s[i]);
        }
    }
    return res;
}

string solution(const string & s) {
    int s_len = s.length();
    string res(s.begin(), s.begin()+2);
    for (int i = 2; i < s_len; ++i) {
        if (s[i] != s[i-1] || s[i] != s[i-2]) {
            res.push_back(s[i]);
        }
    }
    return res;
}


int main() {

    cout << solution("eedaaad") << endl;
    cout << solution("xxxtxxx") << endl;
    cout << solution("uuuuxaaaaxuuu") << endl;
    return 0;
}

