class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> freq;
        for(int i : nums)
        {
            freq[i]++;
            if(freq[i] > 1){return true;}
        }
        return false;
    }
};