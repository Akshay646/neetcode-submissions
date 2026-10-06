
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // binary search on the smaller array
        if(n2 < n1){return findMedianSortedArrays(nums2, nums1);}

        // mid1 = how many I take from nums1 = where nums1 gets partitioned
        // partition can be at 0 (take none) up to n1 (take all)
        int low = 0, high = n1;
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0;

        // left half needs this many elements in total
        // (+1 so the left gets the extra one when total is odd)
        int reqInLeft = (n1 + n2 + 1) / 2;

        while(low <= high){
            // partition nums1 at mid1 -> I take mid1 elements from nums1
            int mid1 = (low + high) / 2;
            // partition nums2 at mid2 -> nums2 fills whatever the left half still needs
            int mid2 = reqInLeft - mid1;

            // partition at mid -> left of partition is mid - 1, right of partition is mid
            //
            //   nums1:  ... l1 = [mid1 - 1]  |  r1 = [mid1] ...
            //   nums2:  ... l2 = [mid2 - 1]  |  r2 = [mid2] ...
            //
            // partition at 0 -> nothing on the left -> INT_MIN
            // partition at n -> nothing on the right -> INT_MAX
            l1 = mid1 - 1 < 0 ? INT_MIN : nums1[mid1 - 1];
            r1 = mid1 >= n1 ? INT_MAX : nums1[mid1];
            l2 = mid2 - 1 < 0 ? INT_MIN : nums2[mid2 - 1];
            r2 = mid2 >= n2 ? INT_MAX : nums2[mid2];

            // each array is already sorted, so only the cross pairs need checking
            if(l1 <= r2 && l2 <= r1){
                // even: average of biggest on the left and smallest on the right
                if((n1 + n2) % 2 == 0){
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
                // odd: left has the extra element, and it's the biggest one there
                return (double)max(l1, l2);
            }
            else if(l1 > r2){
                // partition in nums1 is too far right -> move it left
                high = mid1 - 1;
            }
            else{
                // partition in nums1 is too far left -> move it right
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};