/*
https://leetcode.com/problems/course-schedule/description/
*/
#include<bits/stdc++.h>
using namespace std;
class Graph {
    public:
        int v;
        vector<int>* adjList;
        bool* visited;
        bool* curr_path;
    Graph(int v) {
        this->v = v;
        adjList = new vector<int>[v];
        visited = new bool[v]{false};
        curr_path = new bool[v]{false};
    }
    ~Graph() {
        delete[] adjList;
        delete[] visited;
        delete[] curr_path;
    }
    void addEdge(int x, int y) {
        adjList[x].push_back(y);
    }
    
    bool Schedule(int source) {
        visited[source] = true;
        curr_path[source] = true;
        for(auto neighbour : adjList[source]) {
            if(!visited[neighbour]) {
                bool cycle = Schedule(neighbour);
                if(cycle) return true;
            }
            else if(curr_path[neighbour]) return true;
        }
        curr_path[source]= false;
        return false;
    }
    
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g = Graph(numCourses);
        for(auto edge : prerequisites) {
            g.addEdge(edge[0], edge[1]);
        }
        for(int i=0; i<numCourses; i++) {
            if(!g.visited[i]) {
                bool cycle = g.Schedule(i);
                if(cycle) return false;
            }
        }
        return true;
    }
};