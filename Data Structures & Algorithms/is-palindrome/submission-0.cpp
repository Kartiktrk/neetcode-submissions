class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;
        while(start <= end){
            if(!isalnum(s[start])) start ++;
            else if(!isalnum(s[end])) end--;
            else{
                char c1=s[start],c2=s[end];
                if(s[start] >= 'A' && s[start] <= 'Z') c1 = tolower(c1);
                if(s[end] >= 'A' && s[end] <= 'Z') c2 = tolower(c2);
                if(c1 != c2) return false;
                start++;
                end--;
            }
        }
        return true;
    }
};
