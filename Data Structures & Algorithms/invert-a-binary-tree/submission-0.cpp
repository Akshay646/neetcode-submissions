/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* node){
          //you can use any traversal like dfs or bfs
        //I am using dfs due to its intuitiveness, both have same TC
        if(node == nullptr){return nullptr;}
        //Get the left and right subtree
        TreeNode* lChild = invertTree(node->left);
        TreeNode* rChild = invertTree(node->right);

        //now for current node left, assign right &  vice versa, i.e. swap
        node->right = lChild;
        node->left = rChild;

        //return the updated(inverted) node to previous call
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
};
