class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = s1.size()-1;
        if( s1.size() > s2.size() ) return false;
        vector<int> m1(26,0), m2(26,0);

        for( char s : s1 ) 
        {
            // cout << s-'a' << "\n";
            m1[s-'a'] ++;
        }

        for( int i = l ; i <= r ; i++ ) m2[s2[i]-'a']++;

        if( m1 == m2 ) return true;

        while( r < s2.size() )
        {
            // cout << l << " " << r << "\n";
            m2[s2[l]-'a']--;
            l++;
            r++;
            if(r < s2.size()) m2[s2[r]-'a']++;
            if( m1 == m2 ) return true;
        }
        return false;
    }
};
