/*

Shortest Cycle in Undirected Graph
Given an undirected unweighted graph of n nodes numbered 0 to n-1.

The graph is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge between node ui and node vi.

Your task is to find the length of the shortest cycle present in the graph.

Return the length of shortest cycle present in the graph, if no cycle exists return -1.

Constraints:

2≤ n ≤1000

1<= edges.length <= min( n*(n-1)/2, 1000)

0<= ui, vi <n

*/

#include<bits/stdc++.h>
using namespace std;
class Graph {
  public:
    int nodes;
    vector<int> *adjList;
    int* pathLength;
    int smallest_cycle_length = INT_MAX;
  Graph(int nodes) {
    this->nodes = nodes;
    adjList = new vector<int>[nodes];
    pathLength = new int[nodes]{INT_MAX};
  }
  ~Graph() {
    delete[] adjList;
    delete[] pathLength;
  }
  void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  void detect_cycle(int source, int parent, int curr_length) {
    pathLength[source] = curr_length;
    for(auto neighbour : adjList[source]) {
      if(neighbour != parent){
        if(pathLength[neighbour] > curr_length + 1) {
          detect_cycle(neighbour, source, curr_length+1);
        } else if( pathLength[neighbour] < curr_length) {
          smallest_cycle_length = min(smallest_cycle_length, curr_length - pathLength[neighbour] +1);
        }
      }
    }


  }

};

int findShortestCycle(int n,vector<vector<int>>& edges) {

  Graph g = Graph(n);
  for(auto edge : edges) {
    g.addEdge(edge[0], edge[1]);
  }
  for(int i=0; i<n;i++) {
    if(g.pathLength[i] == INT_MAX) {
      g.detect_cycle(i,-1,0);
    }
  }
  return g.smallest_cycle_length == INT_MAX ? -1 : g.smallest_cycle_length;

}
