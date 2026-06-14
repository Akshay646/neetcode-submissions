class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //0,1,1,2
        //edge case to cover wrong return of lConsec
        if(nums.size() == 0){return 0;}
        int lConsec = 1;
        unordered_set<int> st(nums.begin(), nums.end());

        for(int num : st){
            int count = 1;
            int curr = num;
            //if predecessor of num exist in the set,its not a starting point
            //you can skip until you find starting point
            if(st.find(num - 1) != st.end()){
                continue;
            }

            //This will only execute when u get starting point
            //keep finding its next element in set
            while(st.find(curr + 1) != st.end()){
                count++;
                curr++;
            }

            //Now at here, you must have got a valid longest sequence
            lConsec = max(lConsec, count);
        }
        return lConsec;
    }
};