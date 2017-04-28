#include <iostream>
#include <vector>
#include <string>
#include <iterator>

template <class T>
class TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T i) : val(i), left(NULL), right(NULL) {}
    TreeNode* getLeft() { return left; }
    TreeNode* getRight() { return right; }
    void setLeft(TreeNode*);
    void setRight(TreeNode*);
    T getVal() { return val; }
};

template <class T>
void TreeNode<T>::setLeft(TreeNode* r_left) {
    left = r_left;
}

template <class T>
void TreeNode<T>::setRight(TreeNode* r_right) {
    right = r_right;
}

template <class T>
void preorderTraversal(TreeNode<T>* root, std::vector<T>& vector) {
    if (!root) return;
    vector.push_back(root->getVal());
    preorderTraversal(root->getLeft(), vector);
    preorderTraversal(root->getRight(), vector);
    return;
}

int main() {
    TreeNode<int> a(1), b(2), c(3), d(4);

    a.setLeft(&b);
    a.setRight(&c);
    c.setRight(&d);

    std::vector<int> traversal;
    preorderTraversal(&a, traversal);

    for (std::vector<int>::iterator i = traversal.begin(); i != traversal.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    TreeNode<std::string> e("jack"), f("zheng"), g("is"), h("a"), i("student");

    e.setLeft(&f);
    e.setRight(&g);
    g.setLeft(&h);
    h.setLeft(&i);

    std::vector<std::string> str_traversal;
    preorderTraversal(&e, str_traversal);

    for (std::vector<std::string>::iterator i = str_traversal.begin(); i != str_traversal.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

