#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/* The given array in this task is a usual way to keep a binary graph. Each item of the array is a node of the graph
 * Each node has one or two connected nodes (left and right) on the distance of value which the array item contains.
 * So in order to find if we can reach 0 we should find if there is a way on the graph from the given node to node 0.
 * In order to find a shortest way from one node of the graph to another one we need to implement Breadth-First Search
 * algorithm
*/

// Recursive solution

bool BFS_r(const vector<int>& v, int i, vector<bool> & visited) {
    // if the given start node has index inside of the array
    // and we processing this node for first time
//    if (i >= 0 && i < v.size() && visited.insert(i).second) {
    if (i >= 0 && i < v.size() && !(visited[i])) {
        visited[i] = true;
        // If zero node is found return true or recursive call the function to process left and right connected nodes
        return v[i] == 0 ||
                BFS_r(v, i + v[i], visited) || BFS_r(v, i - v[i], visited);
    }
    return false;
}


// unordered_set<int> visited;
///
/// \param v container of a graph
/// \param i start index
/// \return
bool solution_r(const vector<int>& v, int i) {
    vector<bool>  visited(v.size(), false);
    return BFS_r(v, i, visited);
}


bool solution_i(const vector<int>& v, int start) {
    int v_size = v.size();
    vector<bool> visited(v.size(), false);
    std::queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (v[i] == 0) return true;
        if (visited[i]) continue;
        visited[i] = true;
        if (i + v[i] < v_size) { q.push(i + v[i]); }
        if (i - v[i] >= 0) { q.push(i - v[i]); }
    }
    return false;
}


int main() {

    cout << "Result: " << solution_i({3, 4, 2, 3, 0, 3, 1, 2, 1}, 7) << " Expected: 1" << endl;

    return 0;
}

