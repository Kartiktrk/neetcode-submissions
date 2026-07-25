class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i++){
            int needed_target = -nums[i];
            int start = i+1;
            int end = n-1;
            while(start < end){
                int found_target = nums[start]+nums[end];
                if(found_target == needed_target) {
                    s.insert({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                }
                else if(found_target < needed_target) start++;
                else end--;
            }
        }
        vector<vector<int>> ans;
        for(vector<int> q : s) ans.push_back(q);
        return ans;
    }
};
