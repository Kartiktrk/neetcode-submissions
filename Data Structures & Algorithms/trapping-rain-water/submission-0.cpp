class Solution {
public:
    int trap(vector<int>& nums) {
        int pref_height[nums.size()-1] , suff_height[nums.size()-1];
        int maxheight = INT_MIN;
        int water_trapped = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(maxheight < nums[i]) {
                maxheight = nums[i];
                pref_height[i] = 0;
            }
            else{
                pref_height[i] = maxheight - nums[i];
            }
        }
        maxheight = 0;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            if(maxheight < nums[i]) {
                maxheight = nums[i];
                suff_height[i] = 0;
            }
            else{
                suff_height[i] = maxheight - nums[i];
            }
        }

        for(int i = 0 ; i < nums.size() ; i++){
            water_trapped += min(suff_height[i] , pref_height[i]);
        }

        return water_trapped;

    }
};


/*

pref = [0 , 0 , 2 , 0 , 2 , 3 , 2 , 0 , 1 , 2]
suff = [3 , 1 , 3 , 0 , 2 , 3 , 2 , 0 , 0 , 0]
min  = [0 , 0 , 2 , 0 , 2 , 3 , 2 , 0 , 0 , 0]

*/