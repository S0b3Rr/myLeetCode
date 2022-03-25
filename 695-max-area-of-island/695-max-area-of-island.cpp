class Solution {
public:
    int find(vector<vector<int>>& grid, int x, int y) {
        int sum = 0;
        if (grid[x][y] == 1) {
            sum++;
            grid[x][y] = 0;
            if (x >= 1)
                sum += find(grid, x - 1, y);
            if (y >= 1)
                sum += find(grid, x, y - 1);
            if (x + 1 < grid.size())
                sum += find(grid, x + 1, y);
            if (y + 1 < grid[0].size())
                sum += find(grid, x, y + 1);
        }
        return sum;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    maxArea = max(find(grid, i, j), maxArea);
            }
        }
        return maxArea == INT_MIN ? 0 : maxArea;
    }
};