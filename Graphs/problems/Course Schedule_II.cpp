/*
https://leetcode.com/problems/course-schedule-ii/
*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
  public:
    int nodes;
    vector<int>* adjList;
    int* indegree;
    vector<int> topo_sort;
  Graph(int nodes) {
    this->nodes = nodes;
    adjList = new vector<int>[nodes];
    indegree = new int[nodes]{0};
  }
  ~Graph() {
    delete[] adjList;
    delete[] indegree;
  }
  void addEdge(int u, int v) {
    adjList[u].push_back(v);
    indegree[v]++;
  }

  void topological_sort() {
    queue<int> q;
    // Add all the non dependent nodes into queue first
    for (int i=0;i<nodes;i++) {
      if(indegree[i] == 0) {
        q.push(i);
      }
    }
    while(!q.empty()) {
      int curr_node = q.front();
      q.pop();
      topo_sort.push_back(curr_node);
      for(auto it : adjList[curr_node]) {
        indegree[it]--;
        if(indegree[it] == 0) {
          q.push(it);
        }
      }
    }
  }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        Graph g = Graph(numCourses);
        for(auto edge : prerequisites) {
            g.addEdge(edge[1],edge[0]);
        }
        g.topological_sort();
        return g.topo_sort.size() == numCourses ? g.topo_sort : ans; 
    }
};