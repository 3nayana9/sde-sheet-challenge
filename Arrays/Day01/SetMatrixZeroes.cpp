/*
  Problem: Set Matrix Zeroes
  Link: https://leetcode.com/problems/set-matrix-zeroes/

  Approach:
  - Brute: Use a copy of the matrix to mark zeroes
  - Better: Use separate row[] and col[] boolean arrays
  - Optimal: Use first row and first column of matrix itself as markers
              Special case: matrix[0][0] is shared, so use a separate variable col0
              for tracking whether column 0 itself should be zeroed.

  Time: O(M*N)  Space: O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int M = matrix.size();
        int N = matrix[0].size();
        int col0 = 1;

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0){
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }

        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int j = 0; j < N; j++) matrix[0][j] = 0;
        }
        if(col0 == 0){
            for(int i = 0; i < M; i++) matrix[i][0] = 0;
        }
    }
};
