#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(const string &day, int k) {
    vector<string> days = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    unordered_map<string, int> week_map = {{"Sun", 0},
                                           {"Mon", 1},
                                           {"Tue", 2},
                                           {"Wed", 3},
                                           {"Thu", 4},
                                           {"Fri", 5},
                                           {"Sat", 6}};

    return days[(week_map[day] + k) % 7];
}

int main() {

    cout << solution("Sat", 23) << " Expected: Mon" << endl;

    return 0;
}

