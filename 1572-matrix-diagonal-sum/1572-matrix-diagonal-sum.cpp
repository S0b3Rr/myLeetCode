class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int i = 0;
        int m = mat.size() - 1;
        int size = mat.size();
        while(true) {
            sum += mat[i][i];
            sum += mat[i][m];
            if (i == size - 1)
                break;
            i++;
            m--;
        }
        if (size % 2 != 0)
            sum -= mat[size / 2][size / 2];
        return sum;
    }
};