class Solution {
public:

    string encode(vector<string>& strs) {
        string enc_str="";
        for(string s : strs){
            string len = to_string(s.size());
            enc_str += len;
            enc_str += "#";
            enc_str += s;
        }
        cout << enc_str << "\n";
        return enc_str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int end = 0;
        for(int i = 0 ; i < s.size() ; ){
            if(s[i] == '#'){
                string ans="";
                int len = stoi(s.substr(end , i-end));
                int j = i+1;
                for( ; j < i+len+1 ; j++){
                    ans += s[j];
                }
                strs.push_back(ans);
                i = j;
                end = j;
            }
            else i++;
        }
        return strs;
    }
};
