// Prims algorithm used for finding minimum spanning tree.
// Applicable only for weighted undirected graph
// Greedy algorithm
// O(V* logV^2)
#include<iostream>
#include<vector>
#include <queue>
using namespace std;

class Graph {
  public:
    int nodes;
    // {neighbour, edgeweight}
    vector<pair<int,int>> *adjList;
  Graph(int nodes) {
    this->nodes = nodes;
    adjList = new vector<pair<int,int>>[nodes];
  }
  ~Graph() {
    delete[] adjList;
  }
  void addEdge(int x, int y, int weight) {
    adjList[x].push_back({y,weight});
    adjList[y].push_back({x,weight});
  }

  int prims(int source) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    bool* visited = new bool[nodes]{0};
    int ans =0;
    
    // Add the source to the priority queue - {weight, node}
    Q.push({source,0});
    
    while(!Q.empty()) {
      // Take the top element
      auto best = Q.top();
      Q.pop();
      int next_edge = best.second;
      int weight = best.first;

      if(visited[next_edge]) {
        // discard this edge as the other node is also already attached to the MST
        continue;
      }
      // If not add the edge weight to ans
      ans+=weight;
      for(auto neighbour : adjList[next_edge]) {
        if(!visited[neighbour.first]) {
          // if this node is not already attached to the MST
          // {Weight,node}
          Q.push({neighbour.second,neighbour.first});
        }
      }
    }
  // return the total sum of the edges of the MST
    return ans;
  }


};