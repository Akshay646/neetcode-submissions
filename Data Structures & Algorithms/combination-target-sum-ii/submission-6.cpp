class Solution {
public:
    void dfs(int i, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans, int target){
        //if you find the target
        if(target == 0){
            ans.push_back(path);
            return;
        }

        //if target goes below 0 or i goes beyond candidates
        if(target < 0 || i >= candidates.size()){
            return;
        }

        //take the current element
        path.push_back(candidates[i]);
        dfs(i + 1, candidates, path, ans, target - candidates[i]);

        //not take
        
        //Now since we need to skip duplicates which sits adjacent
        //since this is the same recursion level, you need to
        //skip the duplicates until you get fresh one

        //why i + 1 < cand.size()?,as [1,1,1], at i = 2, you'll be
        //comparing it with i + 1 which is 3,i.e. out of bound
        while(i + 1 < candidates.size() && candidates[i] ==
        candidates[i + 1]){
            i = i + 1;
        }
        path.pop_back();
        dfs(i + 1, candidates, path, ans, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0, candidates, path, ans, target);
        return ans;
    }
};

//before backtracking : before dfs call its a same branch 
//Affter dfs call, the subsequent dfs(not take in our case) still at the same recursion level just it advances to next element while rejecting current one
