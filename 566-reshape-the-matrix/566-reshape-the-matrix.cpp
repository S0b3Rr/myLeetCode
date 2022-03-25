class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rownum = mat.size(), colnum = mat[0].size();
        if (rownum * colnum != r * c)
            return mat;
        
        vector<int> memory;
        for (int i = 0; i < rownum; i++) {
            for (int j = 0; j < colnum; j++)
                memory.push_back(mat[i][j]);
        }
        vector<int>::iterator it = memory.begin();
        vector<vector<int>> ans(r , vector<int> (c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = *it;
                if (it != memory.end())
                    it++;
            }
        }
        return ans;
    }
};