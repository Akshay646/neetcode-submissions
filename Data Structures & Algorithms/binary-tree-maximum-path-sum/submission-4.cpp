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
//why INT_MIN, becuase nodes can be negative
    int maxSum = INT_MIN;
    int dfs(TreeNode* node){
        if(node == nullptr)return 0;

        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);

        if(leftSum < 0)leftSum = 0;
        if(rightSum < 0)rightSum = 0;

        maxSum = max(maxSum, node->val + leftSum + rightSum);

        //Here we return node->val and max between left and right sum
        //because, this helps decide a max path for its parent.
        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};