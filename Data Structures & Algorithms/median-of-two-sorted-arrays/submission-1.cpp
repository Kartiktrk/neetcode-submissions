class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if( sz1 > sz2 ) return findMedianSortedArrays(nums2,nums1);

        int l = 0;
        int r = sz1;
        int half = (sz1+sz2+1)/2;

        while( l <= r )
        {
            int mid1 = (l+r) >> 1 ;
            int mid2 = half-mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if( mid1-1 >= 0 ) l1 = nums1[mid1-1];
            if( mid2-1 >= 0 ) l2 = nums2[mid2-1];
            if( mid1 < sz1 ) r1 = nums1[mid1];
            if( mid2 < sz2 ) r2 = nums2[mid2];
            if( l1 <= r2 && l2 <= r1 )
            {
                if( (sz1+sz2)%2 == 0 ) return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
                else return max(l1,l2);
            }
            else if( l2 > r1 ) l = mid1+1;
            else r = mid1-1;
        }
        return 0.0;
    }
};

// 1 2 3 4 | 5 6 6
// 1 | 2 3 4 
// 1 2
// 
//     1 | 2
//     3 | 4
