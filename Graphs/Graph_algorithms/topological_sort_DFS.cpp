#include <bits/stdc++.h>
using namespace std;
class Graph {
  public:
    int nodes;
    vector<int>* adjList;
    bool* visited;
    vector<int> topological_sort;
  Graph(int nodes) {
    this->nodes = nodes;
    adjList = new vector<int>[nodes];
    visited = new bool[nodes]{false};
  }
  ~Graph() {
    delete[] adjList;
    delete[] visited;
  }
  void addEdge(int u, int v) {
    adjList[u].push_back(v);
  }

  void DFS(int source) {
    visited[source] = true;
    for (auto i : adjList[source]) {
      if(!visited[i]) {
        DFS(i);
      }
    }
    // Add the edge at the beginning of the topological sort
    topological_sort.insert(topological_sort.begin(), source);
  }
};

int main() {
  int nodes,edges;
  cin >> nodes >>edges;
  Graph g = Graph(nodes);
  for(int i=0; i<edges; i++) {
    int u,v;
    cin >>u >> v;
    g.addEdge(u,v);
  }
  for(int i=0; i<nodes; i++) {
    if(!g.visited[i]) {
      g.DFS(i);
    }
  }
  // Print topological sort
  for(auto ele : g.topological_sort) {
    cout << ele << " ";
  }
  cout <<endl;
  return 0;
}