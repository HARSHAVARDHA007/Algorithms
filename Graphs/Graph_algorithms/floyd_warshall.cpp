#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

class Graph
{
public:
  int v;
  vector<vector<int>> adjMatrix;
  Graph(int v)
  {
    this->v = v;
    // resize the adjacency matrix to the v*v and intial value as INF
    adjMatrix.resize(v, vector<int>(v, INF));
  }
  void addEdge(int u, int v, int wt)
  {
    // Populate the edge weights
    adjMatrix[u][v] = wt;
  }

  vector<vector<int>> floyd_warshall()
  {
    // distance array to be returned - D0
    vector<vector<int>> dist(adjMatrix);
    // phases-> distance between i-> j = i->k + k->j
    for (int k = 0; k < v; k++)
    {
      // LOOP over 2D matrix
      for (int i = 0; i < v; i++)
      {
        for (int j = 0; j < v; j++)
        {
          // If we find a better dist[i][j] update that value
          if (dist[i][j] > dist[i][k] + dist[k][j])
          {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }
    return dist;
  }
};

int main()
{
  int v, e;
  cin >> v >> e;
  Graph g(v);
  for (int i = 0; i < e; i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    g.addEdge(u, v, wt);
  }
  auto ans = g.floyd_warshall();
  for (auto row : ans)
  {
    for (auto ele : row)
    {
      cout << ele << " ";
    }
    cout << endl;
  }
}