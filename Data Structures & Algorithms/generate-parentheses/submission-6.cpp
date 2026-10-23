class Solution {
public:
    void dfs(int n, string& path, vector<string>& ans, int openB, int closeB){
        //when opens and closed are = n,we get one of the 
        //valid parenthesis, but valedity is totally rely
        //on the way we add parenthesis in the path
        if(openB == n && closeB == n){
            ans.push_back(path);
        }
        
        //we can keep adding '(' as long as its < n
        if(openB < n){
            path.push_back('(');
            //go to next choice
            dfs(n, path, ans, openB + 1, closeB);
            //backtrack to retsore the state so another choice
            //explore gets fresh previous state of data
            path.pop_back();
        }
        //now when opens > closes, it is the valid case to
        //try adding closing bracket
        if(openB > closeB){
            path.push_back(')');
            //go to next choice
            dfs(n, path, ans, openB, closeB + 1);
            //backtrack to retsore the state so another choice
            //explore gets fresh previous state of data
            path.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string path;
        vector<string> ans;
        dfs(n, path, ans, 0, 0);
        return ans;
    }
};
