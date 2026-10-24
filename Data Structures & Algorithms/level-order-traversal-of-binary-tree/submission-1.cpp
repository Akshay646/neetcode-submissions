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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){return {};}
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> tmp;
            for(int i = 0; i < levelSize; i++){
                TreeNode* curNode = q.front();
                q.pop();
                //curNode->val will never be null since
                //we never insert null nodes anyways
                tmp.push_back(curNode->val);
                //before addinng left and right childern
                //make sure they are not null
                if(curNode->left != nullptr){
                    q.push(curNode->left);
                }
                if(curNode->right != nullptr){
                    q.push(curNode->right);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
