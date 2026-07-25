class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefprod[nums.size()];
        int sufprod[nums.size()];
        vector<int> ansprod(nums.size());
        prefprod[0] = nums[0];
        sufprod[nums.size()-1] = nums[nums.size()-1];
        for(int i = 1 ; i < nums.size() ; i++){
            prefprod[i] = prefprod[i-1]*nums[i];
        }
        for(int i = nums.size()-2 ; i >= 0 ; i--){
            sufprod[i] = sufprod[i+1]*nums[i];
        }
        for(int i = 0 ; i < nums.size() ; i++){
            ansprod[i] = 1;
            if(i-1 >= 0) ansprod[i] *= prefprod[i-1];
            if(i+1 < nums.size()) ansprod[i] *= sufprod[i+1];
        }
        return ansprod;
    }
};
