class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,bool> mp,vis;
        for( int num : nums ) mp[num] = true;

        for( int num : nums )
        {
            if( !vis[num] )
            {
                int res = 1;
                int i = num;
                //go till bottom
                while( mp[i-1] )
                {
                    res++;
                    vis[i] = true;
                    i--;
                }
                i = num;
                //go to top
                while( mp[i+1] )
                {
                    res++;
                    vis[i] = true;
                    i++;
                }
                ans = max(ans,res);
            }
        }

        return ans;

    }
};
