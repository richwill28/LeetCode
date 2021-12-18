class Solution {
private:
    void spiralTraverse(vector<vector<int>>& matrix, vector<int>& spiral, vector<vector<bool>>& isTraversed, pair<int, int> row, pair<int, int> column) {
        // traverse right
        for (int i = column.first; i <= column.second; i++) {
            if (!isTraversed[row.first][i]) {
                spiral.push_back(matrix[row.first][i]);
                isTraversed[row.first][i] = true;
            }
        }

        // traverse down
        for (int i = row.first; i <= row.second; i++) {
            if (!isTraversed[i][column.second]) {
                spiral.push_back(matrix[i][column.second]);
                isTraversed[i][column.second] = true;
            }
        }

        // traverse left
        for (int i = column.second; i >= column.first; i--) {
            if (!isTraversed[row.second][i]) {
                spiral.push_back(matrix[row.second][i]);
                isTraversed[row.second][i] = true;
            }
        }

        // traverse up
        for (int i = row.second; i >= row.first; i--) {
            if (!isTraversed[i][column.first]) {
                spiral.push_back(matrix[i][column.first]);
                isTraversed[i][column.first] = true;
            }
        }
    }

public:
    // O(mn) time and O(mn) space complexity
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> isTraversed(m, vector<bool>(n, false));
        pair<int, int> row = {0, m - 1};
        pair<int, int> column = {0, n - 1};
        while (row.first <= row.second && column.first <= column.second) {
            spiralTraverse(matrix, spiral, isTraversed, row, column);
            row.first += 1;
            row.second -= 1;
            column.first += 1;
            column.second -= 1;
        }
        return spiral;
    }

    // Better implementation using direction matrix
    // O(mn) time and O(mn) space complexity
    // Disregarding solution array, actual runtime space complexity = O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> directionMatrix = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 0 = right, 1 = down, 2 = left, 3 = up
        vector<int> shift = {n, m - 1};
        int currentDirection = 0;
        int row = 0, col = -1;
        while (shift[currentDirection % 2] != 0) {
            for (int i = 0; i < shift[currentDirection % 2]; i++) {
                row += directionMatrix[currentDirection][0];
                col += directionMatrix[currentDirection][1];
                spiral.push_back(matrix[row][col]);
            }

            shift[currentDirection % 2]--;
            currentDirection = (currentDirection + 1) % 4;
        }
        return spiral;
    }
};
