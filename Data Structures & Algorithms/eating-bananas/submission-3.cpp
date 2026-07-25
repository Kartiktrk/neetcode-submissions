class Solution {
public:
    bool canEat(int k , int h, vector<int>& piles){
        long long int actualH = 0;
        if(k == 0) return false;
        for(int i = 0 ; i < piles.size() ; i++){
            actualH += ceil((double)piles[i]/(double)k); 
        }
        return (actualH <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        unsigned long long int sum = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            sum = max(sum , (unsigned long long)piles[i]);
        }
        unsigned long long int l = 1;
        unsigned long long int r = sum;
        while(l <= r){
            int mid = (r-l)/2 +l;
            if(canEat(mid,h,piles)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
