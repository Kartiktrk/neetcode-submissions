class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char,int> mp;
        int left = 0;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( mp.find(s[i]) != mp.end() )
            {
                left = max(left,mp[s[i]]+1);
            }
            mp[s[i]] = i;
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};
