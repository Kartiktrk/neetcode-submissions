class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod(nums.size(),1);
        for( int i = 1 ; i < nums.size() ; i++ )
        {
            prod[i] = prod[i-1]*nums[i-1];
        }
        int res = 1;
        for( int i = nums.size()-2 ; i >= 0 ; i-- )
        {
            res *= nums[i+1];
            prod[i] = prod[i]*res;
        }
        return prod;
    }
};
