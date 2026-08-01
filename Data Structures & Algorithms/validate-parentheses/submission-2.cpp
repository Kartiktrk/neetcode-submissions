class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for( char ch : s )
        {
            if( ch == '(' || ch == '{' || ch == '[' )
            {
                st.push(ch);
            }
            else
            {
                if( !st.empty() )
                {
                    if( ch == ')' && st.top() != '(' ) return false;
                    if( ch == ']' && st.top() != '[' ) return false;
                    if( ch == '}' && st.top() != '{' ) return false;
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty() ? true : false;
    }
};
