#include<bits/stdc++.h>
using namespace std;
class Graph {
  public:
    int v;
    vector<pair<int,int>>* adjList;
    Graph(int v) {
        this->v = v;
        adjList = new vector<pair<int,int>>[v];
    }
    ~Graph() {
        delete[] adjList;
    }
    void addEdge(int x, int y, int weight, int undir = true) {
        adjList[x].push_back({y,weight});
        if(undir) {
            adjList[y].push_back({x,weight});
        }
    }
    
    vector<int> dijkstra_set(int source) {
        vector<int> dist(v,INT_MAX);
        set<pair<int,int>> st;
        // Add the source into the set
        st.insert({0,source});
        dist[source] = 0;
        while(!st.empty()) {
            auto it = st.begin();
            int node = it->second;
            int distTillNow = it->first;
            st.erase(it);
            for(auto nbr : adjList[node]) {
                int nbrNode = nbr.first;
                int edgeWeight = nbr.second;
                if(distTillNow + edgeWeight < dist[nbrNode]) {
                    // we found a better weight shortestPath
                    if(dist[nbrNode] != INT_MAX) {
                        //Already an entry is available in the set have to remove that
                        auto it = st.find({dist[nbrNode],nbrNode});
                        st.erase(it);
                    }
                    dist[nbrNode] = distTillNow + edgeWeight;
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        return dist;
    }
};

vector<int> shortestPath(vector<vector<int>> edges,int n)
{
    Graph g(n+1);
    cout<< n << endl;
    for(auto edge : edges) {
        cout<< edge[0]<<edge[1]<<edge[2]<<endl;
        g.addEdge(edge[0],edge[1],edge[2]);
    }
    return g.dijkstra_set(1);
}