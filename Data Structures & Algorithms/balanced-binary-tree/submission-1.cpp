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
    pair<bool, int> dfs(TreeNode* node){
        if(node == nullptr){
            return {true, 0};
        }

        auto[lF, lH] = dfs(node->left);
        auto[rF, rH] = dfs(node->right);

        if((!lF || !rF) || abs(lH - rH) > 1){
            return {false, -1};
        }

        return {true, 1 + max(lH, rH)};
    }
    bool isBalanced(TreeNode* root) {
        auto [isBln, val] = dfs(root);

        return isBln;
    }
};