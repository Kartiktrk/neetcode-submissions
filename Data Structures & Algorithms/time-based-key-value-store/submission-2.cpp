class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back( {value, timestamp} );
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> &res = mp[key];
        int l = 0;
        int r = res.size()-1;
        string ans = "";
        while( l <= r )
        {
            int mid = l + (r-l)/2;

            if( res[mid].second > timestamp )
            {
                r = mid-1;
            }
            else
            {
                ans = res[mid].first;
                l = mid+1;
            }
        }
        return ans;
    }
};
