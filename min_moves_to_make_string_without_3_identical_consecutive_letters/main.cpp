#include <iostream>
#include <string>

using namespace std;

int solution(string S) {
    int wl = 0, wr = 0, ans = 0;
    while (wr < S.size()) {
        if (S[wl] == S[wr]) ++wr;
        else {
            ans += (wr - wl) / 3;
            wl = wr;
        }
    }
    ans += (wr - wl) / 3;
    return ans;
}

int main() {

    cout << "Result " << solution("baaaaa") << " expected: 1" << endl;
    cout << "Result " << solution("baaabbaabbba") << " expected: 2" << endl;
    cout << "Result " << solution("baabab") << " expected: 0" << endl;

    return 0;
}

