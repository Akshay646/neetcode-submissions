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
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr)return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int lSize = q.size();

            //process the level
            for(int i = 0; i  < lSize; i++){
                TreeNode* node = q.front();
                q.pop();
                //as we  are sure node will never be null as we push only valid nodes
                tmp.push_back(node->val);

                //now add its childern
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

            //finally add current level elements into result array
            ans.push_back(tmp);
        }
        return ans;
    }
};
