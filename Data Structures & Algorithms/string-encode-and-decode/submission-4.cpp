class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string str : strs)
        {
            encoded = encoded + to_string(str.size()) + "#" + str;
        }
        cout << encoded << "\n";
        return encoded;
    }

    vector<string> decode(string s) {
        int len = s.size();
        int i = 0;
        vector<string> ans;
        while( i < len)
        {
            int j = i;
            while( s[j] != '#' ) j++;
            cout << i << " " << j-i+1 << "\n";
            int stlen = stoi(s.substr(i,j-i+1));
            i+=j-i+1;
            if(i < len) ans.push_back(s.substr(i,stlen));
            else ans.push_back("");
            i += stlen;
        }
        return ans;
    }
};
