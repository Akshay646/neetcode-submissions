class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        //1.Search space
        int st = 0, en = m * n - 1;
        while(st <= en){
            int mid = st + (en - st) / 2; // ind
            //2.Get the actual coordinates
            int r = mid / n; //tells which row you're in
            int c = mid % n; //tells in that row, which col you're in
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] > target){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        return false;
    }
};
