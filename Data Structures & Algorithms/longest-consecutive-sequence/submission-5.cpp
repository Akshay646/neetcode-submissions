class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //2,3,5,100,4,200
        unordered_set<int> hashset(nums.begin(), nums.end());
        int longSeq = 0;
        for(int i: hashset)
        {
            int localLongSeq = 1;
            //finding the start element
            if(!hashset.count(i - 1))
            {
                int j = i + 1;
                //checking every consecutive element if it appears in set
                while(hashset.count(j))
                {
                    j++;localLongSeq++;
                }
                //updating the gloab maz length
                longSeq = max(longSeq, localLongSeq);
            }
        }

        return longSeq;
    }
};
