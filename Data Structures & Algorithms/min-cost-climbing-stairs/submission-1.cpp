class Solution {
public:
    int dfs(int i, vector<int>& cost, vector<int>& dp){

        // If we've reached or crossed the top, no more cost is needed.
        if(i >= cost.size()) return 0;
        if(dp[i] != -1)return dp[i];

        // Pay the cost at the current step and climb 1 step.
        int takeOne = cost[i] + dfs(i + 1, cost, dp);

        // Pay the cost at the current step and climb 2 steps.
        int takeTwo = cost[i] + dfs(i + 2, cost, dp);

        // Explore both choices and return the cheaper one.
        return dp[i] = min(takeOne, takeTwo);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        // We are allowed to start from either step 0 or step 1.
        vector<int> dp(cost.size(), -1);
        return min(dfs(0, cost, dp), dfs(1, cost, dp));
    }
};