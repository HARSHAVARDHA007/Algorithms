//problem link:https://codeforces.com/problemset/problem/1037/D
#include<bits/stdc++.h>
using namespace std;

 int* indexes;
 bool comp(int i ,int j) {
    return indexes[i] < indexes[j];
}

class Graph {
    public:
        int v;
        vector<int>* adjList;
        bool* visited;
    Graph(int V) {
        v = V;
        adjList = new vector<int>[V+1];
        visited = new bool[V+1]{false};
    }
    
    void addEdge(int u , int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> BFS() {
        vector<int> ans;
        queue<int> q;
        q.push(1);
        visited[1] = true;
        while(!q.empty()) {
            auto curr_node = q.front();
            ans.push_back(curr_node);
            q.pop();
            for(auto neighbour : adjList[curr_node]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
            
        }
        return ans;
    }
};

bool validBfs(int n, vector<int> sequence , vector<vector<int>> edges)
{
    Graph g  = Graph(n);
    for(auto edge : edges) {
        g.addEdge(edge[0],edge[1]);
    }
    indexes = new int[n+1];
    for(int i=0; i<n;i++) {
        indexes[sequence[i]] = i;
    }
    // Sort the AdjList of the array based up on the ordering of the sequence
    for(int i=1;i<=n;i++) {
        sort(g.adjList[i].begin(), g.adjList[i].end(),comp);
    }
    //sequence
    auto ans = g.BFS();
    for( int i =0 ; i<ans.size();i++) {
        if(ans[i] != sequence[i]) return false;
    }
    delete[] indexes;
    return true;
}