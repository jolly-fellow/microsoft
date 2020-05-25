#include <iostream>
#include <vector>

using namespace std;

string solution(const string& s, int k) {

    auto last_space = s.find_last_of(' ', k);
    auto last_letter = s.find_last_not_of(' ', last_space);
    return s.substr(0, last_letter+1);
}

int main() {

    cout << "[" << solution("codility We            test coders", 14) << "]" << " Expected: [codility We]" << endl;

    return 0;
}

