class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,bool> mp;
        for( int num : nums ) mp[num] = true;

        for( int num : nums )
        {
            if( !mp[num-1] )
            {
                int res = 1;
                int i = num;
                //go to top
                while( mp[i+1] )
                {
                    res++;
                    i++;
                }
                ans = max(ans,res);
            }
        }

        return ans;

    }
};
