#include <iostream>
#include <vector>
#include <iterator>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    bool visited;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), visited(false), left(NULL), right(NULL) {}

    bool isLeaf() { return !left && !right; }
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> postorder;
    stack<TreeNode*> visitor;
    TreeNode* temp;

    visitor.push(root);

    while (!visitor.empty()) {
        temp = visitor.top();

        if (temp->isLeaf() || temp->visited) {
            postorder.push_back(temp->val);
            visitor.pop();
        } else {
            if (temp->right)
                visitor.push(temp->right);
            if (temp->left)
                visitor.push(temp->left);
            temp->visited = true;
        }
    }
    return postorder;
}

int main() {
    TreeNode a(1), b(2), c(3);
    a.left = &b;
    a.right = &c;

    vector<int> traversal = postorderTraversal(&a);

    for (vector<int>::iterator i = traversal.begin(); i != traversal.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";
}
