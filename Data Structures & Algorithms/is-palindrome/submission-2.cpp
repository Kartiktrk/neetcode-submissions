class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while( l < r )
        {
            // cout << s[l] << " " << s[r] << "\n";
            if( isalnum(s[l]) && isalnum(s[r]) && tolower(s[l]) == tolower(s[r]) )
            {
                l++;
                r--;
            }
            else if( l < r && !isalnum(s[l]) ) l++;
            else if( r >= 0 && !isalnum(s[r]) ) r--;
            else return false;
        }
        return true;
    }
};
