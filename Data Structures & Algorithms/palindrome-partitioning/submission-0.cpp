class Solution {
public:
    bool isValid(int i, int j, string& s){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(int i, vector<string>& path, vector<vector<string>>& ans,
    string& s){
        if(i == s.size()){
            ans.push_back(path);
            return;
        }

        //now try every partition on each level from i to n
        for(int j = i; j < s.size(); j++){
            //here i and j represent a substring of a string
            if(isValid(i, j, s)){
                path.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, path, ans, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
    vector<string> path;
    vector<vector<string>> ans;
    backtrack(0, path, ans, s);
    return ans;
    }
};
