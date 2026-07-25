class Solution {
public:
    bool possible(vector<int> &nums , int target){
        int l = 0;
        int r = (int)nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return true;
            else if(nums[mid] < target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = (int)matrix.size()-1;
        int m = matrix[0].size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(matrix[mid][0] <= target && matrix[mid][m] >= target){
                return possible(matrix[mid],target);
            }
            else if(matrix[mid][0] <= target) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};
