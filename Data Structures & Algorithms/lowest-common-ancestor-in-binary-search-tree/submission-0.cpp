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
         vector<TreeNode*> path1, path2;
         bool findPath1 = storePath(root, p, path1);
         bool findPath2 = storePath(root, q, path2);

        //now check last distict val in both paths
        int i = path1.size() - 1, j = path2.size() - 1;
        TreeNode* lcs = nullptr;
        while(i >= 0 && j >= 0)
        {
            if(path1[i]->val == path2[j]->val)
            {
                lcs = path1[i]; //current lcs so far
            }
            else{break;}//we have got  lcs
            i--;
            j--;
        }

        return lcs;
    }
};
