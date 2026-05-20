class Solution {
public:
    bool canFinishInLessThanH(int k, vector<int>& piles, int h){
        int hours = 0;

        for(int pile : piles){
            hours += ceil((double)pile/k);
        }

        //why? => we always keep checking if we can finish it within h hours
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1, en = *max_element(piles.begin(), piles.end());
        int minSpeed = en;
        while(st <= en){
            int mid = st + (en - st) / 2;
            //check if this mid actually gives lesser time than h
            if(canFinishInLessThanH(mid, piles, h)){
                //mid is still optimal, narrow search by end
                en = mid - 1;
                minSpeed = min(minSpeed, mid);
            }
            else{
                //if canFinish(mid) == false, 
                /*That means:
                mid is too small and exceeding total hours
                All values ≤ mid are also false (monotonic property)
                So we eliminate left side:
                st = mid + 1
                Because mid can never be the answer.*/
                st = mid + 1;
            }
        }

        return minSpeed;
    }
};
