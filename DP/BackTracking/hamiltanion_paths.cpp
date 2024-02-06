#include<bits/stdc++.h>
using namespace std;

class Graph {
  public:
    int n;
    vector<int> *adjList;
    bool* visited;
    vector<vector<int>> answer;
    vector<int> path;
  Graph(int N) {
    this->n = N;
    adjList = new vector<int>[N];
    visited = new bool[N]{false};
  }

  void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  void hamiltonian_path(int cur, int cnt) {
    if (cnt == n) {
      // Base case
      answer.push_back(path);
      return;
    }

    // normal case
    visited[cur] = true;
    path.push_back(cur);
    for(auto neighbour : adjList[cur]) {
      if(!visited[neighbour]) {
        hamiltonian_path(neighbour, cnt+1);
      }
    }
    // Backtrack or undo the work
    visited[cur] = false;
    path.pop_back();
    return;
  }
};

int main() {
  
}