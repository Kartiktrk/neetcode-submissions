class Solution {
public:
    string minWindow(string s, string t) {
        if( t.size() > s.size() ) return "";
        unordered_map<char,int> mp,mp1;
        int left = -1;
        int matches = 0;
        vector<int> step;
        int next = 1;
        string ans = "";
        int len = 1e5;
        for( char s : t ) mp[s]++;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( mp.find(s[i]) != mp.end() )
            {
                mp1[s[i]]++;
                if( mp1[s[i]] == mp[s[i]] ) matches++;
                if( left == -1 ) left = i;
                step.push_back(i);
            }
            if( matches == mp.size() )
            {
                if( i-left+1 < len )
                {
                    ans = s.substr( left, i-left+1 );
                    len = i-left+1;
                }
                while( matches == mp.size() )
                {
                    mp1[s[left]] -= 1;
                    if( mp1[s[left]] < mp[s[left]] ) matches--;
                    if(next < step.size()){
                        left = step[next];
                        next++;
                        if( matches == mp.size() )
                        {
                            if( i-left+1 < len )
                            {
                                ans = s.substr( left, i-left+1 );
                                len = i-left+1;
                            }
                        }
                    }
                    else return ans;
                }
            }
        }
        return ans;
    }
};


// 
