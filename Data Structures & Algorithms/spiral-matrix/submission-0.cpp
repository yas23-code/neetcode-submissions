class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int srow = 0, erow = n - 1;
        int scol = 0, ecol = m - 1;

        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            // top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }

            // right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            // bottom
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) break;
                ans.push_back(matrix[erow][j]);
            }

            // left
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};