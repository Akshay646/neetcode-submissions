class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        int n = numbers.size();

        while(start < end)
        {
            int currentSum = numbers[start] + numbers[end];
            if(currentSum == target){return {start + 1, end + 1};}

            if(currentSum > target)
            {
                end -= 1;
            }
            else
            {
                start += 1;
            }
        }

        return {};
    }
};
