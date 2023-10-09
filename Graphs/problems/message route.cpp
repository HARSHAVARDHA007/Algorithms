/*
Message Route
There is a network of n computers, each computer is numbered 1 to n.

The computer network is given as an array of edges where edges[i] = [ui, vi] is a bidirectional edge that connects computer ui and computer vi .

Your task is to find if Alice can send a message to Bob, if it is possible, return minimum number of computers on such a route and if it is not possible than return -1.

Alice's Computer is 1 and Bob's computer is  n.

Constraints:

2≤ n ≤10^5

1<= edges.length <= 2*10^5

1<= ui, vi <=n



Expected Time Complexity:  O (n + edges.length)
*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int v;
        list<int> *adjList;
        bool* visited;
    Graph(int V) {
        v = V;
        adjList = new list<int>[V+1];
        visited = new bool[V+1]{false};
    }
    
    void addEdge(int source, int destination) {
        adjList[source].push_back(destination);
        adjList[destination].push_back(source);
    }
    
    int BFS(int destination) {
        // node , distance to reach the node from source
        queue<pair<int,int>>q;
        q.push(make_pair(1,1));
        visited[1] = true;
        while(!q.empty()) {
            auto curr_node = q.front();
            q.pop();
            if(curr_node.first == destination) {
                return curr_node.second;
            }
            for(auto neighbour : adjList[curr_node.first]) {
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(make_pair(neighbour,curr_node.second+1));
                }
            }
        }
        return -1;
        
        
    }
};

int messageRoute(int n, vector<vector<int>>edges)
{
    Graph g = Graph(n);
    for(auto edge : edges) {
        g.addEdge(edge[0],edge[1]);
    }
    return g.BFS(n);
}