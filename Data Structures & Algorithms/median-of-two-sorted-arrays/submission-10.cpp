class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        if(n1 > n2){return findMedianSortedArrays(nums2, nums1);}

        //since we swapped the above, if n1 > n2, means n2 is smaller, and we swapped it
        //so, now n1 will be smaller in recursion, and high = n1.size() works as its
        //min array
        int low = 0, high = n1;
        int l1 = 0, r1 = 0;
        int l2 = 0, r2 = 0;

        int total = n1 + n2;
        // We want req elements on the left side of the partition.
        // req = total/2 + 1 ensures max(l1,l2) gives the median for odd
        // and gives the larger of the two middle elements for even.
        int req = (total + 1) / 2;
        
        //now apply binary search
        while(low <= high){
            //get the partition
            int partition = (low + high) / 2;

            //find the partition boundaries for both of the arrays
            //visualise partition on notebbok
            
            // Since we find max(l1, l2) & min(r1, r2),
            // avoid out-of-bound access using sentinels.
            //
            // l1 is a left-side maximum candidate → if nonexistent, use INT_MIN
            // r1 is a right-side minimum candidate → if nonexistent, use INT_MAX

            l1 = partition - 1 < 0 ? INT_MIN : nums1[partition - 1];
            r1 = partition >= n1 ? INT_MAX : nums1[partition];

            // For nums2:
            // l2 is a left-side maximum candidate → if nonexistent, use INT_MIN
            // r2 is a right-side minimum candidate → if nonexistent, use INT_MAX

            l2 = (req - partition - 1) < 0
                    ? INT_MIN
                    : nums2[req - partition - 1];

            r2 = req - partition >= n2
                    ? INT_MAX
                    : nums2[req - partition];

            //now chekc if we found the valid partition
            //left portion boundaries(l1,l2) elements should be <= right portion
            //boundaries(r1,r2)
            //Also, if l1th element > r2th or l2th element > r1, its invalid as left
            //arrays still contains greater element.
            if(l1 > r2){
                high = partition - 1;
            }
            else if( l2 > r1){
                low = partition + 1;
            }
            else{
                //now check if total is odd
                if(total % 2 != 0){
                    return (double)max(l1, l2);
                }
                else{
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
        }
        return 0.0;
    };
};
