class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> row(10,false), col(10,false), sq(10,false);
        for( int i = 0 ; i < 9 ; i++ )
        {
            //check row and col
            for( int j = 0 ; j < 9 ; j++ )
            {
                //row

                if(board[i][j] != '.')
                {
                    if(row[(board[i][j]-'0')]) return false;
                    row[(board[i][j]-'0')] = true;
                }
                
                //col
                if(board[j][i] != '.')
                {
                    if(col[(board[j][i]-'0')]) return false;
                    col[(board[j][i]-'0')] = true;
                }

                //square
                int r = 3*(i/3) + j/3;
                int c = 3*(i%3) + j%3;
                if( board[r][c] != '.' )
                {
                    if(sq[board[r][c]]) return false;
                    sq[board[r][c]] = true;
                }
            }
            row = vector<bool>(10,false);
            col = vector<bool>(10,false);
            sq = vector<bool>(10,false);
        }
        return true;
    }
};
