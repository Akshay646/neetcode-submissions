class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = 0, stRow = -1;
        int cols = matrix[0].size() - 1;
        //Find row under which the target lies
        for(r = 0; r < matrix.size(); r++){
           if(target >= matrix[r][0] && target <= matrix[r][cols]){
                stRow = r;
                break;
            }
        }
        if(stRow == -1)return false;
        int l = 0, h = matrix[0].size() - 1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(matrix[stRow][mid] == target){
                return true;
            }
            else if(matrix[stRow][mid] < target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return false;
    }
};
