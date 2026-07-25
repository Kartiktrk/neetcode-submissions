class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int start = 0 , end = 0;
        int ans = 0;
        while(end < s.length()){
            if(mp.find(s[end]) != mp.end()){
                start = max(mp[s[end]]+1,start);
            }
            mp[s[end]] = end;
            ans = max(ans , end-start+1);
            end++;
        }
        return ans;
    }
};
