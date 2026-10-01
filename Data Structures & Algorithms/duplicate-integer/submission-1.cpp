class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;
        for( int num : nums )
        {
            if(st.count(num) > 0) return true;
            st.insert(num);
        }
        return false;
    }
};