#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int rows, cols;
  queue<pair<int, pair<int, int>>> q;
  void DFS(vector<vector<int>> &grid, vector<vector<int>> &visited, int x, int y)
  {
    visited[x][y] = true;
    q.push({0, {x, y}});
    for (int k = 0; k < 4; k++)
    {
      int nextX = x + dx[k], nextY = y + dy[k];
      if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols && !visited[nextX][nextY] && grid[nextX][nextY] == 1)
      {
        DFS(grid,visited,nextX,nextY);
      }
    }
  }
  int shortestBridge(vector<vector<int>> &grid)
  {
    rows = grid.size();
    cols = grid[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    bool loop = false;
    for (int i = 0; i < rows && !loop; i++)
    {
      for (int j = 0; j < cols && !loop; j++)
      {
        if (grid[i][j] == 1)
        {
          DFS(grid, visited, i, j);
          loop = true;
        }
      }
    }
    while (!q.empty())
    {
      int currCount = q.front().first;
      int currX = q.front().second.first;
      int currY = q.front().second.second;
      visited[currX][currY] = 1;
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int nextX = currX + dx[k], nextY = currY + dy[k];
        if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols && !visited[nextX][nextY])
        {
          if (grid[nextX][nextY] == 1)
          {
            return currCount;
          }
          else if (grid[nextX][nextY] == 0)
          {
            q.push({currCount + 1, {nextX, nextY}});
          }
        }
      }
    }
    return -1;
  }
};