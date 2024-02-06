#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  int n;
  vector<int> *adjList;
  bool *visited;
  vector<vector<int>> answer;
  vector<int> path;
  Graph(int N)
  {
    this->n = N;
    adjList = new vector<int>[N];
    visited = new bool[N]{false};
  }

  void addEdge(int u, int v)
  {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  void hamiltonian_path(int cur, int cnt)
  {
    if (cnt == n)
    {
      // Base case
      answer.push_back(path);
      return;
    }

    // normal case
    visited[cur] = true;
    path.push_back(cur);
    for (auto neighbour : adjList[cur])
    {
      if (!visited[neighbour])
      {
        hamiltonian_path(neighbour, cnt + 1);
      }
    }
    // Backtrack or undo the work
    visited[cur] = false;
    path.pop_back();
    return;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  Graph g = Graph(n);
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    g.addEdge(x, y);
  }
  for (int i = 0; i < n; i++)
  {
    g.hamiltonian_path(i, 1);
  }
  // after finding hamiltonian paths from all the nodes
  for (auto path : g.answer)
  {
    for (auto ele : path)
    {
      cout << ele << " -> ";
    }
    cout << endl;
  }
  return 0;
}