class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                int d = c - '1';
                int b = (i / 3) * 3 + (j / 3);

                if (row[i][d] || col[j][d] || box[b][d]) {
                    return false;
                }

                row[i][d] = true;
                col[j][d] = true;
                box[b][d] = true;
            }
        }

        return true;
    }
};