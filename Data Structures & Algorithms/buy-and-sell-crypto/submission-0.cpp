class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Simple greedy approach
        //Pick always minimum locally(i.e. for each i)
        //Whenever you get higher than the minimum so far,
        //Just keep storing the profit = currentElement - minSoFar
        //profit = currentElement - minSoFar only works if current element
        // at index i is greater than minSoFar. if such conndition never happens
        //you will never be able to make profit, i.e. choose any stock
        
        int maxProfit = 0, minSoFar = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] > minSoFar)
            {
                maxProfit = max(maxProfit, prices[i] - minSoFar);
            }
            else
            {
                minSoFar = prices[i];
            }
        }

        return maxProfit;

    }
};
