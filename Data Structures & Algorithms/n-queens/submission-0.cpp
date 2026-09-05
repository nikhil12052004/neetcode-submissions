class Solution {
public:
    vector<vector<string>> ans;
    bool issafe(int row, int col, vector<string> &board, int n){
        //horizontal check
        for(int j = 0; j<n; j++){
            if(board[row][j] == 'Q') return false;
        }
        //vertical check
        for(int i = 0; i<n; i++){
            if(board[i][col] == 'Q') return false;
        }
        //diagnol top-left
        for(int i = row, j = col; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }
        //diagnol top-right
        for(int i = row, j = col; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(vector<string> &board, int n, int row){
        // base case - agar last row pe pahuch gaye
        if(row >= n){
            ans.push_back(board);
            return;
        }
        // particular row ke liye col by col jaake check karo
        for(int j = 0; j<n; j++){
            if(issafe(row, j, board, n)){
                board[row][j] = 'Q';
                solve(board, n, row+1);
                board[row][j] = '.'; // back-track
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n, '.'));
        solve(board, n, 0);
        return ans;
    }
};
