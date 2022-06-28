class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int  L = 0, R = matrix[0].size() * matrix.size() - 1;
        while(L <= R)
        {
            int M = L + (R - L)/2;
            int r = M / matrix[0].size();
            int c = M % matrix[0].size();
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] > target)
                R = M - 1;
            else
                L = M + 1;
        }
        return false;
    }
};
