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
    pair<bool, int> DFS(TreeNode* root){
        if(root == nullptr){return {true, 0};}

        auto [b1, lH] = DFS(root->left);
        auto [b2, rH] = DFS(root->right);
        
        if(!b1 || !b2 || abs(lH - rH) > 1){return {false, -1};}
        
        return {true, 1 + max(lH, rH)};
    }
    
    bool isBalanced(TreeNode* root) {
        auto [isBln, mxH] = DFS(root);
        return isBln;
    }
};