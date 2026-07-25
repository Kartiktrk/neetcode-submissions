class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n = nums.size();
        vector<int> ans(2,-1);
        for(int i = 0 ; i < n ; i++){
            if(mp.find(target-nums[i]) != mp.end()){
                ans[0] = mp[target-nums[i]];
                ans[1] = i;
                break;
            }
            else mp[nums[i]] = i;
        }
        return ans;
    }
};
