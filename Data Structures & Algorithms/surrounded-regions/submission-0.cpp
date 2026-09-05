class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
       int n = board.size();
       int m = board[0].size();
       int drow[] = {-1, 0, 1, 0};
       int dcol[] = {0, 1, 0, -1};
       for(int i = 0; i<4; i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0){
            vis[nrow][ncol] = 1;
            dfs(nrow, ncol, board, vis); 
        }
       }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //1st col
        for(int i = 0; i<n; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                vis[i][0] = 1;
                dfs(i, 0, board, vis);
                
            }            
        }
        //last col
        for(int i = 0; i<n; i++){
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0){
                vis[i][m-1] = 1;
                dfs(i, m-1, board, vis);
                
            }
        }
        //1st row
        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O' && vis[0][j] == 0){
                vis[0][j] = 1;
                dfs(0, j, board, vis);
                
            } 
        }
        // last row
        for(int j = 0; j<m; j++){
            if(board[n-1][j] == 'O' && vis[n-1][j] == 0){
                vis[n-1][j] = 1;
                dfs(n-1, j, board, vis);
                
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] == 1) board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
