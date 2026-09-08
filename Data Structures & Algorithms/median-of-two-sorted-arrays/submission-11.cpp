class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2){return findMedianSortedArrays(nums2, nums1);}
        int total = n1 + n2;
        int reqInFirstHalf = (total + 1) / 2;

        int low = 0, high = n1; //since n1 is small based on recursion
        while(low <= high){
            //make partition and check if its valid
            int partition = (low + high) / 2;
            //helps determine second halfs boundaries- l2, r2
            int req = reqInFirstHalf - partition;

            //calculate boundaries:
            //l1/l2 represents 1st half, it can go -v;Default:INT_MAX
            //r1/r2 represents 2nd half, it can go > n;Default:INT_MIN
            //When the left side is empty, they must never block the
            //l1 <= r2 check, so they should be INT_MIN. Same logic in
            //reverse for r1/r2 → INT_MAX.
            l1 = partition - 1 >= 0 ? nums1[partition - 1] : INT_MIN;
            r1 = partition < n1 ? nums1[partition] : INT_MAX;
            l2 = req - 1 >= 0 ? nums2[req - 1] : INT_MIN;
            r2 = req < n2 ? nums2[req] : INT_MAX;

            //if valid bounbdaries
            if(l1 <= r2 && l2 <= r1){
                //if odd length
                if(total % 2 == 0){
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                }
                //when total is odd
                //since our totalsArr1 is (n1+n2)/2
                return (double)max(l1, l2);
            }
            else if(l1 > r2){
                //since, you have included more elements in first half 
                //than required
                high = partition - 1;
            }
            else{
                low = partition + 1;
            }
        }
        return 0.0;
    }
};
