class Solution {
public:
    int GetHoursWithK(vector<int>& piles, int k){
        int totalHrs = 0;

        for(int p : piles){
            totalHrs += ceil((double)p / k);
        }

        return totalHrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        
        while(l < r){
            int k = (l + r) / 2;
            int curHrs = GetHoursWithK(piles, k);
            if(curHrs <= h){
                // k is valid, so keep it in the search space since it could be the
                // /minimum speed
                r = k;
            }
            else{
                // k is too slow, so discard k and all smaller speeds
                l = k + 1;
            }
        }
        return r;
    }
};
