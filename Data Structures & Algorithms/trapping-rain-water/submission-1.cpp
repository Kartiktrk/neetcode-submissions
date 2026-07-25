class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> lmax( height.size(), 0 ), rmax( height.size(), 0 );
        lmax[0] = height[0];
        for( int i = 1 ; i < height.size() ; i++ )
        {
            lmax[i] = max( lmax[i-1], height[i-1] );
        }

        rmax[height.size()-1] = height[height.size()-1];
        for( int i = height.size()-2 ; i >= 0 ; i-- )
        {
            rmax[i] = max( rmax[i+1], height[i+1] );
        }

        for( int i = 1 ; i < height.size()-1 ; i++ )
        {
            // cout << lmax[i] << " " << rmax[i] << " " << min(lmax[i],rmax[i]) - height[i] << "\n";
            ans += max(min(lmax[i],rmax[i]) - height[i],0);
        }

        return ans;
    }
};
