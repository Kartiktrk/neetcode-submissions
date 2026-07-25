class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ansprod(nums.size());
        ansprod[0] = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            ansprod[i] = ansprod[i-1]*nums[i-1];
        }
        int postfix = 1;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            ansprod[i] *= postfix;
            postfix *= nums[i];
        }
        return ansprod;
    }
};
