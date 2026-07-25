class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> mp;
        for(int i = 0 ; i < nums.size() ; i++) mp.insert(nums[i]);
        return !((int)mp.size() == (int)nums.size());
    }
};
