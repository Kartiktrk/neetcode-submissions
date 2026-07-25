class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i  = 0 ; i < 9 ; i++){
            //row
            map<char,int> mp;
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.') continue;
                if(mp[board[i][j]] > 0)return false;
                else mp[board[i][j]]++; 
            }
            mp.clear();
            //column
            for(int j = 0 ; j < 9 ; j++){
                if(board[j][i] == '.') continue;
                if(mp[board[j][i]] > 0) return false;
                else mp[board[j][i]]++;
            }
            mp.clear();
            //squares
            for(int j = (i%3)*3 ; j < ((i%3)*3) +3 ; j++){
                for(int k = (i/3)*3 ; k < ((i/3)*3)+3; k++){
                    if(board[j][k] == '.') continue;
                    if(mp[board[j][k]] > 0) return false;
                    else mp[board[j][k]]++;
                }
            }
        }
        return true;
    }
};
