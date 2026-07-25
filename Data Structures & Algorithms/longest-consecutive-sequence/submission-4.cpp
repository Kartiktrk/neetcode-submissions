class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        vector<bool> checked(nums.size(),true);
        for(int i = 0 ; i < nums.size() ; i++) mp[nums[i]]=i;
        for(int i = 0 ; i < nums.size() ; i++){
            if(checked[i]){
                int len1 = 0;
                int len2 = 0;
                int start = nums[i];
                int end = nums[i];
                checked[mp[start]] = false;

                while(mp.find(start+1) != mp.end() && checked[mp[start+1]]){
                    checked[mp[start+1]] = false;
                    start  += 1;
                    len1++;
                }
                cout << len1 << "\n";
                while(mp.find(end-1) != mp.end() && checked[mp[end-1]]){
                    checked[mp[end-1]] = false;
                    end -= 1;
                    len2++;
                }

                ans = max(ans , len1+len2+1);
            }
        }
        return ans;
    }
};
