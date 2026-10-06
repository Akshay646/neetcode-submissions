class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2 < n1){return findMedianSortedArrays(nums2, nums1);}
        
        int low = 0, high = n1;
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0;

        int reqInLeft = (n1 + n2 + 1) / 2;

        while(low <= high){
            //get mid1 which decides l1 & r1
            int mid1 = (low + high) / 2;
            //get mid2 which decides l2 & r2
            int mid2 = reqInLeft - mid1;

            //Set l1 and r1 - derived from nums1
            l1 = mid1 - 1 < 0 ? INT_MIN : nums1[mid1 - 1];
            r1 = mid1 >= n1 ? INT_MAX : nums1[mid1];
            l2 = mid2 - 1 < 0 ? INT_MIN : nums2[mid2 - 1];
            r2 = mid2 >= n2 ? INT_MAX : nums2[mid2];

            //now check if we have got valid partition
            if(l1 <= r2 && l2 <= r1){
                if((n1 + n2) % 2 == 0){
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
                return (double)max(l1, l2);
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