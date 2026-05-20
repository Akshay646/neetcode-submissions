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
    bool storePath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path)
    {
        if(root == nullptr){return false;}
        if(root->val == node->val){
            path.push_back(root);
            return true;
        }
        if(storePath(root->left, node, path) || storePath(root->right, node, path))
        {
            path.push_back(root);
            //It means one of the function returns true
            //So, return true and tell its previous call that this path has
            //our target so the prev node val also get into path
            return true;
        }

        //never find that target in path
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root == nullptr || root->val == p->val || root->val == q->val)
         {
            return root;
         }

         //now goto each left and right subtree
         TreeNode* left = lowestCommonAncestor(root->left, p, q);
         TreeNode* right = lowestCommonAncestor(root->right, p, q);

         if(left == nullptr){return right;}
         else if(right== nullptr){return left;}
         else{
            return root;//LCS, both left and right has return matching
            //values from anywhere in the deep path
         }

    }
};
