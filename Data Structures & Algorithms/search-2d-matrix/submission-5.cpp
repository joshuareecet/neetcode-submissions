class Solution {
public:
    bool row_search(vector<int>& row, int target, int l, int r) {
        int m = l + (r-l) / 2;
        if (l > r) return false;
        if (target == row[m]) return true;

        if (row[m] < target){
            return row_search(row, target, m+1, r);
        }
        else {//if (row[m] > target){
            return row_search(row, target, l, m-1);
        }
    }
    bool col_search(vector<vector<int>>& matrix, int target, int l, int r) {
        int cols = matrix[0].size() - 1;
        int m = l + (r-l) / 2;
        if (l > r) return false;

        if (target >= matrix[m][0] && target <= matrix[m][cols]){
            return row_search(matrix[m], target, 0, cols);
        }
        else if (target > matrix[m][cols]){
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
