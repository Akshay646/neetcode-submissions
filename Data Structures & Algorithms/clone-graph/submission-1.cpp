/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        Node* cloneCur = nullptr;
        unordered_map<Node*, Node*> mp;
        if (node == nullptr) return nullptr;
        q.push(node);
        while(!q.empty()){
            Node* tmpNode = q.front();
            //first check if cloneCur is clonned or not
            if(!mp.count(tmpNode)){
                cloneCur = new Node(tmpNode->val);
                mp[tmpNode] = cloneCur;
                }else{
                    cloneCur = mp[tmpNode];
                }
            q.pop();
            for(auto nbr : tmpNode->neighbors){
                //secondly check if nbr are already cloned, if so use them else
                //create new nodes for them
                Node* nNbr;
                if(!mp.count(nbr)){
                nNbr = new Node(nbr->val);
                mp[nbr] = nNbr;
                q.push(nbr);
                }else{
                    nNbr = mp[nbr];
                }
                //Add it to cloneCur
                cloneCur->neighbors.push_back(nNbr);
            }
        }
        // Throughout the BFS, every original node is mapped to its cloned node.
        // The problem asks us to return the clone of the given starting node,
        // which is stored in the map.
        return mp[node];
    }
};
