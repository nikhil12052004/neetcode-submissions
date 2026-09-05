class Solution {
public:
    int maxi = 0;
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 1;
        vis[i][j] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;

                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && 
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        vis[nrow][ncol] = 1;
                        cnt++;
                        q.push({nrow, ncol});
                    }
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] != 1 && grid[i][j] == 1){
                    maxi = max(maxi, bfs(grid, vis, i, j));
                }
            }
        }
        return maxi;
    }
};
