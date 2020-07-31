#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

char safe_tolower(char ch) {
    return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

string solution (const string & s) {
    char max_char = 0;
    string res("NO");
    unordered_set<char> us(s.begin(), s.end());

    for(auto c : s) {
        if(isupper(c)) {
            if(us.count(safe_tolower(c))) {
                max_char = max(c, max_char);
            }
        }
    }

    if(max_char) { res = max_char; }

    return res;


}

int main() {

    cout << solution("admeDCAB") << " Expected: D" << endl;

    return 0;
}

