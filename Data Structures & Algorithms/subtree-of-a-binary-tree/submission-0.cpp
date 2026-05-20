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
    bool isSameTree(TreeNode* t1, TreeNode* t2){
        if(t1 == nullptr && t2 == nullptr)return true;
        if(t1 == nullptr || t2 == nullptr)return false;
        if(t1->val != t2->val)return false;

        return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //brute force
        if(isSameTree(root, subRoot))return true;
        //make sure root left/right does not become null
        if(root != nullptr){
        bool f1 = isSubtree(root->left, subRoot);
        bool f2 = isSubtree(root->right, subRoot);
        if(f1 || f2)return true;
        }

        return false;
    }
};
