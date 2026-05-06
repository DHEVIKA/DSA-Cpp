class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int r = 0; r < rows; r++) {
            int p = 0; // make pointer as 0 initally
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '.') {  // when u find stone '.' swap the row col with row pointer then update pointer
                    swap(grid[r][c], grid[r][p]);
                    p++;
                } else if (grid[r][c] == '*') // when u find obstacle '*' p jumps to the position right after the current index.
                    p = c + 1;
            }
        }
        //rotae 90 degree row -> col to col ->row
        vector<vector<char>> res(cols, vector<char>(rows));
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                res[c][rows - 1 - r] = grid[r][c];
                
        return res;
    }
};