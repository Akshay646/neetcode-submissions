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
    void inorder(TreeNode* node, int& k, int& ans){
        //Think of  for a valid BST, the inorder is absolutely an increasing, if we
        //find inorder, the kth element will be the kth smaller element we get as 
        //for BST, inorder follows strict increasing order.
        if(node == nullptr)return;
        inorder(node->left, k, ans);
        k -= 1;
        if(k == 0){ ans = node->val;return;}
        inorder(node->right, k, ans);
    }
    int kthSmallest(TreeNode* root, int& k) {
        int ans = 0;
        inorder(root, k, ans);
        return ans;
    }
};