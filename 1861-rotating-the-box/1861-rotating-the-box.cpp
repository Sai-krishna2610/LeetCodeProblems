class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();       // Number of rows
        int n = box[0].size();    // Number of columns

        // Step 1: Rotate the box by 90 degrees clockwise
        vector<vector<char>> rotatedBox(n, vector<char>(m)); // Transposed dimensions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotatedBox[j][m - 1 - i] = box[i][j]; // Transpose and reverse rows
            }
        }

        // Step 2: Apply gravity in each column
        for (int col = 0; col < m; ++col) {  // Iterate over columns of the rotated box
            int emptyRow = n - 1;            // Start from the bottom of the column
            for (int row = n - 1; row >= 0; --row) {
                if (rotatedBox[row][col] == '#') {
                    // Move the stone to the lowest empty space
                    swap(rotatedBox[row][col], rotatedBox[emptyRow][col]);
                    --emptyRow; // Update the empty space pointer
                } else if (rotatedBox[row][col] == '*') {
                    // Obstacle blocks further movement; reset empty space
                    emptyRow = row - 1;
                }
            }
        }

        return rotatedBox;
    }
};
