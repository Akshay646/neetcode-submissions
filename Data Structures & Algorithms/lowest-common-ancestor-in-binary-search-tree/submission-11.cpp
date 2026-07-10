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
    bool dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        //if you its null, you reach end, and could not find path with node in it
       if(root == nullptr)return false;

       if(root == node){
        path.push_back(root);
        return true;
       }

       if(dfs(root->left, node, path) || dfs(root->right, node, path)){
        path.push_back(root);
        return true;
       }
       return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)return nullptr;
        //check if both p & q belong to left
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            return root;
        }
    }
};
