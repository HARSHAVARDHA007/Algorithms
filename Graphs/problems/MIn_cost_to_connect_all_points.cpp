/*
https://leetcode.com/problems/min-cost-to-connect-all-points/

*/
class Graph {
    public:
        int nodes;
        vector<pair<int,int>>* adjList;
        bool *visited;
    Graph(int nodes) {
        this->nodes = nodes;
        adjList = new vector<pair<int,int>>[nodes];
        visited = new bool[nodes]{0};
    }
    ~Graph() {
        delete[] adjList;
    }
    void addEdge(int x, int y, int weight) {
        adjList[x].push_back({y,weight});
        adjList[y].push_back({x,weight});
    }
    int prims() {
        int ans=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()) {
            // take out the top element in priority queue;
            auto node = pq.top();
            pq.pop();
            int to = node.second;
            int weight = node.first;
            if(visited[to]) {
                // if second vertex of the edge is visited then discard
                continue;
            }
            //take this edge
            visited[to] = true;
            ans+=weight;
            // add all the neighbours of the edges to the pq
            for(auto edge : adjList[to]) {
                if(!visited[edge.first]) {
                    //If this neighbour vertex is not already in MST
                    // {weight,node}
                    pq.push({edge.second,edge.first});
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        Graph g(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int weight = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                g.addEdge(i,j,weight);
            }
        }
        return g.prims();
    }
};