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
        while(root){
            //check if both p & q belong to left
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }//check if both p & q belong to left
            else if(p->val > root->val && q->val > root->val){
                root = root->right;
            }
            else{
                return root;
            }
        }
        return nullptr;
    }
};
