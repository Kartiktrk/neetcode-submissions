class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    void bfs( int i, int j, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> v( m, vector<bool>(n,false) );
        queue<vector<int>> q;
        q.push({i,j,0});
        while( !q.empty() )
        {
            int siz = (int)q.size();
            // cout << siz << "\n";
            for( int l = 0 ; l < siz ; l++ )
            {
                vector<int> curr = q.front();
                q.pop();
                v[curr[0]][curr[1]] = true;
                for( vector<int> dir : dirs )
                {
                    int x = curr[0]+dir[0];
                    int y = curr[1]+dir[1];
                    if( x < m && x >= 0 && y < n && y >= 0 && !v[x][y])
                    {
                        if( grid[x][y] != -1  && grid[x][y] != 0)
                        {
                            grid[x][y] = min( grid[x][y], curr[2]+1 );
                            // cout << "x : " << x << "y : " << y << "\n";
                            q.push({x,y,curr[2]+1});
                        }
                    }
                }
            }
        }

    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for( int i = 0; i < m ; i++ )
        {
            for( int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 0 ) bfs( i,j,grid );
            }
        }
    }
};
