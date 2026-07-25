class Solution {
public:
    bool isValid( unordered_map<char,int> mp, int l , int r, int k)
    {
        for( auto x : mp )
        {
            if( (r-l+1) - x.second <= k )
            {
                return true;
            }
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left = 0;
        int ans = 0;
        int maxf = 0;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            mp[s[i]]++;
            maxf = max(maxf,mp[s[i]]);
            while( i-left+1 - maxf > k )
            {
                mp[s[left]] = max( 0, mp[s[left]]-1 );
                left++;
            }
            ans = max( ans, i-left+1 );
        }
        return ans;
    }
};
