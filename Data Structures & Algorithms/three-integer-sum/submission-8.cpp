class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        for( int i = 0 ; i < nums.size() ; )
        {
            int target = -nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while( l < r )
            {
                int res = nums[l]+nums[r];
                if( res == target ) 
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    //need to do more to avoid duplicates
                    int old_l = l;
                    l++;
                    while( l < nums.size() && nums[l] == nums[old_l] ) l++;
                }

                else if( res < target ) l++;
                else r--; 
            }
            int old_i = i;
            i++;
            while( i < nums.size() && nums[i] == nums[old_i] ) i++;
        }
        return ans;
    }
};

//[-1,0,1,2,-1,-4]
//[-4,-1,-1,0,1,2]
