class Solution {
public:
    void bfs(vector<vector<int>>& heights, vector<vector<int>>& vis,
        vector<vector<int>>& ocean, int i, int j){
            int n = heights.size();
            int m = heights[0].size();

            vis[i][j] = 1;
            ocean[i][j] = 1;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            
            queue<pair<int,int>> q;
            q.push({i,j});
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int i = 0; i<4; i++){
                    int nrow = drow[i] + row;
                    int ncol = dcol[i] + col;

                    if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                        heights[nrow][ncol] >= heights[row][col] && 
                        !vis[nrow][ncol]){
                            vis[nrow][ncol] = 1;
                            ocean[nrow][ncol] = 1;
                            q.push({nrow, ncol});
                    }
                }
            }

        }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        // doing for pacific
        //1st row
        for(int j = 0; j<m; j++){
            if(!vis[0][j]){
                bfs(heights, vis, pac, 0, j);
            }
        }
        //1st col
        for(int i = 0; i<n; i++){
            if(!vis[i][0]){
                bfs(heights, vis, pac, i, 0);
            }
        }
        vis.assign(n, vector<int>(m, 0));
        // doing for atlantic
        // last row
        for(int j = 0; j<m; j++){
            if(!vis[n-1][j]){
                bfs(heights, vis, atl, n-1, j);
            }
        }
        // last col
        for(int i = 0; i<n; i++){
            if(!vis[i][m-1]){
                bfs(heights, vis, atl, i, m-1);
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(pac[i][j] == 1 && atl[i][j] == 1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
