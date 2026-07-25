class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int ans = 0;
        unordered_map <char,int> mp;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
            int maxfreq = 0;
            for(auto x : mp){
                maxfreq = max(maxfreq,x.second);
            }
            if((i-start+1-maxfreq) > k){
                while((i-start+1-maxfreq) > k){
                    mp[s[start]]--;
                    start++;
                    for(auto x : mp){
                        maxfreq = max(maxfreq,x.second);
                    }
                }
            }
            ans = max(ans , i-start+1);
        }
        return ans;
    }
};
