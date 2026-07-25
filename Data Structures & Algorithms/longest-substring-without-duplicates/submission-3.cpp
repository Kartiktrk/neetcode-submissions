class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int start = 1 , end = 1;
        int ans = 0;
        while(end-1 < s.length()){
            if(mp[s[end-1]]){
                for(int i = start-1 ; i < mp[s[end-1]]-1 ; i++){
                    mp[s[i]] = 0;
                }
                start = mp[s[end-1]]+1;
            }
            ans = max(ans , end-start+1);
            mp[s[end-1]] = end;
            end++;
        }
        return ans;
    }
};
