class Solution {
public:

    bool findCol(vector<vector<int>>& matrix, int target,
                 int row, int stCol, int endCol) {

        while(stCol <= endCol) {

            int mid = stCol + (endCol - stCol) / 2;

            if(matrix[row][mid] == target) {
                return true;
            }
            else if(matrix[row][mid] < target) {
                stCol = mid + 1;
            }
            else {
                endCol = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int stRow = 0;
        int endRow = matrix.size() - 1;

        int n = matrix[0].size();

        while(stRow <= endRow) {

            int midRow = stRow + (endRow - stRow) / 2;

            // Target is inside this row's range
            if(matrix[midRow][0] <= target &&
               target <= matrix[midRow][n - 1]) {

                return findCol(matrix, target,
                               midRow, 0, n - 1);
            }

            // Target is greater than this row
            if(target > matrix[midRow][n - 1]) {
                stRow = midRow + 1;
            }
            else {
                endRow = midRow - 1;
            }
        }

        return false;
    }
};