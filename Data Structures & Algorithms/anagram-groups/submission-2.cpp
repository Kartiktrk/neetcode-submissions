class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        for(int i = 0 ; i < strs.size() ; i++){
            vector<int> identifier(26,-1);
            for(int j = 0 ; j < strs[i].size() ; j++){
                int index = strs[i][j] - '0' - 49;
                identifier[index] += 1;
            }
            mp[identifier].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto x : mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
