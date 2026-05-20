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
    vector<int> rightSideView(TreeNode* root) {
       //Think of BFS(Level Order Traversal)
       //Analyse view from diagram, then it boils down to considering only last element
       //in the particular level.
       vector<int> ans;
       if(root == nullptr)return ans;
       queue<TreeNode*> q;
       q.push(root);

       while(!q.empty()){
            int lSize = q.size();
            //now add childern
            for(int i = 0; i < lSize; i++){
                TreeNode* node = q.front();
                q.pop();
                //we only care about the last element in the particular level
                if(i == lSize - 1){
                    ans.push_back(node->val);
                }

                //add childern
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
       }
       return ans;
    }
};