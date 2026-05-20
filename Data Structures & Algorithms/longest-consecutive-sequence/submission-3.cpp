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
                while(hashset.count(j))
                {
                    j++;localLongSeq++;
                }

                longSeq = max(longSeq, localLongSeq);
            }
        }

        return longSeq;
    }
};
