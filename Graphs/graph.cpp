#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
  int V;
  list<int> *l;
  Graph(int nodes)
  {
    V = nodes;
    l = new list<int>[nodes];
  }
  void addEdge(int i, int j, bool undir = true)
  {
    l[i].push_back(j);
    if (undir)
    {
      l[j].push_back(i);
    }
  }
  void printGraph()
  {
    for (int i = 0; i < V; i++)
    {
      cout << "Node " << i << " --> ";
      for (auto neighbour : l[i])
      {
        cout << neighbour << ",";
      }
      cout << endl;
    }
  }
};

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  // Take input of no of vertices and no of edges
  int vertices, edges;
  cin >> vertices >> edges;
  Graph graph = Graph(vertices);
  for (int i = 0; i < edges; i++)
  {
    int a, b;
    cin >> a >> b;
    graph.addEdge(a, b); // Add edge to the graph
  }
  // Print the added graph
  graph.printGraph();
  return 0;
}