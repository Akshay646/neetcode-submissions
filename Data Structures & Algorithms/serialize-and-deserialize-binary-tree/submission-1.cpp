/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialisedBT = "";
        queue<TreeNode*> q;
        if(root == nullptr)return serialisedBT;
        q.push(root);

        while(!q.empty()){
            
            TreeNode* node = q.front(); 
            q.pop();
            if(node == nullptr){
                serialisedBT += "N,";
                continue;
            }
            serialisedBT += to_string(node->val) + ",";

            //adding node's childern in next level to process
            {q.push(node->left);}
            {q.push(node->right);}
            
        }

        //remove trailing ',';
        serialisedBT.pop_back();
        return serialisedBT;
    }

    vector<string> Split(string data){
        vector<string> tokens;
        string token = "";
        stringstream ss(data);
        while(getline(ss, token, ',')){
            tokens.push_back(token);
        }
        return tokens;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        if(data.empty())return root;
        vector<string> tokens = Split(data);
        if(tokens[0] == "N")return root;
        queue<TreeNode*> q;
        root = new TreeNode(stoi(tokens[0]));
        q.push(root);

        //now starts with i = 1 as we have already added 0th token
        int i = 1;
        while(!q.empty() && i < tokens.size()){
            TreeNode* curr = q.front();
            q.pop();

            //add left child
            if(tokens[i] != "N"){
                curr->left = new TreeNode(stoi(tokens[i]));
                q.push(curr->left);
            }
            //MOve to next child
            i++;

            //add right child
            if(tokens[i] != "N"){
                curr->right = new TreeNode(stoi(tokens[i]));
                q.push(curr->right);
            }
            //move to next child
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));