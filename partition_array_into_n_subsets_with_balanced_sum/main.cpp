#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void print(const vector<vector<int>> & v) {
    for (int i = 0; i < v.size(); i++) {
        int sum = 0;
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
            sum += v[i][j];
        }
        cout << " Sum [" << sum << "]" << endl;
    }
}

/*
 This is a typical partition problem (https://en.wikipedia.org/wiki/Partition_problem)
 Although there are many approaches to solve this problem optimized for special cases
 we know nothing special about the input data and requirements so the best solution is to use the simplest
 and the most basic approach - the greedy algorithm.
 */

vector<vector<int>> part(const vector<int> & v, int n) {
    vector<int> sums(n, 0);

    auto compare = [&sums](int a, int b) { return sums[a] >= sums[b]; };
    priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);

    vector<vector<int>> result(n, vector<int>());

    for (int i = 0; i < n; i++) {
        pq.push(i);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
        int c = pq.top(); pq.pop();
        result[c].push_back(v[i]);
        sums[c] += v[i];
        pq.push(c);
    }
    return result;
}

void print_map(const std::multimap<int, std::vector<int> > & m) {
    for (auto & entry : m) {
        std::cout << "Sum: " << entry.first << " :: ";
        for (int i : entry.second) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

std::multimap<int, std::vector<int> > solution(const vector<int> & v, int n) {
    int v_size = v.size();
    std::multimap<int, std::vector<int> > m;

    for (int i = 0, j = v_size - 1; i < n; ++i, --j) {
        m.emplace(v[j],vector<int>{v[j]});
    }

    for (int i = v_size - n - 1; i >= 0; --i) {
        auto node = m.extract(m.begin());
        node.mapped().push_back(v[i]);
        node.key() += v[i];
        m.insert(move(node));
    }
    return m;
}

int main() {

//    auto result = part({1,2,3,4,5}, 3);
    auto result = part({1,2,3,4,5,6,7,8,9,10}, 3);
    print(result);

    cout  << endl << "Second solution:" << endl;

    auto m = solution({1,2,3,4,5,6,7,8,9,10}, 3);
    print_map(m);

    return 0;
}

