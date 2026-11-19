class Solution {
public:
    bool ok( vector<int> &piles, int h, int k )
    {
        uint64_t actual_h = 0;
        for( int pile : piles )
        {
            actual_h += pile/k;
            if( pile%k != 0 ) actual_h += 1;
        }
        return actual_h <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element( piles.begin(), piles.end() );
        int ans = 0;
        while( left <= right )
        {
            int mid = left + (right-left)/2;
            if( ok(piles,h,mid) )
            {
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }
        return ans;
    }
};
