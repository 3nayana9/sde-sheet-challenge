/*
  Problem: Next Permutation
  Link: https://leetcode.com/problems/next-permutation/

  Approach:
  - Brute: Generate all permutations, find next one
  - Better: Use C++ STL next_permutation()
  - Optimal (implemented):
      1. Find break point — rightmost index where arr[i] < arr[i+1]
      2. Swap arr[break] with the smallest element to its right that is still > arr[break]
      3. Reverse the suffix after break point to get the next smallest arrangement

  Time: O(N)  Space: O(1)
*/

vector<int> nextPermutation(vector<int> arr, int n){
    
    int idx = -1;
    for(int i = n - 2; i >= 0; i--){
        if(arr[i] < arr[i + 1]){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i = n - 1; i >= idx; i--){
        if(arr[i] > arr[idx]){
            swap(arr[i], arr[idx]);
            break;
        }
    }

    reverse(arr.begin() + idx + 1, arr.end());
    return arr;
}
