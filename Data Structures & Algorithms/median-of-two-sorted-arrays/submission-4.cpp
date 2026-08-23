class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute force
        int m = nums1.size(), n = nums2.size();
        int n1 = 0, n2 = 0;
        int i = 0;
        vector<int> ans(m + n);

        //merge the array first: O(m + n)
        while(n1 < m && n2 < n){
            if(nums1[n1] > nums2[n2]){
                ans[i] = nums2[n2];
                n2++;
            }
            else{
                ans[i] = nums1[n1];
                n1++;
            }
            i++;
        }
        //add leftover elements
        while(n1 < m){
            ans[i] = nums1[n1];
            n1++;
            i++;
        }
         while(n2 < n){
            ans[i] = nums2[n2];
            n2++;
            i++;
        }

        //find median
        int mid = (m + n) / 2;
        double med = 0.0;
        if((m + n) % 2 != 0){
            med = (double)ans[mid];
        }
        else{
            med = (double) (ans[mid] + ans[mid - 1]) / 2;
        }
        return med;
    };
};
