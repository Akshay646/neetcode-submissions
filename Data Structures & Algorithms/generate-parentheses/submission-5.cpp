class Solution {
public:
    void backtrack(int n, int oB, int cB, vector<string>& ans, string& ds){
        if(oB == n && cB == n){
            ans.push_back(ds);
            return;
        }
        //pop_back() correctly undoes the choice after returning from that recursive
        //branch, which is what makes the backtracking work.

        //you can add open brackets
        if(oB < n){
            ds.push_back('(');
            backtrack(n, oB + 1, cB, ans, ds);
            ds.pop_back();
        }
        //you can add closing brackets
        if(cB < oB){
            ds.push_back(')');
            backtrack(n, oB, cB + 1, ans, ds);
            ds.pop_back();
            
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;
        backtrack(n, 0, 0, ans, ds);
        return ans;
    }
};
