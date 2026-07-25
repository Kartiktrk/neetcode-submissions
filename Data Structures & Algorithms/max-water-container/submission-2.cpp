class Solution {
public:
    int maxArea(vector<int>& heights) {
         int l = 0;
         int r = heights.size()-1;
         int ans = 0;
         while( l < r )
         {
            int base = (r-l);
            int height = min(heights[l],heights[r]);
            int area = base*height;
            ans = max(ans,area);
            if( heights[l] <= heights[r] ) l++;
            else r--;
         }
         return ans;
    }
};
