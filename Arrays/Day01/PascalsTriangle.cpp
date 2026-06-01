/*
  Problem: Pascal's Triangle
  Link: https://leetcode.com/problems/pascals-triangle/

  Approach:
  - Brute: Compute nCr for each element using factorial
  - Optimal: Generate each row using the formula:
             C(row, col) = C(row, col-1) * (row - col) / col
             Builds each row in O(n) without recomputing from scratch.

  Time: O(N^2)  Space: O(N^2) for output
*/

class Solution {
public:
    vector<int> ansRow(int row){
        vector<int> ansR;
        ansR.push_back(1);
        int ans = 1;
        for(int col = 1; col < row; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansR.push_back(ans);
        }
        return ansR;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(ansRow(i));
        }
        return ans;
    }
};
