
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (st.count(board[i][j])) {
                    return false;
                }

                st.insert(board[i][j]);
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> st;

            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;

                if (st.count(board[i][j])) {
                    return false;
                }

                st.insert(board[i][j]);
            }
        }

        // Check 3x3 boxes
        for (int box = 0; box < 9; box++) {
            unordered_set<char> st;

            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {

                    char ch = board[startRow + i][startCol + j];

                    if (ch == '.') continue;

                    if (st.count(ch)) {
                        return false;
                    }

                    st.insert(ch);
                }
            }
        }

        return true;
    }
};
