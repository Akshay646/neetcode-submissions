class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //1. Always maintain minimum along the way
        //2. Only replace min when you get min than store min
        //you only compute diff when yout get value > stored min
        //as that will only give you actual profit
        int minSoFar = INT_MAX;
        int mxProfit = INT_MIN;

        for(int price : prices){
            if(price < minSoFar){
                minSoFar = price;
            }

            if(price >= minSoFar){
                mxProfit = max(mxProfit, price - minSoFar);
            }
        }
        return mxProfit;
    }
};
