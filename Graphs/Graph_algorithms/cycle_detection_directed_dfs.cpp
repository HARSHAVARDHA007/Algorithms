#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  int n;
  vector<int> *adjList;
  bool *visited;
  bool *path;
  Graph(int n)
  {
    this->n = n;
    adjList = new vector<int>[n + 1];
    visited = new bool[n + 1]{false};
    path = new bool[n + 1]{false};
  }
  ~Graph()
  {
    delete[] adjList;
    delete[] visited;
    delete[] path;
  }
  void addEdge(int u, int v)
  {
    adjList[u].push_back(v);
  }

  bool cycle_directed(int source)
  {
    visited[source] = true;
    path[source] = true;

    for (auto neighbour : adjList[source])
    {
      if (!visited[neighbour])
      {
        bool cycle = cycle_directed(neighbour);
        if (cycle)
        {
          return true;
        }
      }
      else if (path[neighbour])
      {
        return true;
      }
    }
    path[source] = false;
    return false;
  }
};

bool solve(int n, vector<vector<int>> edges)
{

  Graph g = Graph(n);
  for (auto edge : edges)
  {
    g.addEdge(edge[0], edge[1]);
  }
  for (int i = 1; i <= n; i++)
  {
    if (!g.visited[i])
    {
      bool cycle = g.cycle_directed(i);
      if (cycle)
      {
        return true;
      }
    }
  }
  return false;
}