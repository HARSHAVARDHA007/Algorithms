#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
  int v;
  vector<int> *adjList;
  bool *visited;
  Graph(int v)
  {
    this->v = v;
    adjList = new vector<int>[v + 1];
    visited = new bool[v + 1]{false};
  }
  ~Graph()
  {
    delete[] adjList;
    delete[] visited;
  }

  void addEdge(int u, int v)
  {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  // Cycle detectionn using DFS
  bool DFS(int source, int parent)
  {
    visited[source] = true;
    for (auto neighbour : adjList[source])
    {
      if (!visited[neighbour])
      {
        bool cycle = DFS(neighbour, source);
        if (cycle)
        {
          return true;
        }
      }
      // our neighbour is already visited and it is not our parent so cycle
      else if (neighbour != parent)
      {
        return true;
      }
    }
    return false;
  }
  // Cycle detection using BFS
  bool BFS(int source)
  {
    // source, parent
    queue<pair<int, int>> q;
    q.push(make_pair(source, -1));
    visited[source] = true;
    while (!q.empty())
    {
      auto curr = q.front();
      q.pop();
      for (auto neighbour : adjList[curr.first])
      {
        if (!visited[neighbour])
        {
          visited[neighbour] = true;
          q.push(make_pair(neighbour, curr.first));
        }
        else if (neighbour != curr.second)
        {
          return true;
        }
      }
    }
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
      bool cycle = g.DFS(i, -1);
      if (cycle)
      {
        return true;
      }
    }
  }
  return false;
}