class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        map<char,int> mp1, mp2;
        for(int i = 0 ; i < s1.size() ; i++) mp1[s1[i]]++;
        for(int i = 0 ; i < s1.size() ; i++) mp2[s2[i]]++;
        int start = 0;
        if(mp1 == mp2) return true;
        for(int i = s1.size() ; i < s2.size() ; i++){
            mp2[s2[i]]++;
            mp2[s2[start]]--;
            if(mp2[s2[start]] == 0) mp2.erase(s2[start]);
            start++;
            if(mp1 == mp2) return true;
        }
        return false;
    }
};
