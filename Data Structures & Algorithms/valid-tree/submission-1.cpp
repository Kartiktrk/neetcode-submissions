class Solution {
public:

    bool bfs( int i, int n , vector<vector<int>> &adj, vector<bool> &vis )
    {
        vis[i] = true;
        queue<pair<int,int>> q;
        q.push( { i , -1 } );
        while( !q.empty() )
        {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            for( int v : adj[curr] )
            {
                if( !vis[v] )
                {
                    vis[v] = true;
                    q.push( { v , curr } );
                }
                else if( parent != v ) return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj( n );
        vector<bool> vis( n , false );
        for( vector<int> edge : edges )
        {
            adj[edge[0]].push_back( edge[1] );
            adj[edge[1]].push_back( edge[0] );
        }

        if( bfs( 0 , n , adj , vis ) ) return false;

        for( int i = 0 ; i < n ; i++ )
        {
            if( !vis[i] )
            {
                return false;
            }
        }
        return true;

    }
};
