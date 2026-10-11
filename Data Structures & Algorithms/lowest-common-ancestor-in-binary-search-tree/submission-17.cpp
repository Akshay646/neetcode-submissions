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
    bool DFS(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        if(root == nullptr){
            return false; //it reaches null means we never got 'node' in given path
        }
        if(root == node){
            //we compare nodes directly as those are objects so we can compare
            //if current visiting node(root) == node(target)
            path.push_back(root);
            return true;
            //return true so true gets propagated upwards, helps tracking path
        }

        if(DFS(root->left, node, path) || DFS(root->right, node, path)){
            //one of the paths returns true, means root can be added in path
            path.push_back(root);
            return true; //propagate true to its upstream calls;
        }

        //if we reach here, we anyway never found node in path
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != nullptr){
            //check whether both p,q are in left subtree, if so just search in left
            if(p->val < root->val && q->val < root->val){
                //your search space becomes now left subtree
                root = root->left;
            }
            else if(p->val > root->val && q->val > root->val){
                 //your search space becomes now right subtree
                root = root->right;
            }
            else{
                //it means p goes to left and q goes to right, which makes root
                //an least common ancestor as split happens here
                return root;
            }
        }

        //it means we never found LCA(will not execute given test cases are valid)
        return nullptr;
    }
};
