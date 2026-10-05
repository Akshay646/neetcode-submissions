class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();

        // binary search on the smaller one, so flip if needed
        if(n1 > n2){return findMedianSortedArrays(nums2, nums1);}

        int total = n1 + n2;
        // left half gets one extra when total is odd, so the median lands on the left
        int reqInFirstHalf = (total + 1) / 2;

        // mid1 = how many I take from nums1, anywhere from none to all of it
        int low = 0, high = n1;
        while(low <= high){
            int mid1 = (low + high) / 2;
            // once I pick from nums1, nums2 has to fill the rest of the left half
            int mid2 = reqInFirstHalf - mid1;

            // the four numbers sitting right at the cut
            // nothing on a side? use INT_MIN / INT_MAX so it never fails the check
            l1 = mid1 - 1 >= 0 ? nums1[mid1 - 1] : INT_MIN;
            r1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            l2 = mid2 - 1 >= 0 ? nums2[mid2 - 1] : INT_MIN;
            r2 = mid2 < n2 ? nums2[mid2] : INT_MAX;

            // each array is sorted already, so just check across them
            if(l1 <= r2 && l2 <= r1){
                // even: median is between the biggest on the left and smallest on the right
                if(total % 2 == 0){
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
                // odd: left has the extra one, and it's the biggest thing there
                return (double)max(l1, l2);
            }
            else if(l1 > r2){
                // nums1 gave something too big for the left, take fewer from it
                high = mid1 - 1;
            }
            else{
                // nums2 gave something too big for the left, take more from nums1
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};