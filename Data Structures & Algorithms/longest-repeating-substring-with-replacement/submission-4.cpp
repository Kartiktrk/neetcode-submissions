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
        for( int i = 0 ; i < s.size() ; i++ )
        {
            mp[s[i]]++;
            if( isValid( mp, left, i , k ) ) ans = max( ans, i-left+1 );
            else
            {
                while( !isValid( mp, left, i, k ) )
                {
                    mp[s[left]] = max( 0, mp[s[left]]-1 );
                    left++;
                }
            }
        }
        return ans;
    }
};
