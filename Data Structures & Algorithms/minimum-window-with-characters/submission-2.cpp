class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if( m < n ) return "";
        unordered_map<char,int> mps, mpt;
        for( char ch : t ) mpt[ch]++;

        int matches = 0;
        int ans = INT_MAX;
        string anstr = "";

        int l = 0;

        for( int i = 0 ; i < m ; i++ )
        {
            mps[s[i]] ++;
            if( mpt[s[i]] != 0 && mpt[s[i]] >= mps[s[i]])
            {
                matches++;
            }
            if( matches == t.size() )
            {
                if( ans > (i-l+1) )
                {
                    ans = i-l+1;
                    anstr = s.substr( l, i-l+1 );
                }
                while( l <= i && matches == t.size() )
                {
                    mps[s[l]]--;
                    if( mpt[s[l]] != 0 && mps[s[l]]+1 == mpt[s[l]] )
                    {
                        mps[s[l]]++;
                        if( ans > i-l+1 )
                        {
                            ans = i-l+1;
                            anstr = s.substr( l , i-l+1 );
                        }
                        break;
                    }
                    else l++;
                }
            }
        }
        cout << ans << "\n";
        return anstr;
    }
};
