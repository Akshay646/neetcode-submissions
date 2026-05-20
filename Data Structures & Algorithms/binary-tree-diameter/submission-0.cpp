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
    int GetDiameter(TreeNode* node, int& diameter){
        if(node == nullptr){
            return 0;
        }

        //get the height of left subtree
        int leftHeight = GetDiameter(node->left, diameter);
        int rightHeight = GetDiameter(node->right, diameter);

        //now when both left and right heights are available for a node
        //as diameter, we always consider path which has maximum height
        diameter = max(diameter, leftHeight + rightHeight);
        
        //return height of the current subtree(left/right)
        return 1 + max(leftHeight, rightHeight);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int ans = GetDiameter(root, diameter);
        return diameter;
    }
};