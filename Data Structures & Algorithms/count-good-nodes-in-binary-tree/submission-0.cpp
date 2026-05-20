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
    int dfs(TreeNode* node, int maxVal) {
        if(node == nullptr)return 0;
        //preorder: set the counter
        int counter = 0;
        if(node->val < maxVal){counter = 0;}//as this node  will not  include in counter
        else{counter = 1;}//we got the good node

        //track the max so far for future dfs conditions
        maxVal = max(maxVal, node->val);

        //commulate the result(counter) and then call on both left and right subtree
        counter = counter + dfs(node->left, maxVal);
        counter = counter + dfs(node->right, maxVal);

        //counter will return at the end
        return counter;

    }
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
