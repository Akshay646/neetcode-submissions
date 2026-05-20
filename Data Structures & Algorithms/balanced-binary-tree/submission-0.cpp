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
pair<bool, int> getHeight(TreeNode* root){
        if(root == nullptr)return {true, 0};

        //get the left height
        auto[b1,lH] = getHeight(root->left);
        //get the right height
        auto[b2,rH] = getHeight(root->right);

        //first check if any of the tree is unbalnce, overall tree become unbalanced
        if(!b1 || !b2){return {false, 0};}

        if(abs(lH - rH) > 1)return {false, 0};

        //height of tree is always max(lH, rH)
        return {true, 1 + max(lH, rH)};

    }
    bool isBalanced(TreeNode* root) {
        auto[ans, h] = getHeight(root);
        return ans;
    }
};
