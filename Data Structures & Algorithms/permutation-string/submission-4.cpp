class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = s1.size()-1;
        if( s1.size() > s2.size() ) return false;
        vector<int> m1(26,0), m2(26,0);

        for( char s : s1 ) 
        {
            m1[s-'a'] ++;
        }

        for( int i = l ; i <= r ; i++ ) m2[s2[i]-'a']++;

        int matches = 0;

        for( int i = 0 ; i < 26 ; i++ )
        {
            if( m1[i] == m2[i] ) matches++;
        }

        if( matches == 26 ) return true;

        while( r < s2.size() )
        {
            m2[s2[l]-'a']--;
            if( m2[s2[l]-'a']+1 == m1[s2[l]-'a'] ) matches --;
            if( m2[s2[l]-'a'] == m1[s2[l]-'a'] ) matches ++;
            l++;
            r++;
            if(r < s2.size())
            { 
                m2[s2[r]-'a']++;
                if( m2[s2[r]-'a'] - 1 == m1[s2[r]-'a'] ) matches --;
                if( m2[s2[r]-'a'] == m1[s2[r]-'a'] ) matches ++;
            }
            if( matches == 26 ) return true;
        }
        return false;
    }
};
