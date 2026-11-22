class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        int n = nums.size();
        while( l <= r )
        {
            int mid = l + (r-l)/2;
            if( nums[mid] > nums[n-1] )
            {
                l = mid+1;
            }
            else
            {
                if( mid-1 >= 0 && nums[mid-1] > nums[mid] ) return nums[mid];
                else
                {
                    r = mid-1;
                }
            }
        }
        return nums[l];
    }
};
