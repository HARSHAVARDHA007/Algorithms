#include<bits/stdc++.h>
using namespace std;

class Graph {
  public:
    int V;
    // {u,v,wt}
    vector<vector<int>> edges;
  Graph(int V) {
    this->V = V;
  }
  void addEdge(int u, int v, int wt) {
    edges.push_back({u,v,wt});
  }
  vector<int> bellman_ford(int src) {
    // output vector
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    // relax edges v-1 times
    for(int i=0; i<V-1; i++) {
      for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        // Added check to avoid overflow
        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
          dist[v] = dist[u]+wt;
        }
      }
    }
    // Detect the -ve wt cycle 
    for(auto edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int wt = edge[2];
      // Added check to avoid overflow
      if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
        cout << " -VE weight cycle detected, cant find the shortest distances to this graph" << endl;
        exit(0);
      }
    }
    return dist;
  }
};