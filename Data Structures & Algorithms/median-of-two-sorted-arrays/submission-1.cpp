class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        //1. Hypothetical partitioning of combined array(nums1 & nums2)
        //------(m + n + 1)/2-------|-------------------------
        //      (left partition)           (right partition)
        //+1 is for consistent format works for both Odd and even sizes for partitioning
        //as well as calculating medians

        //We always apply BS on smaller array. If not, lets say n1 = 100
        //n2 = 2, leftPart = 51, but n2 only has 2 elements, here we may need extra
        //boundary check, gets messy.

        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }

        //we need to know the left partition total element counts which needs to decide
        //number of elements needed from nums2
        int leftPartition = (n1 + n2 + 1) / 2;
        int n = n1 + n2;
//Step 1: Due to above swap, n1 defaults to smaller array
        int low = 0, high = n1;
        while(low <= high){
            //find mid1 & mid2 for our formula variables
            int mid1 = low + (high - low) / 2;
            int mid2 = leftPartition - mid1; //(total elements from nums2)

            //Default are based on their part(left/right for safer accurate comparisions)
            int L1 = INT_MIN, L2 = INT_MIN;
            int R1 = INT_MAX, R2 = INT_MAX;

//Step 2:Boundary conditions
            //now if we have valid  middles, then only assign else, they already are set to default
            //1.Check boundary for mid1 if it crosses n1 for nums1
            if(mid1 < n1) R1 = nums1[mid1];
            //2.Check boundary for mid2 if it crosses n2 for nums2
            if(mid2 < n2) R2 = nums2[mid2];
            //3. Check boundary for mid1 if it goes below or to 0 for nums1
            if(mid1 - 1 >= 0) L1 = nums1[mid1 - 1];
            //3. Check boundary for mid2 if it goes below or to 0 for nums2
            if(mid2 - 1 >= 0) L2 = nums2[mid2 - 1];

//Step 2: Now check BS conditions for both even and odd sizes
            if(L1 <= R2 && L2 <= R1){//found simmetry
                if(n % 2 == 0){
                    return (double)(max(L1, L2) + min(R1, R2)) / 2.0;
                }
                else{
                    return (double)max(L1, L2);
                }
            }
            else if(L1 > R2){
            //mid1? bcoz, we are applying BS on nums1, and mid1 represent mid of nums1
                high =  mid1 - 1; 
            }
            else{
                low = mid1 + 1;
            }
        }

        return 0;
    }
};
