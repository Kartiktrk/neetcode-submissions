class Solution {
public:

    void dfs( int i, vector<vector<int>> &adj, vector<bool> &vis )
    {
        vis[i] = true;
        for( int v : adj[i] )
        {
            if( !vis[v] ) dfs( v , adj, vis );
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj( n );
        vector<bool> vis( n , false );
        for( vector<int> edge : edges )
        {
            adj[edge[0]].push_back( edge[1] );
            adj[edge[1]].push_back( edge[0] );
        }
        int ans = 0;

        for( int i = 0 ; i < n ; i++ )
        {
            if( !vis[i] ) 
            {
                dfs( i , adj, vis );
                ans++;
            }
        }

        return ans;

    }
};
