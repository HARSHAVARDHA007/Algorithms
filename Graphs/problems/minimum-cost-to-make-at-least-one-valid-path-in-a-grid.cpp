/*

https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minCost(vector<vector<int>> &grid)
  {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    dist[0][0] = 0;
    deque<pair<int, pair<int, int>>> q;
    q.push_front({0, {0, 0}});
    while (!q.empty())
    {
      // get the top element out of the queue
      auto topEle = q.front();
      q.pop_front();
      int currWeight = topEle.first;
      int x = topEle.second.first;
      int y = topEle.second.second;
      for (int i = 0; i < 4; i++)
      {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols)
        {
          int edgeWeight = grid[x][y] == i + 1 ? 0 : 1;
          if (currWeight + edgeWeight < dist[nx][ny])
          {
            dist[nx][ny] = currWeight + edgeWeight;
            edgeWeight == 0 ? q.push_front({dist[nx][ny], {nx, ny}}) : q.push_back({dist[nx][ny], {nx, ny}});
          }
        }
      }
    }
    return dist[rows - 1][cols - 1];
  }
};