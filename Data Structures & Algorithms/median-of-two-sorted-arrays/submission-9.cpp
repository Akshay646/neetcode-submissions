class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int l1 = 0, l2 = 0;
        int medInd = (n1 + n2) / 2;
        int counter = 0;
        int prev = 0, curr = 0;
        while(l1 < n1 && l2 < n2 && counter <= medInd){
            prev = curr;
            if(nums1[l1] < nums2[l2]){
                curr = nums1[l1];
                l1++;
            }
            else{
                curr = nums2[l2];
                l2++;
            }

           counter++;
        }

        //now one of the array might got out of bound even before reaching medInd
        //e.g [1,2] [3, 4]

        //if nums1 still has elements
        while(l1 < n1 && counter <= medInd){
            prev = curr;
            curr = nums1[l1];
            l1++;
            counter++;
        }
        //if nums2 still has elements
        while(l2 < n2 && counter <= medInd){
            prev = curr;
            curr = nums2[l2];
            l2++;
            counter++;
        }

        if((n1 + n2) % 2 != 0){
            return (double)curr;
        }

        return (double)(prev + curr) / 2;
    };
};
