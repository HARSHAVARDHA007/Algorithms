#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int orangesRotting(vector<vector<int>> &grid)
  {
    // get all the oranges that are rotten and add them to te queue
    //{mins,{x,y}}
    queue<pair<int, pair<int, int>>> q;
    int rows = grid.size(), cols = grid[0].size();
    int answer = 0;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({0, {i, j}});
        }
      }
    }
    while (!q.empty())
    {
      int currTime = q.front().first;
      int currX = q.front().second.first;
      int currY = q.front().second.second;
      q.pop();
      // Iterate the adjacent nodes
      for (int k = 0; k < 4; k++)
      {
        int nextX = currX + dx[k], nextY = currY + dy[k];
        if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols && grid[nextX][nextY] == 1)
        {
          // If there is a fresh orange at (nextX,nextY), then we can say this fresh orange will be rotten in current time + 1
          grid[nextX][nextY] = 2;
          q.push({currTime + 1, {nextX, nextY}});
          answer = max(answer, currTime + 1);
        }
      }
    }
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (grid[i][j] == 1)
        {
          return -1;
        }
      }
    }
    return answer;
  }
};