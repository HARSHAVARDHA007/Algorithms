#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void helper(vector<vector<string>> &answer, vector<string> &config, int row, int n)
  {

    // Base case
    if (row == n)
    {
      answer.push_back(config);
      return;
    }
    // check each column to place the queen in the curerent row
    for (int col = 0; col < n; col++)
    {
      bool canPlace = true;
      // Check for the previous row conflicts
      for (int x = row - 1; x >= 0; x--)
      {
        // In the same column
        if (config[x][col] == 'Q')
        {
          canPlace = false;
          break;
        }
        // In the right side diagonal
        if (col + row - x >= 0 && col + row - x <= n && config[x][col + row - x] == 'Q')
        {
          canPlace = false;
          break;
        }
        // In the left side diagonal
        if (col + x - row >= 0 && col + x - row <= n && config[x][col + x - row] == 'Q')
        {
          canPlace = false;
          break;
        }
      }
      if (canPlace)
      {
        // place the queen in the row,col
        config[row][col] = 'Q';
        helper(answer, config, row + 1, n);
        // Undo the previous work
        config[row][col] = '.';
      }
    }
    return;
  }
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> answer;
    vector<string> config;
    for (int i = 0; i < n; i++)
    {
      string s = string(n, '.');
      config.push_back(s);
    }
    helper(answer, config, 0, n);
    return answer;
  }
};