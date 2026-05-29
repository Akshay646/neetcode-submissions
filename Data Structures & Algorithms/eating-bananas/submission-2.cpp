class Solution {
public:
    bool canEatAll(vector<int>& piles, int k, int h){
        int totalHours = 0;
        for(int pile : piles){
            totalHours += ceil((double)pile/k);
        }

        return totalHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int n = piles.size();

        //the max bound for BS is max element from piles as that is 
        //the max times koko can finish all the bananas for sure
        int r = *max_element(piles.begin(), piles.end());

        while(l < r){
            int mid = (l + r) / 2;
            if(canEatAll(piles, mid, h)){
                //why r = mid not not mid - 1
                //u can do it, but since we store answer directly, we can use
                //mid again as right boundary
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};
