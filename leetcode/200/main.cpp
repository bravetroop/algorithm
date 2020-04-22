class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();

        grid[i][j] = '0';

        if (i>0 && grid[i-1][j] == '1') {
            dfs(grid, i-1, j);
        }

        if (i+1 < row && grid[i+1][j] == '1') {
            dfs(grid, i+1, j);
        }

        if (j > 0 && grid[i][j-1] == '1') {
            dfs(grid, i, j-1);
        }

        if (j+1 < col && grid[i][j+1] == '1') {
            dfs(grid, i, j+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;

        for(int i = 0; i < grid.size(); ++i) {
            vector<char>& v = grid[i];
            for(int j = 0; j < v.size(); ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }
};