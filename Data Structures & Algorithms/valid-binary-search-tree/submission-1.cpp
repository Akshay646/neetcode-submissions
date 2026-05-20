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
    void inOrder(TreeNode* node, vector<int>& nodes){
        if(node == nullptr)return;
        inOrder(node->left, nodes);
        nodes.push_back(node->val);
        inOrder(node->right, nodes);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nodes;
        inOrder(root, nodes);
        //Inorder traversal of binary tree should be strictly increasing
        for(int i = 1; i < nodes.size(); i++){
            if(nodes[i] <= nodes[i - 1]){return false;}
        }
        return true;
    }
};
