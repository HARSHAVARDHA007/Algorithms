#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canPlace(vector<vector<char>> &board, int x, int y, int value)
  {

    // check row wise
    for (int i = 0; i < 9; i++)
    {
      if (board[x][i] == (value + '0'))
        return false;
    }

    // check col wise
    for (int j = 0; j < 9; j++)
    {
      if (board[j][y] == (value + '0'))
        return false;
    }

    // check in the 3*3 square
    int row, col;
    if (x < 3)
    {
      row = 0;
    }
    else if (x >= 3 && x < 6)
    {
      row = 3;
    }
    else if (x >= 6)
    {
      row = 6;
    }
    if (y < 3)
    {
      col = 0;
    }
    else if (y >= 3 && y < 6)
    {
      col = 3;
    }
    else if (y >= 6)
    {
      col = 6;
    }
    for (int i = row; i < row + 3; ++i)
    {
      for (int j = col; j < col + 3; j++)
      {
        if (board[i][j] == (value + '0'))
          return false;
      }
    }
    return true;
  }
  bool helper(vector<vector<char>> &board, int x, int y)
  {
    // Base case if we reach last elemnt which is board[8][8] we are done
    if (x == 9 && y == 0)
      return true;

    // for each cell we have 9 options to explore if the value there is '.'
    if (board[x][y] != '.')
    {
      // don't do anything move forward
      if (y < 8 && x < 9)
      {
        // move to next column
        return helper(board, x, y + 1);
      }
      else if (y == 8 && x < 9)
      {
        // move to new row
        return helper(board, x + 1, 0);
      }
      return true;
    }
    else
    {
      // we have 9 options to explore if the value is '.'
      for (int k = 1; k <= 9; k++)
      {
        if (canPlace(board, x, y, k))
        {
          board[x][y] = (k + '0');
          bool subProblem = false;
          if (y < 8 && x < 9)
          {
            // move to next column
            subProblem = helper(board, x, y + 1);
          }
          else if (y >= 8 && x < 9)
          {
            // move to new row
            subProblem = helper(board, x + 1, 0);
          }
          if (subProblem)
            return true;
          // else backtrack
          else
            board[x][y] = '.';
        }
      }
      // If it moves out of the loop that means it can't use any of the above values
      return false;
    }
  }

  void solveSudoku(vector<vector<char>> &board)
  {
    helper(board, 0, 0);
    return;
  }
};