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
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, 
    unordered_map<int, int>& inorderMap, int& preInd, int inLeft, int inRight){
        //if boundaries in inorder goes out of bounds means no more left/right
        //nodes to visit. return null, so null will be assign to left/right of root
        if(inLeft > inRight)return nullptr;

        //create a root node
        TreeNode* root = new TreeNode(preorder[preInd]);
        //Get roots position in inorder to further explore left and right subtrees
        int inIndx = inorderMap[preorder[preInd]];
        preInd++;
        //Now build tree for root's left part and right part
        //inLeft stays inLeft and inRight changes to inIndx - 1 for left part
        root->left = _buildTree(preorder, inorder, inorderMap, preInd, inLeft, inIndx - 1);
        //inLeft becomes inIndx + 1, and right stays the same
        //for right subtree, based on preorder(root->left-right), 
        //preInd will be starting from all leftsubtrees nodes for given root
        //int leftSize = inIndex - inLeft;
        root->right = _buildTree(preorder, inorder, inorderMap, preInd, inIndx + 1, inRight);

        //now return formed root
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap; //{element, index}
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        int preInd = 0, inLeft = 0, inRight = inorder.size() - 1;
        return _buildTree(preorder, inorder, inorderMap, preInd, inLeft, inRight);
    }
};
