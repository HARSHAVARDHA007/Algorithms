#include <bits/stdc++.h>
using namespace std;

class Graph {
  public:
    int nodes;
    vector<int>* adjList;
    int* indegree;
    vector<int> topo_sort;
  Graph(int nodes) {
    this->nodes = nodes;
    adjList = new vector<int>[nodes];
    indegree = new int[nodes]{0};
  }
  ~Graph() {
    delete[] adjList;
    delete[] indegree;
  }
  void addEdge(int u, int v) {
    adjList[u].push_back(v);
    indegree[v]++;
  }

  void topological_sort() {
    queue<int> q;
    // Add all the non dependent nodes into queue first
    for (int i=0;i<nodes;i++) {
      if(!indegree[i]) {
        q.push(i);
      }
    }
    while(!q.empty()) {
      int curr_node = q.front();
      q.pop();
      topo_sort.push_back(curr_node);
      for(auto it : adjList[curr_node]) {
        indegree[it]--;
        if(!indegree[it]) {
          q.push(it);
        }
      }
    }
  }
};

int main() {
  int nodes,edges;
  cin >> nodes >> edges;
  Graph g = Graph(nodes);
  for(int i=0; i<edges; i++) {
    int x,y;
    cin >> x >> y;
    g.addEdge(x,y);
  }
  g.topological_sort();
  if(g.topo_sort.size() == nodes) {
    cout << "Topologically sorted" << endl;
    for(auto it: g.topo_sort) {
      cout << it << " ";
    }
  } else {
    cout << "Can't Topologically sort, graph is not a DAG";
  }
}