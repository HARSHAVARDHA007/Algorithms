/*

Build Roads
There are N towns on a plane. The i-th town is located at the coordinates (xi,yi)(xi,yi). There may be more than one town at the same coordinates.

You can build a road between two towns at coordinates (a,b)(a,b) and (c,d)(c,d) for a cost of min(|a−c|,|b−d|)min(|a−c|,|b−d|). It is not possible to build other types of roads.

Your objective is to build roads so that it will be possible to travel between every pair of towns by traversing roads. At least how much cost is necessary to achieve this?

Constraints

2≤ N ≤10^5

0≤ xi,yi ≤10 ^ 9  0≤ xi,yi ≤10^9

All input values are integers.

Input  : N = 6, Cordinates : {{8,3},{4,9},{12,19},{18,1},{13,5},{7,6}}
Output : 8

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {
    public:
        int nodes;
        // {neighbour,
        vector<pair<ll,ll>>* adjList;
        bool* visited;
    Graph(int n) {
        nodes = n;
        adjList = new vector<pair<ll,ll>>[nodes];
        visited = new bool[nodes]{0};
    }
    ~Graph() {
        delete[] adjList;
        delete[] visited;
    }
    
    void addEdge(int x, int y, ll weight) {
        adjList[x].push_back({y,weight});
        adjList[y].push_back({x,weight});
    }
    
    ll Prims() {
        // use priority queue to get the edge with least weight everytime
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
        ll answer = 0;
        //{weight,neighbour}
        pq.push({0,0});
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            ll neighbour = curr.second;
            ll weight = curr.first;
            // if the neighbour is already visited discard that edge
            if(visited[neighbour]) {
                continue;
            }
            answer= answer + weight;
            cout << answer << endl;
            visited[neighbour] = true;
            // Add all the edges with the neighbour as starting node
            for(auto edge : adjList[neighbour]) {
                if(!visited[edge.first]) {
                    pq.push({edge.second,edge.first});
                }
            }
        }
        return answer;
    }
    
};

long long buildRoads(vector<vector<long long>>Coordinates){
    int n = Coordinates.size();
    Graph g(n);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ll weight = min(abs(Coordinates[i][0]-Coordinates[j][0]), abs(Coordinates[i][1]-Coordinates[j][1]));
            g.addEdge(i,j,weight);
        }
    }
    return g.Prims();
    
}