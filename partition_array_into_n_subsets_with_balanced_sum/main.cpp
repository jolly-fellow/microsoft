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
    int v_size = v.size();
    // in this vector we will keep sums of the partitions
    vector<int> sums(n, 0);

    // in this priority queue we will keep values of the priorities
    // it is just numbers from 0 to numbers of partitions. We will use these numbers as indexes
    // to access sums and to definition priorities of the partitions
    // in other words the sums tied with the partitions by these priority values.

    // Pay attention that the sums we keep in the external vector described above,
    // so we need to declare a special comparator
    // for the queue in order to sort the queue by the priority values.
    auto compare = [&sums](int a, int b) { return sums[a] >= sums[b]; };
    priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);

    // here we will keep values of the partitions
    vector<vector<int>> result(n, vector<int>());

    // generate numbers of the priority values.
    for (int i = 0; i < n; i++) {
        pq.push(i);
    }

    // The input array is sorted ascending so we will process it from the back to the front.
    for (int i = v_size - 1; i >= 0; --i) {
        // take the highest priority from the queue
        int c = pq.top(); pq.pop();
        // put the max value from the input array to the partition with the highest priority,
        // that is partition with the lowest sum.
        result[c].push_back(v[i]);
        // increase the lowest sum to max value from the input array.
        sums[c] += v[i];
        // push back the priority value. After this call the queue will be resorted corresponding to
        // new value of the sums array.
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

std::multimap<int, std::vector<int> > solution2(const vector<int> & v, int n) {
    int v_size = v.size();
    std::multimap<int, std::vector<int> > m;

    for (int i = 0, j = v_size - 1; i < n; ++i, --j) {
        m.emplace(v[j],vector<int>{v[j]});
    }

    for (int i = v_size - n - 1; i >= 0; --i) {

        std::pair<int, std::vector<int> > tmp_pair = *(m.begin());
        tmp_pair.second.push_back(v[i]);
        tmp_pair.first += v[i];
        m.erase(m.begin());
        m.emplace(tmp_pair);
    }
    return m;
}


int main() {

//    auto result = part({1,2,3,4,5}, 3);
    auto result = part({1,2,3,4,5,6,7,8,9,10}, 3);
    print(result);

    cout  << endl << "Second solution:" << endl;

    auto m = solution2({1,2,3,4,5,6,7,8, 9, 10}, 3);
    print_map(m);

    return 0;
}

