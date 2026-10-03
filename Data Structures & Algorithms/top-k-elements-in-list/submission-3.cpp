class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ans;
        int cnt = 0;
        for( int num : nums )
        {
            mp[num]++;
        }
        vector<vector<int>> freq(nums.size()+1, vector<int>());
        for( auto x : mp )
        {
            freq[x.second].push_back(x.first);
        }
        for( int i = nums.size() ; i >= 0 ; i-- )
        {
            if(freq[i].size() != 0)
            {
                for( int l : freq[i] )
                {
                    // cout << i << " " << l << "\n";
                    ans.push_back(l);
                    cnt++;
                    if(cnt == k) return ans;
                }
            }
        }
        return ans;
    }
};
