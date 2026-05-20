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
    int maxDepth(TreeNode* root) {
       if(root == nullptr)return 0; //no height

        //1.Go and get left subtree height
       int lTreeDepth = maxDepth(root->left);
        //2.Go and get right subtree height
       int rTreeDepth = maxDepth(root->right);

       //return 1 + maximum height among those
       return 1 + max(lTreeDepth, rTreeDepth);
    }
};
