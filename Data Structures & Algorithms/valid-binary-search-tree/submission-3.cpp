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
    TreeNode* prev = nullptr;
    bool inOrder(TreeNode* node){
        if(node == nullptr)return true;
        if(!inOrder(node->left))return false;
        //we're comparing increasing array condition on the fly
        if(prev && node->val <= prev->val)return false;
        prev = node;
        if(!inOrder(node->right))return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inOrder(root);
    }
};
