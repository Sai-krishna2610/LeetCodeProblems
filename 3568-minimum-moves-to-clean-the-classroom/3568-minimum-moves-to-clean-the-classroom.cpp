class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size();
        int cols = classroom[0].size();

        vector<vector<int>> lockerId(rows, vector<int>(cols, 0));

        int startRow = 0, startCol = 0;
        int totalLockers = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                char cell = classroom[r][c];

                if (cell == 'S') {
                    startRow = r;
                    startCol = c;
                }
                else if (cell == 'L') {
                    lockerId[r][c] = totalLockers++;
                }
            }
        }

        if (totalLockers == 0)
            return 0;

        vector<vector<vector<vector<bool>>>> visited(
            rows,
            vector<vector<vector<bool>>>(
                cols,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << totalLockers, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> bfsQueue;

        int initialMask = (1 << totalLockers) - 1;

        bfsQueue.emplace(startRow, startCol, energy, initialMask);
        visited[startRow][startCol][energy][initialMask] = true;

        vector<int> movement = {-1, 0, 1, 0, -1};

        int steps = 0;

        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();

            while (levelSize--) {
                auto [row, col, power, remaining] = bfsQueue.front();
                bfsQueue.pop();

                if (remaining == 0)
                    return steps;

                if (power <= 0)
                    continue;

                for (int dir = 0; dir < 4; dir++) {
                    int nextRow = row + movement[dir];
                    int nextCol = col + movement[dir + 1];

                    if (nextRow < 0 || nextRow >= rows ||
                        nextCol < 0 || nextCol >= cols ||
                        classroom[nextRow][nextCol] == 'X') {
                        continue;
                    }

                    int nextPower;

                    if (classroom[nextRow][nextCol] == 'R')
                        nextPower = energy;
                    else
                        nextPower = power - 1;

                    int nextMask = remaining;

                    if (classroom[nextRow][nextCol] == 'L') {
                        nextMask &= ~(1 << lockerId[nextRow][nextCol]);
                    }

                    if (!visited[nextRow][nextCol][nextPower][nextMask]) {
                        visited[nextRow][nextCol][nextPower][nextMask] = true;

                        bfsQueue.emplace(
                            nextRow,
                            nextCol,
                            nextPower,
                            nextMask
                        );
                    }
                }
            }

            steps++;
        }

        return -1;

    }
};