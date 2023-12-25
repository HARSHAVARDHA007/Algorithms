/*

https://leetcode.com/problems/shortest-bridge/

*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int rows, cols;
  queue<pair<int, pair<int, int>>> q;
  void colorTheGraph(vector<vector<int>> &grid, int x, int y)
  {
    grid[x][y] = 2;
    int added = 0;
    for (int k = 0; k < 4; k++)
    {
      int nextX = x + dx[k], nextY = y + dy[k];
      if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols)
      {
        if (grid[nextX][nextY] == 1)
        {
          colorTheGraph(grid, nextX, nextY);
        }
        else if (grid[nextX][nextY] == 0 && !added)
        {
          q.push({0, {x, y}});
          added = 1;
        }
      }
    }
  }
  int shortestBridge(vector<vector<int>> &grid)
  {
    rows = grid.size();
    cols = grid[0].size();
    int answer = INT_MAX;
    for (int i = 0; i < rows; i++)
    {
      int getOut = 0;
      for (int j = 0; j < cols; j++)
      {
        if (grid[i][j] == 1)
        {
          colorTheGraph(grid, i, j);
          getOut = 1;
          break;
        }
      }
      if (getOut)
      {
        break;
      }
    }
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
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
        if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols)
        {
          if (grid[nextX][nextY] == 1)
          {
            return currCount;
          }
          else if (grid[nextX][nextY] == 0 && !visited[nextX][nextY])
          {
            q.push({currCount + 1, {nextX, nextY}});
          }
        }
      }
    }
    return answer;
  }
};