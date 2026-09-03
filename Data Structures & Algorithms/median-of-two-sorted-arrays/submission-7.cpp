class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans(n1 + n2); //S.C=> O(m + n)
        int i = 0;
        while(p1 < n1 && p2 < n2){
            if(nums1[p1] < nums2[p2]){
                ans[i] = nums1[p1];
                p1++;
            }
            else{
                ans[i] = nums2[p2];
                p2++;
            }
            i++;
        }  

        //if any of the arrays has still left with elements due to early index out of bound
        //if nums1
        while(p1 < n1){
            ans[i] = nums1[p1];
            p1++;
            i++;
        }
        //if nums2
         while(p2 < n2){
            ans[i] = nums2[p2];
            p2++;
            i++;
        }
        for(int i : ans){
            cout << i << ", ";
        }
        //find the median
        int mid = ans.size() / 2;
        if(ans.size() % 2 == 0){
            return (double)(ans[mid] + ans[mid - 1]) / 2;
        }
        
        return (double)ans[mid];
    };
};
