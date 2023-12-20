/*
https://leetcode.com/problems/coloring-a-border/

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int rows;
  int cols;
  int newColor;
  int currColor;
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  void dfs(vector<vector<int>> &grid, vector<vector<int>> &ans, vector<vector<int>> &visited, int x, int y)
  {
    visited[x][y] = 1;
    // If the curr block is an edge block mark as an newColor
    if (x == 0 || y == 0 || x == rows - 1 || y == cols - 1)
    {
      ans[x][y] = newColor;
    }
    // else if it is adjacent to any non component block
    for (int i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == currColor && visited[nx][ny] == 0)
      {
        dfs(grid, ans, visited, nx, ny);
      }
      else if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] != currColor)
      {
        ans[x][y] = newColor;
      }
    }
  }
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
  {
    vector<vector<int>> ans(grid);
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    newColor = color;
    currColor = grid[row][col];
    dfs(grid, ans, visited, row, col);
    return ans;
  }
};