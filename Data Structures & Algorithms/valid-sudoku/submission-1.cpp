class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int,int>,set<char>> box_vals {};
        vector<set<char>> row_vals(board.size());
        vector<set<char>> col_vals(board[0].size());
        
        for (int row {0}; row < board.size(); ++row){
            for (int col {0}; col < board[0].size(); ++col){
            char curr = board[row][col];
            if (curr == '.') continue;
            
            // col check
            if (col_vals[col].find(curr) != col_vals[col].end()) return false;
            col_vals[col].insert(curr);
            
            //row check
            if (row_vals[row].find(curr) != row_vals[row].end()) return false;
            row_vals[row].insert(curr);

            //box check
            pair<int,int> box_key = {row/3,col/3};
            if (box_vals[box_key].find(curr) != box_vals[box_key].end()) return false;
            box_vals[box_key].insert(curr);
            }

        }
    return true;
    }
};
