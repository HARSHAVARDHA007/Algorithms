#include <bits/stdc++.h>
using namespace std;
#define inf 1000000
class Solution
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    // adjMatrix representation for the edges
    vector<vector<int>> adjMatrix(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++)
    {
      adjMatrix[i][i] = 0;
    }
    for (auto edge : edges)
    {
      adjMatrix[edge[0]][edge[1]] = edge[2];
      adjMatrix[edge[1]][edge[0]] = edge[2];
    }
    // distance DP array
    vector<vector<int>> dist(adjMatrix);
    // Floyd Warshall algorithm
    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    // Now we have all pairs shortest paths
    // Find city with least neighbours
    int ans = 0;
    int count = inf;
    for (int i = 0; i < n; i++)
    {
      int currCount = 0;
      for (int j = 0; j < n; j++)
      {
        if (dist[i][j] <= distanceThreshold)
        {
          currCount++;
        }
      }
      if (currCount <= count)
      {
        count = currCount;
        ans = i;
      }
    }
    return ans;
  }
};