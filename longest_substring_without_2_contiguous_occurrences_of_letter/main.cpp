#include <iostream>
#include <vector>

using namespace std;

string solution(const string &s) {
    int s_size = s.size();
    // start position and length of the longest sequence
    // which doesn't contain 3 contiguous occurrences of a and b
    int p = 0, max_length = 0;

    int start = 0; // start of current processing string.
    int count = 1; // length of current processing string.

    for (int i = 1; i < s_size; i++) {

        if (s[i] == s[i - 1]) {
            // if we met two the same letters

            count++;
        }
        else {
            count = 1;
        }
        if (count <= 2) {
            // "i - start + 1" is length of the current processed sequence
            if (i - start + 1 > max_length) {
                max_length = i - start + 1;
                p = start;
            }
        }
        else {
            start = i - 1;
            count = 2;
        }
    }
    return s.substr(p, max_length);
}

int main() {

    cout << "Result: " << solution("aabbaabbaabbaa") << " Expected: aabbaabbaabbaa" << endl;
    cout << "Result: " << solution("aabbaaaaabb") << " Expected: aabbaa" << endl;

    return 0;
}

