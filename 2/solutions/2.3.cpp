#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <limits>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

    
    // Iterative preorder traversal
    void preorderTraversalIterative(TreeNode* node) {
        std::stack<TreeNode*> stack;
        TreeNode* current = node;

        while (current != nullptr || !stack.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                std::cout << current->val << " ";
                stack.push(current);
                current = current->left;
            }

            // Current must be nullptr at this point
            current = stack.top();
            stack.pop();
            // We have visited the node and its left subtree. Now, it's right subtree's turn
            current = current->right;
        }
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
   
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& indexMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    // The first node in preorder is the root
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);

    // Find the position of root in inorder array
    int rootIndex = indexMap[rootVal];

    // Number of elements in left subtree
    int numsLeft = rootIndex - inStart;

    // Recursively build left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, preStart + 1, preStart + numsLeft, inStart, rootIndex - 1, indexMap);
    root->right = buildTreeHelper(preorder, inorder, preStart + numsLeft + 1, preEnd, rootIndex + 1, inEnd, indexMap);

    return root;
}


public:
    
  
   TreeNode*  GetRoot(){return root;}

   BinaryTree* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> indexMap; // Maps value to its index in inorder array

    // Populate map with index of each value in inorder array
    for (int i = 0; i < inorder.size(); ++i) {
        indexMap[inorder[i]] = i;
    }

    TreeNode* newroot= buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, indexMap);
    return new BinaryTree(newroot);
    }
    BinaryTree( TreeNode* myroot=nullptr) : root(myroot) {}

    // Public method to insert a node
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method for iterative inorder traversal
    void preorderTraversal() {
        preorderTraversalIterative(root);
        std::cout << std::endl;
    }
    // Public method for iterative inorder traversal
    void inorderTraversal() {
        inorderTraversalIterative(root);
        std::cout << std::endl;
    }
  

   
};


int GetMinimumOfThree(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}


int GetMaximumOfThree(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}


// Find Minimum of a tree (subtree)
    int GetMinimum(TreeNode* treeroot)
    {
      if (treeroot == nullptr) return  std::numeric_limits<int>::max();
      auto rootval =  treeroot->val ;
      auto leftmin = GetMinimum(treeroot->left);
      auto rightmin = GetMinimum(treeroot->right);
      return  GetMinimumOfThree(rootval,leftmin,rightmin);


    }
    
    int GetMaximum(TreeNode* treeroot)
    {
      if (treeroot == nullptr) return  std::numeric_limits<int>::min();
      auto rootval =  treeroot->val ;
      auto leftmax =  GetMaximum(treeroot->left);
      auto rightmax =  GetMaximum(treeroot->right);
      return  GetMaximumOfThree(rootval,leftmax,rightmax);
    }

    /** the tree is Binary Search tree <=> for all node in this tree the follwing 2 hold
        1.  Value(node) >= MaxValue(node->left)
        2.  Value(node) <= MinValue(node->right)  
    */

    bool IsItBST(TreeNode* treeroot)
    {
       if (treeroot == nullptr) return true;
       auto leftmax = GetMaximum(treeroot->left);
       auto rightmin = GetMinimum(treeroot->right);
       auto rootval =  treeroot->val ;
       bool rootisok=false,leftisok=false,rightisok=false;
       if ((rootval >= leftmax)  && (rootval <= rightmin)) rootisok=true;
       leftisok = IsItBST(treeroot->left);
       rightisok = IsItBST(treeroot->right);
       return rootisok &&  leftisok && rightisok;
       
       
       
       
    }
int main() {

    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout <<  (IsItBST(tree.GetRoot()) ? "This tree is a BST" : "This is not a BST" ) << std::endl;
 
  

    return 0;
}