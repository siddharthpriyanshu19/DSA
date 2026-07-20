class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        k = k % total; // Prevent unnecessary rotations
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int old_1d = i * n + j;
                int new_1d = (old_1d + k) % total;
                
                int new_i = new_1d / n;
                int new_j = new_1d % n;
                
                ans[new_i][new_j] = grid[i][j];
            }
        }
        
        return ans;
    }
};