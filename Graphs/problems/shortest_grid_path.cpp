/*
Shortest Grid Path

Given a two dimensional grid, each cell of which contains integer cost which 
represents a cost to traverse through that cell, we need to find a 
path from top left cell to bottom right cell by which total cost incurred is minimum.

Note : It is assumed that negative cost cycles do not exist in input matrix.

*/

#include <bits/stdc++.h>
using namespace std;

int shortest_path(vector<vector<int>> grid)
{
  int rows = grid.size();
  int cols = grid[0].size();
  // Create a 2D array to store the smallest distance from source till that node.
  // currently we are considering 0,0 as the source node.
  vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
  // Intialize the starting with the intial value
  int i = 0;
  int j = 0;
  // Four neighbours
  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  dist[0][0] = grid[0][0];
  // Create a min priority queue
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
  // push the starting element
  pq.push({dist[0][0], {i, j}});
  while (!pq.empty())
  {
    // Get the first element
    int cx = pq.top().second.first;
    int cy = pq.top().second.second;
    int cd = pq.top().first;
    pq.pop();
    // iterarte over the neighbours
    for (int k = 0; k < 4; k++)
    {
      int nx = cx + dx[k];
      int ny = cy + dy[k];
      // Check if the node is valid and not visited before
      if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && cd + grid[nx][ny] < dist[nx][ny])
      {
        // If the neighbour is in limits and less distance then push that into priority queue
        dist[nx][ny] = cd + grid[nx][ny];
        pq.push({dist[nx][ny], {nx, ny}});
      }
    }
  }
  return dist[rows - 1][cols - 1];
}