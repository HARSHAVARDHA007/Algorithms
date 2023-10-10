#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  int v;
  vector<int> *adjList;
  bool *visited;
  vector<int> dfs_store;

  Graph(int V)
  {
    this->v = V;
    adjList = new vector<int>[V];
    visited = new bool[V];
  }

  ~Graph()
  {
    delete[] adjList;
    delete[] visited;
  }

  void addEdge(int u, int v, bool undir = true)
  {
    adjList[u].push_back(v);
    if (undir)
    {
      adjList[v].push_back(u);
    }
  }

  void dfs(int node)
  {
    visited[node] = true;
    dfs_store.push_back(node);
    for (auto neighbour : adjList[node])
    {
      if (!visited[neighbour])
      {
        dfs(neighbour);
      }
    }
    return;
  }
};

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int vertices, edges;
  cin >> vertices >> edges;
  Graph g = Graph(vertices);

  for (int i = 0; i < edges; i++)
  {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v);
  }

  int source;
  cin >> source;
  g.dfs(source);
  for (auto ele : g.dfs_store)
  {
    cout << ele << "-";
  }
  cout << endl;
  return 0;
}