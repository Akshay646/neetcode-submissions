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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p == nullptr && q == nullptr)return true;
       if(p == nullptr || q == nullptr)return false;
       if(p->val != q->val)return false;

        //check result of boths lefts
       bool isLTreeSame = isSameTree(p->left, q->left);
        //check result of boths rights
       bool isRTreeSame = isSameTree(p->right, q->right);

       //now boths return values should be true to declare a same trees
       return isLTreeSame && isRTreeSame;
    }
};