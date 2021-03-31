class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col, char c) {
        for(int i=0;i<9;i++) {
            if(board[i][col] == c)
                return false;
        }
        for(int i=0;i<9;i++) {
            if(board[row][i] == c)
                return false;
        }
        int rw = row - row%3;
        int cl = col - col%3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[rw+i][cl+j] == c)
                    return false;
            }
        }
        return true;
    }
    bool solveUtil(vector<vector<char>>& board,int i,int j) {
        if(i == 9)
            return true;
        if(j == 9)
            return solveUtil(board,i+1,0);
        if(board[i][j]!='.')
            return solveUtil(board,i,j+1);
        for(char c = '1';c <= '9';c++) {
            if(isSafe(board,i,j,c)) {
                board[i][j] = c;
                if(solveUtil(board,i,j+1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveUtil(board,0,0);
        return;
    }
};
