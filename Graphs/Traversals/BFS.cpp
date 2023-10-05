#include <bits/stdc++.h>
using namespace std;

class Graph {
  public:
  int V;
  list<int>* adjList;
  Graph(int v) {
    V = v;
    adjList = new list<int>[V];
  }

  void addEdge(int u, int v, bool undir = true) {
    adjList[u].push_back(v);
    if(undir) {
      adjList[v].push_back(u);
    }
  }

  vector<int> BFS(int source) {
    vector<int> bfs;
    vector<bool>visited(V,false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while(!q.empty()) {
      // Get the first node from queue
      int curr_node = q.front();
      bfs.push_back(curr_node);
      q.pop();
      // Push neighbours into queue
      for( auto neighbour : adjList[curr_node]) {
        if(!visited[neighbour]) {
          visited[neighbour] = true;
          q.push(neighbour);
        }
      }
    }
    return bfs;

  }

};

int main() {

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
int v,e;
cin >>v>>e;
Graph g = Graph(v);
for(int i =0; i<e; i++) {
  int x,y;
  cin >> x>> y;
  g.addEdge(x,y);
}

vector<int> bfs = g.BFS(5);
for(auto node : bfs) {
  cout << node << "-> ";
}
cout << endl;
return 0;

}