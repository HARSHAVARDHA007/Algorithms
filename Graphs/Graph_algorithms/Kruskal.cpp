#include<bits/stdc++.h>
using namespace std;

// Custom Comparator
bool comp(pair<pair<int,int>,int> x, pair<pair<int,int>,int> y ) {
  return x.second < y.second;
}

class DSU {
  public:
    int nodes;
    int* parent;
    int* rank;
  DSU(int nodes) {
    this->nodes = nodes;
    parent = new int[nodes];
    rank = new int[nodes];
    for(int i=0; i<nodes; i++) {
      parent[i] = -1;
      rank[i] = 1;
    }
  }
  ~DSU() {
    delete[] parent;
    delete[] rank;
  }

  int find(int x) {
    if(parent[x] == -1) {
      return x;
    }
    int leader = find(parent[x]);
    parent[x] = leader;
    return leader;
  }

  bool union_set(int x, int y) {
    int p1 = find(x);
    int p2 = find(y);
    if(p1 != p2) {
      if(rank[p1] < rank[p2]) {
        parent[p1] = p2;
        rank[p2] = rank[p2] + rank[p1];
      } else{
        parent[p2] = p1;
        rank[p1] = rank[p1] + rank[p2];
      }
      return true;
    }
    return false;
  }

};

class Graph {
  public:
    int nodes;
    vector<pair<pair<int,int>,int>> edgeList;

  Graph(int nodes) {
    this->nodes = nodes;
  }

  void addEdge(int x, int y, int weight) {
    edgeList.push_back({{x,y},weight});
  }

  int kruskal() {
    // Create a DSU to detect the cycle
    DSU d(nodes);
    // sort the edges of the edgeList based upon the edgeWeight
    sort(edgeList.begin(), edgeList.end(), comp);
    int ans=0;
    // Algo Logic
    for(auto edge : edgeList) {
      bool consider = d.union_set(edge.first.first,edge.first.second);
      // If do not form a cycle add that to the MST
      if(consider) {
        ans+=edge.second;
        if(edge.first.first < edge.first.second) {
          cout << edge.first.first << " " << edge.first.second << " " << edge.second << endl;
        } else {
          cout << edge.first.second << " " << edge.first.first << " " << edge.second << endl;
        }
      }
    }
    return ans;
  }
};

int main() {
  int nodes,edges;
  cin >> nodes >>edges;
  Graph g(nodes);
  for(int i=0; i<edges; i++){
    int x,y,z;
    cin >> x >> y>> z;
    g.addEdge(x, y, z);
  }
  cout << g.kruskal();
  return 0;
}
