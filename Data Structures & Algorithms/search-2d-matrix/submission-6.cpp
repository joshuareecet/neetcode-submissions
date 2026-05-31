class Solution {
public:
    bool row_search(vector<int>& row, int target, int l, int r) {
        if (l > r) return false;
        int m = l + (r-l) / 2;
        if (target == row[m]) return true;

        if (row[m] < target){
            return row_search(row, target, m+1, r);
        }
        else {//if (row[m] > target){
            return row_search(row, target, l, m-1);
        }
    }
    bool col_search(vector<vector<int>>& matrix, int target, int l, int r) {
        if (l > r) return false;
        
        int last_col = matrix[0].size() - 1;
        int m = l + (r-l) / 2;

        if (target >= matrix[m][0] && target <= matrix[m][last_col]){
            return row_search(matrix[m], target, 0, last_col);
        }
        else if (target > matrix[m][last_col]){
            return col_search(matrix, target, m+1, r);
        }
        else {//if (target < matrix[m][0]){
            return col_search(matrix, target, l, m-1);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return col_search(matrix, target, 0, matrix.size()-1);
    }
};
