class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for( string str : strs )
        {
            encode += "#"+to_string(str.size())+"#"+str;
        }
        return encode;
    }

    vector<string> decode(string s) {
        // cout << s << "\n";
        vector<string> ans;
        int ptr = 0;
        while( ptr < s.size() )
        {
            if(s[ptr] == '#')
            {
                ptr++;
                int len = 0;
                while( s[ptr] != '#' )
                {
                    len = len*10 + (s[ptr]-'0');
                    ptr++;
                }
                ptr++;
                // cout << len << "\n";
                ans.push_back( s.substr(ptr, len) );
                ptr += len;
            }
            else break;
        }
        return ans;
    }
};

// 3qwe5rfvbg1w5tyuio