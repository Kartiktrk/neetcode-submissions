class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int needed_target=-nums[i];
            int start = i+1;
            int end = n-1;
            while(start < end){
                int found_target = nums[start]+nums[end];
                if(found_target == needed_target) {
                    ans.push_back({nums[i],nums[start],nums[end]});
                    while(start < end && nums[start] == nums[start+1]) start++;
                    while(start < end && nums[end] == nums[end-1]) end--;
                    start++;
                    end--;
                }
                else if(found_target < needed_target) start++;
                else end--;
            }
        }
        return ans;
    }
};
