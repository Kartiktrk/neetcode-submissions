class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            if( i>0 && nums[i] == nums[i-1] ) continue;
            int target = -nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while( l < r )
            {
                // cout << target << " " << nums[l]+nums[r] << "\n";
                if( nums[l]+nums[r] > target ) 
                {
                    r--;
                }
                else if( nums[l]+nums[r] < target )
                {
                    l++;
                    // int old_l = l;
                    // while( l < r && nums[old_l] == nums[l] ) l++;
                }
                else
                {
                    ans.push_back({nums[l],nums[r],nums[i]});
                    int old_l = l;
                    while( l < r && nums[old_l] == nums[l] ) l++;
                }
            }
        }
        return ans;
    }
};
