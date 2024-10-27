class Solution {
public:
    int countSquares(vector<vector<int>>& grid) {
        const int rows = grid.size(), cols = grid[0].size();
        int totalSquares = 0;
        totalSquares = count(grid[0].begin(), grid[0].end(), 1);
        
        for(int i = 1; i < rows; i++)
            totalSquares += grid[i][0];
        
        for(int i = 1; i < rows; i++)
            for(int j = 1; j < cols; j++){
                if (grid[i][j] == 0) continue;
                grid[i][j] = 1 + min({grid[i-1][j], grid[i-1][j-1], grid[i][j-1]});
                totalSquares += grid[i][j];
            }
        return totalSquares;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();