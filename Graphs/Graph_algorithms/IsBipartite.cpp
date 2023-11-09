/*
https://leetcode.com/problems/is-graph-bipartite/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool helper(int source, vector<int> &visited, vector<vector<int>> &graph, int color) {
        visited[source] = color;
        for(auto neighbour : graph[source]) {
            if(visited[neighbour] == 0) {
                bool sub_ans = helper(neighbour,visited,graph,3-color);
                if(!sub_ans) return sub_ans;
            }
            else if(visited[neighbour] == color) {
                return false;
            }
        }
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> visited(nodes,0); // 0-unvisited 1-color '1', 2-color '2'
        for(int i=0; i<nodes; i++) {
            if(visited[i]==0) {
                bool sub_ans = helper(i,visited,graph,1);
                if(!sub_ans) return sub_ans;
            }
        }
        return true;
        
    }
};