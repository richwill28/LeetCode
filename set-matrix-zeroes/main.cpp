class Solution {
public:
    // store state of each row/col in the first row/col
    void setZeroes(vector<vector<int>>& matrix) {
        bool isColZero = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                isColZero = true;
            }

            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;   // set row status to 0
                    matrix[0][j] = 0;   // set col status to 0
                }
            }
        }

        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            if (isColZero) {
                matrix[i][0] = 0;
            }
        }
    }
};
