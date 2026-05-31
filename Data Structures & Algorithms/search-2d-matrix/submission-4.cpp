class Solution {
public:
    bool row_search(vector<int>& row, int target) {
        for (auto num : row){
            if (num == target){
                return true;
            }
        }
        return false;
    }
    bool col_search(vector<vector<int>>& matrix, int target, int l, int r) {
        int cols = matrix[0].size();
        int m = l + (r-l) / 2;
        if (l > r){
            return false;
        }

        if (target >= matrix[m][0] && target <= matrix[m][cols-1]){
            return row_search(matrix[m], target);
        }
        else if (target > matrix[m][cols-1]){
            return col_search(matrix, target, m+1, r);
        }
        else if (target < matrix[m][0]){
            return col_search(matrix, target, l, m-1);
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return col_search(matrix, target, 0, matrix.size()-1);
    }
};
