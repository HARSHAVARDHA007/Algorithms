/*
https://leetcode.com/problems/cheapest-flights-within-k-stops/
*/
#include<bits/stdc++.h>
using namespace std;
#define inf 100000
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
  void addEdge(vector<int> edge) {
    adjList[edge[0]].push_back({edge[1],edge[2]});
  }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,inf);
        Graph g = Graph(n);
        for(auto flight : flights) {
          g.addEdge(flight);
        }
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        // stops, node, distance_taken_to_reach_that_node
        q.push({0,{src,0}});
        while(!q.empty()) {
          auto entry = q.front();
          q.pop();
          int stops = entry.first;
          int currNode = entry.second.first;
          int currWeight = entry.second.second;
          for(auto nbrNode : g.adjList[currNode]) {
            int nbr = nbrNode.first;
            int edgeWeight = nbrNode.second;
            // Travese the edges of the neighbour within k stops or k+1th stop should be the destination
            if((stops < k || (stops == k && nbr == dst)) && currWeight + edgeWeight < dist[nbr]) {
              dist[nbr] = currWeight + edgeWeight;
              q.push({stops+1,{nbr,dist[nbr]}});
            }
          }

        }
        return dist[dst] != inf ? dist[dst] : -1;
        
    }
};