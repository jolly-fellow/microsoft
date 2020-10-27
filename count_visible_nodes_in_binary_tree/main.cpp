#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct TreeNode {
    int val;

    TreeNode * left = nullptr;
    TreeNode * right = nullptr;

    TreeNode(int v): val(v) {
    }
};

// Time: O(n)
// Space: O(n)
int countVisibleNodes(TreeNode * node, int maxSoFar) {
    int count = 0;

    if (node->val >= maxSoFar) {
        count = 1;
        maxSoFar = node->val;
    }
    return count + countVisibleNodes(node->left, maxSoFar) + countVisibleNodes(node->right, maxSoFar);
}

int countVisibleNodes(TreeNode * root) {
    return countVisibleNodes(root, std::numeric_limits<int>::min());
}


int main() {

    cout << "" << endl;

    return 0;
}

