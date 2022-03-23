class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = matrix.size() - 1; i >= 0; i--) {
            if (matrix[i][0] > target)
                continue;
            if (matrix[i][0] == target)
                return true;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};