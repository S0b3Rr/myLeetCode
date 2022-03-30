class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //DP
        const int MAX = INT_MAX - 10;
        int row = mat.size(), col = mat[0].size(); 
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 0)
                    continue;
                int top = MAX, left = MAX;
                if (i - 1 >= 0)
                    top = mat[i - 1][j];
                if (j - 1 >= 0)
                    left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                if (mat[i][j] == 0)
                    continue;
                int bottom = MAX, right = MAX;
                if (i < row - 1)
                    bottom = mat[i + 1][j];
                if (j < col - 1)
                    right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};

//inspired by: https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space