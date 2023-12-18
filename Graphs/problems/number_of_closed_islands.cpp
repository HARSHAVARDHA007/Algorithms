#include <bits/stdc++.h>
using namespace std;
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool flood_fill(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &visited)
{
  // If co-ordiantes are out of bounds then return false;
  if (x < 0 || x >= n || y < 0 || y >= m)
  {
    return false;
  }
  // if this is 1 then we 
  if(grid[x][y] == 1 || visited[x][y]) {
    return true;
  }
  visited[x][y] = 1;
  bool final_res = true;
  for (int i = 0; i < 4; i++)
  {
    // Send out DFS on all 4 sides and if any one comes as false return false
    int newX = x + dx[i], newY = y + dy[i];
    bool island = flood_fill(grid, newX, newY, visited);
    if (!island)
    {
      final_res = false;
    }
  }
  return final_res;
}

int closedIsland(vector<vector<int>> &grid)
{
  n = grid.size();
  m = grid[0].size();
  vector<vector<int>> visited(n, vector<int>(m, 0));
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!visited[i][j] && grid[i][j] != 1)
      {
        bool island = flood_fill(grid, i, j, visited);
        if (island)
        {
          ans++;
        }
      }
    }
  }
  return ans;
}