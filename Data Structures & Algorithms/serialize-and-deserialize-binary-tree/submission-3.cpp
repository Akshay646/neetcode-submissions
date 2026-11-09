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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if(root == nullptr){return "";}
        q.push(root);
        string s;
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();

            if(curNode == nullptr){
                s.append("#,");
                continue;
            }
            s.append(to_string(curNode->val) + ",");
            q.push(curNode->left);
            q.push(curNode->right);
        }
        //remove trailing comma
        s.pop_back();
        return s;
    }

    //split helper
    vector<string> Split(string s, char delimeter){
        stringstream ss(s);
        string token;
        vector<string> tokens;
        while(getline(ss, token, delimeter)){
            tokens.push_back(token);
        }
        return tokens;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")return nullptr;
        vector<string> nodes = Split(data, ',');
        int n = nodes.size();
       
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        int i = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            
            if(i < n){
                TreeNode* curLeft = nodes[i] == "#" ? nullptr :
                new TreeNode(stoi(nodes[i]));
                curNode->left = curLeft;
                i++;
                //do not push null node in queue
                if(curLeft != nullptr){
                    q.push(curLeft);
                }
            }
            if(i < n){
                TreeNode* curRight = nodes[i] == "#" ? nullptr :
                new TreeNode(stoi(nodes[i]));
                curNode->right = curRight;
                i++;
                //do not push null node in queue
                if(curRight != nullptr){
                    q.push(curRight);
                }
            }
        }
        return root;
    }
};
