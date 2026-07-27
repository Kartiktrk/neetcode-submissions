class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for( int i = 0 ; i < k ; i++ )
        {
            while( !dq.empty() && dq.back() < nums[i] ) dq.pop_back();
            dq.push_back(nums[i]);
        }
        ans.push_back( dq.front() );
        int left = 0;
        for( int i = k ; i < nums.size() ; i++ )
        {
            //pop front
            if( dq.front() == nums[left] ) dq.pop_front();
            left++;

            //add new element
            while( !dq.empty() && dq.back() < nums[i] ) dq.pop_back();
            dq.push_back( nums[i] );
            ans.push_back( dq.front() );
        }
        return ans;
    }
};

// 2 3 4 5 6 7 8 9
// 
//
//
