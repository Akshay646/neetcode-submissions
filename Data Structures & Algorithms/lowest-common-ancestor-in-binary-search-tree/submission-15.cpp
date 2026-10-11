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
        vector<TreeNode*> path1, path2;
        bool ans1 = DFS(root, p, path1);
        bool ans2 = DFS(root, q, path2);

        int i = path1.size() - 1, j = path2.size() - 1;
        TreeNode* lca;
        while(i >= 0 && j >= 0){
            if(path1[i] == path2[j]){
                lca = path1[i];
            }
            i--;
            j--;
        }
        return lca;
    }
};
