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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //By considering BST propert(left has mins, right has max for each node)
        TreeNode* node = root;
       while(node != nullptr){
        if(p->val > node->val && q->val > node->val){
            node = node->right;
        }
        else if(p->val < node->val && q->val < node->val){
            node = node->left;
        }
        else{
            break;
        }
       }
        return node;
    }
};
