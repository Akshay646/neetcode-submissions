class Solution {
public:
    void backtrack(vector<string>& ans, string& path, int n, 
    int openT, int closeT){
        if(openT == n && closeT == n){
            ans.push_back(path);
            return;
        }
        //1. Adding ( is always possible when ind < n
        //2. Add ) only when you have enough (. i.e. ( >= )
        if(openT < n){
            path.push_back('(');
            backtrack(ans, path, n, openT + 1, closeT);
            path.pop_back();
        }
        if(openT > closeT){
            path.push_back(')');
            backtrack(ans, path, n, openT, closeT + 1);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int openT = 0, closeT = 0;
        vector<string> ans; string path = "";
        backtrack(ans, path, n, openT, closeT);
        return ans;
    }
};
