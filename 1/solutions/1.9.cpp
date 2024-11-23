#include <iostream>
#include <stack>

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BinaryTree class
class BinaryTree {
private:
    TreeNode* root;

    // Helper function to insert a node
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->val) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    

    // Iterative inorder traversal
    void inorderTraversalIterative(TreeNode* node) {
        std::stack<TreeNode*> stack;
        TreeNode* current = node;

        while (current != nullptr || !stack.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            // Current must be nullptr at this point
            current = stack.top();
            stack.pop();
            std::cout << current->val << " ";

            // We have visited the node and its left subtree. Now, it's right subtree's turn
            current = current->right;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Public method to insert a node
    void insert(int value) {
        root = insert(root, value);
    }


    // Public method for iterative inorder traversal
    void inorderTraversal() {
        inorderTraversalIterative(root);
        std::cout << std::endl;
    }

   
};

// Main function to demonstrate usage
int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Iterative Inorder Traversal: ";
    tree.inorderTraversal();

    

    return 0;
}