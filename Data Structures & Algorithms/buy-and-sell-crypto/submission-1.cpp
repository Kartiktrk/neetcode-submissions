class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minTillNow = 1e5;
        for( int price : prices )
        {
            ans = max(ans,price-minTillNow);
            minTillNow = min(price, minTillNow);
        }
        return ans;
    }
};
