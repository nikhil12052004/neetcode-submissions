class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 0) q.push({{i, j}, 0});
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                int ndist = dist + 1;
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0
                    && grid[nrow][ncol] == INT_MAX){
                        grid[nrow][ncol] = ndist;
                        q.push({{nrow, ncol}, ndist});
                    }
            }
        }
    }
};
