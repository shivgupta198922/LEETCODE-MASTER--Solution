class Solution {
    bool issafe(int row, int col, vector<string> &board, int n ){
        int dr =row;
        int dc=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=dr;
        col=dc;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
            
        }
        
        row=dr;
        col=dc;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;

    }
    void solv(int col, vector<string>& board ,vector<vector<string>> &ans, int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(issafe(row, col, board, n)){
                board[row][col]='Q';
                solv(col+1, board,ans, n);
                board[row][col]='.';
            }
        }

    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        solv(0, board, ans, n);
        return ans;
        
    }
};