class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size()+1);
        unordered_map<int,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(const auto &x : mp){
            freq[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i = freq.size()-1 ; i >= 0 ; i--){
            for(auto x : freq[i]){
                ans.push_back(x);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
