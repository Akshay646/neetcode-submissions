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
    int dfs(TreeNode* node, int& maxSum){
        //if root is null, return 0 as it does not alter sum
        if(node == nullptr)return 0;

        //get the left sum
        int leftSum = dfs(node->left, maxSum);
        //get the right sum
        int rightSum = dfs(node->right, maxSum);

        //IMP edge case -> see notes
        if(leftSum < 0) leftSum = 0;
        if(rightSum < 0) rightSum = 0;

         //When we get both left & right sum for give node
        //store the max all the way
        maxSum = max(maxSum, node->val + leftSum + rightSum);

        //this is the actual  return for both recursive calls
        //we only care left/right which gives max sum
        return node->val + max(leftSum, rightSum);
        
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int data = dfs(root, maxSum);
        return maxSum;

    }
};
