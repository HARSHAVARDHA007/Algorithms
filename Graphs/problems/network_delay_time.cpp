/*
   Leet Code 743 
   : https://leetcode.com/problems/network-delay-time/description/
*/

class Graph {
    public:
        int v;
        vector<pair<int,int>> *adjList;
    Graph(int v) {
        this->v = v;
        adjList = new vector<pair<int,int>>[v];
    }
    ~Graph() {
        delete[] adjList;
    }
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v,w});
    }
    int Dijkstra(int source) {
        vector<int> dist(v,INT_MAX);
        // Declare a min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // push the source 
        pq.push({0, source});
        dist[source] = 0;
        while(!pq.empty()) {
            // Take the current node 
            auto curr = pq.top();
            int node = curr.second;
            int distTillNow = curr.first;
            pq.pop();
            for(auto adj : adjList[node]) {
                int nbr = adj.first;
                int edgeWeight = adj.second;
                if(distTillNow + edgeWeight < dist[nbr]) {
                    dist[nbr] = distTillNow + edgeWeight;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return *max_element(dist.begin()+1, dist.end());
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph g(n+1);
        for(auto edge : times) {
            g.addEdge(edge[0],edge[1],edge[2]);
        }
        int ans = g.Dijkstra(k);
        return ans == INT_MAX ? -1 : ans;   
    }
};