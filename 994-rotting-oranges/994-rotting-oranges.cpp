class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> DIR = {-1, 0, 1, 0, -1}; //used to find 4-directionally adjacent
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int timer = -1;
        while (!q.empty()) {
            int size = q.size(); //still needed to make timer work properly
            while (size--) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int roww = p.first + DIR[i];
                    int coll = p.second + DIR[i + 1];
                    if (roww > -1 && roww < row && coll > -1 && coll < col && grid[roww][coll] == 1) {
                        grid[roww][coll] = 2;
                        q.push({roww, coll});
                        fresh--;
                    }
                }
            }
            timer++;
        }
        return fresh > 0 ? -1 : (timer == -1 ? 0 : timer);
    }
};