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
    void dfsSerialization(TreeNode* node, string& ans){
        if(node == nullptr){
            ans += "N,";
            return;
        }
        ans += to_string(node->val);
        ans += ",";
        dfsSerialization(node->left, ans);
        dfsSerialization(node->right, ans);
    }
    string serialize(TreeNode* root) {
       string sTree = "";
       dfsSerialization(root, sTree);
       //removing leading ','
       sTree.pop_back();
       return sTree;
    }

    vector<string> split(string s, char delimeter){
        vector<string> tokens;
        string token; //=> temp variable to use in getline to store each result
        stringstream ss(s);

        //getline(stream, string_variable, delimiter)
        //string_variable store results after given delimeter hits
        while(getline(ss, token, delimeter)){
            tokens.push_back(token);
        }
        return tokens;
    }

    TreeNode* dfsDeSerialization(int& preInd, vector<string>& nodes){

        //if node == 'N', it means just return nullptr which will get attached
        //to respective call of left/right subtree
        //Every time you read a token (node or N), you must advance preInd.
        if(nodes[preInd] == "N"){
            //we increment preInd to go to next element as we consume N also as null
            //and to consume next element
            preInd++; 
            return nullptr;
        }
        
        //as in preorder, we create node first
        TreeNode* root = new TreeNode(stoi(nodes[preInd]));
        //move to next node in nodes
        preInd++;

        //now construct left and right subtreefor given node
        //recursie dfs call itself takes care of increameting preInd so you do not
         //have to do it for each call
        root->left = dfsDeSerialization(preInd, nodes);
        root->right = dfsDeSerialization(preInd, nodes);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes = split(data, ',');
        //use preorder as it highly matches the nature of serialized format and intuitve
        int preInd = 0;
        return dfsDeSerialization(preInd, nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));