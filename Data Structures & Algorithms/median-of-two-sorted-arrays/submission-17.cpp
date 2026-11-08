class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2){return findMedianSortedArrays(nums2, nums1);}
        int reqInLeft = (n1 + n2 + 1) / 2;
        int low = 0, high = n1;
        while(low <= high){
            int mid1 = (low + high) / 2;
            int mid2 = reqInLeft - mid1;

            //your mid1 is r1 because mid-1 elements willbe part of
            //your left part; visualise yourself
            int l1 = mid1 - 1 < 0 ? INT_MIN : nums1[mid1 - 1];
            int r1 = mid1 >= n1 ? INT_MAX : nums1[mid1];
            int l2 = mid2 - 1 < 0 ? INT_MIN : nums2[mid2 - 1];
            int r2 = mid2 >= n2 ? INT_MAX : nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                //check if even
                if((n1 + n2) % 2 == 0){
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
                //if odd
                else{
                    return max(l1, l2);
                    //why max of l1 nd l2, because we split array in
                    // n/2 + 1 | n/2 format
                }
            }
            else if(l1 > r2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
        }
        return 0.0;
    }   
};
