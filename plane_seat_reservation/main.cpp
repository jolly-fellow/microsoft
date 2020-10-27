#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> convert(const string & s) {

    vector<vector<int>> res;

    auto s_len = s.length();

    for (int i = 0; i < s_len; i+=3) {
        int row = s[i] - '0';
        int column = s[i+1] - ('A'-1);
        res.push_back({row, column});
    }
    return res;
}

int solution(int n, vector<vector<int>>& reservedSeats)
{
    int ans = n*2;

    unordered_map<int, char> m;

    for (auto r : reservedSeats)
        if (r[1] > 1 && r[1] < 10)
            m[r[0]] |= 1<<(r[1]-2);

    for (auto seats : m)
    {
        bool p1 = !(seats.second & 0b11110000);
        bool p2 = !(seats.second & 0b00111100);
        bool p3 = !(seats.second & 0b00001111);

        if (p1 && p3)
            continue;
        else if (p1 || p2 || p3)
            ans-=1;
        else
            ans-=2;
    }

    return ans;
}

void print(const vector<vector<int>> & v) {
    for ( const auto &row : v ) {
        for ( const auto &s : row ) std::cout << s << ' ';
        std::cout << std::endl;
    }
}

int main() {

    string s = "1A 2F 1C";

    auto t = convert(s);

//    print(t);

    cout << "Result: " << solution(2, t) << " Expected: 2" << endl;

    return 0;
}

