class Solution {
public:
    int getMax( map<char,int> &mp )
    {
        int maxi = 0;
        for( auto x : mp ) maxi = max(maxi,x.second);
        return maxi;
    }
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int left = 0;
        int ans = 0;
        int getmax = 0;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            mp[s[i]]++;
            getmax = max(mp[s[i]],getmax);
            int req = (i-left+1) - getmax;
            if( req > k )
            {
                while( i-left+1 - getmax > k )
                {
                    mp[s[left]] = max(mp[s[left]]-1,0);
                    left++;
                }
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};
