

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n = 9; // to avoid duplicates we r using set
        vector<unordered_set<char>> rows(9); // remain in sudoku there r rows col boxes all a=of 9
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int r = 0; r < n; r++) {

            for (int c = 0; c < n; c++) {

                char ch = board[r][c]; // its not ingeter nums its a char nums

                if (ch == '.') continue; // empty


                int boxId = ((r / 3) * 3) + (c / 3); // box formula

                if (
                    rows[r].count(ch) ||   //if the row col and box appear same char num return as false 
                    cols[c].count(ch) || 
                    boxes[boxId].count(ch)
                ) {
                    return false;
                }

                rows[r].insert(ch); // its not repaeated then store it 
                cols[c].insert(ch);
                boxes[boxId].insert(ch);
            }
        }

        return true;
    }
};