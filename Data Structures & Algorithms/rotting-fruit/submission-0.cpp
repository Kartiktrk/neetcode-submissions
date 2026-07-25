class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;
        queue<vector<int>> q;
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 2 ) q.push( {i,j,0} );
            }
        }
        while( !q.empty() )
        {
            int siz = q.size();
            while( siz-- )
            {
                vector<int> curr = q.front();
                q.pop();
                for( vector<int> dir : dirs )
                {
                    int x = curr[0]+dir[0];
                    int y = curr[1]+dir[1];
                    if( x < m && x >= 0 && y < n && y >= 0 )
                    {
                        if( grid[x][y] != 0 && grid[x][y] != 2)
                        {
                            // cout << x << " " << y << "\n";
                            grid[x][y] = 2;
                            ans = max( ans,curr[2]+1 );
                            q.push( {x,y,curr[2]+1} );
                        }
                    }
                }
            }
        }
        // cout << m << " " << n << "\n";
        for( int i = 0 ; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                // cout << grid[i][j] << " ";
                if( grid[i][j] == 1 ) return -1;
            }
            // cout << "\n";
        }
        return ans;
    }
};