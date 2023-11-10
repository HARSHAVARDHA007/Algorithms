/*
Given an undirected graph as an adjacency list, return whether the graph has an odd length cycle.

Constraints:

n, m ≤ 250 where n and m are the number of rows and columns in graph

Input

graph = [
    [1, 2, 3],
    [0, 2],
    [0, 1, 3],
    [0, 2]
]
Output

true
Explanation

One odd length cycle would be 0 -> 2 -> 1 -> 0



Expected  Time Complexity: O(n+m)


*/
#include<bits/stdc++.h>
using namespace std;
bool dfs(int source, vector<vector<int>>&graph, vector<int>&visited, int color) {
    visited[source] = color;
    for(auto neighbour : graph[source]) {
        if(visited[neighbour] == 0) {
            bool sub_prob = dfs(neighbour, graph, visited, 3-color);
            if(sub_prob) return true;
        } else if(visited[neighbour] == color) return true;
    }
    return false;
    
}

bool solve(vector<vector<int>> graph)
{
    int nodes = graph.size();
    vector<int> visited(nodes, 0);
    for(int i=0; i<nodes; i++) {
        if(visited[i]==0) {
            bool sub_prob = dfs(i, graph, visited, 1);
            if(sub_prob) return true;
            
        }
    }
    return false;
    
}