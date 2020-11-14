#include <iostream>
#include <vector>

using namespace std;

/*
By definition of lexicographical order each next string is larger
 than the previous one А < АА < ААА < АAB < ААC < АB < B < … < ZZZ

Since we could only remove one character, we should remove the first char
 we meet that is greater than the next from left to right.
 In this case our string will be lexicographically smallest.

May be it looks more clear on numbers. Let us have a number 1324,
 we should remove 3 in order to make it smallest.
 Or let us have a number 389575, it is obvious we should remove 9 to make it smallest.
 */

string solution(const string &s) {

    int i = 0, s_size = s.size();
    string result(s);
    for (; i < s_size - 1; ++i) {
        if (s[i] > s[i + 1]) {
            break;
        }
    }
    result.erase(i, 1);
    return result;
}

int main() {

    cout << "Result: " << solution("bba") << " Expected: ba" << endl;
    cout << "Result: " << solution("abczd") << " Expected: abcd" << endl;
    cout << "Result: " << solution("abcdz") << " Expected: abcd" << endl;

    return 0;
}

