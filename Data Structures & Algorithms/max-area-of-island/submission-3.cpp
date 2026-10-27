class Solution {
public:
    int maxi = 0;
    int bfs(vector<vector<int>>& vis, vector<vector<int>>& grid, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        int curr = 1;
        vis[i][j] = 1;

        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int k = 0; k<4; k++){
                int nrow = drow[k] + row;
                int ncol = dcol[k] + col;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                        curr++;
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
            }
        }
        return curr;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    maxi = max(maxi, bfs(vis, grid, i, j));
                }
            }
        }
        return maxi;
    }
};
