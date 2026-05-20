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
    void preOrder(TreeNode* node, vector<int>& arr){
        if(node == nullptr){
            arr.push_back(INT_MIN);
            return;
        }
        arr.push_back(node->val);
        preOrder(node->left, arr);
        preOrder(node->right, arr);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pTree, qTree;
        preOrder(p, pTree);
        preOrder(q, qTree);

        return pTree == qTree;
    }
};