class Solution {
public:
    void backtrack(int openP, int closeP, vector<string>& path, vector<string>& ans,
    int n){
        //we have got one of the valid permutation of parenthesis
        if(openP == n && closeP == n){
            string s = "";
            for (const auto& str : path) {
                s += str;
            }
            ans.push_back(s);
            return;
        }

        //Validation check 1 for add open parenthesis
        if(openP < n){
            path.push_back("(");
            //used one open parenthesis, so openP + 1, go to next possible valid
            //parenthesis
            backtrack(openP + 1, closeP, path, ans, n);
            //backtrack, as when returning from down, removed already added brackets
            path.pop_back();
        }

        //Validation check 2 for adding closing parenthesis
        if(closeP < openP){
            path.push_back(")");
            backtrack(openP, closeP + 1, path, ans, n);
            path.pop_back();
        }

        //above both conditions make sure we add only valid parentheis in the path
    }
    vector<string> generateParenthesis(int n) {
        vector<string> path, ans;
        backtrack(0, 0, path, ans, n);
        return ans;
    }
};
