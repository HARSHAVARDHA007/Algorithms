#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  int V;
  list<int> *adjList;
  Graph(int v)
  {
    V = v;
    adjList = new list<int>[V];
  }
  void addEdge(int x, int y, bool undir = true)
  {
    adjList[x].push_back(y);
    if (undir)
    {
      adjList[y].push_back(x);
    }
  }

  vector<pair<int, int>> BFS(int source, int dest = -1)
  {
    bool *visited = new bool[V]{false};
    // {node , shortest length from that node to that source}
    vector<pair<int, int>> bfs;
    queue<pair<int, int>> q;
    q.push({source, 0});
    visited[source] = true;
    while (!q.empty())
    {
      // Get the current node
      pair<int, int> curr_node = q.front();
      bfs.push_back({curr_node.first, curr_node.second});
      q.pop();
      for (auto neighbour : adjList[curr_node.first])
      {
        if (!visited[neighbour])
        {
          q.push({neighbour, curr_node.second + 1});
          visited[neighbour] = true;
        }
      }
    }
     return bfs;
  }
};

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int v, e;
  cin >> v >> e;
  Graph g = Graph(v);
  for (int i = 0; i < e; i++)
  {
    int x, y;
    cin >> x >> y;
    g.addEdge(x, y);
  }

  vector<pair<int,int>> bfs = g.BFS(0);
  for (auto node : bfs)
  {
    cout << "Node is " << node.first << " Shortest distance from source is " << node.second <<endl;
  }
  cout << endl;
  return 0;
}