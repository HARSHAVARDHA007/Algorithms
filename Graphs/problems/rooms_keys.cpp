/*
Keys and Rooms
There are N rooms and you start in room 0. Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room.

Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length. A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0).

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Constraints:

1 <= rooms.length <= 1000

0 <= rooms[i].length <= 1000

The number of keys in all rooms combined is at most 3000.

*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int n;
    vector<vector<int>> adjList;
    bool* visited;
    Graph(int N, vector<vector<int>> rooms) {
        this->n = N;
        adjList = rooms;
        visited = new bool[N]{false};
    }
    
    ~Graph() {
        delete[] visited;
    }
    
    void DFS(int source) {
        visited[source] = true;
        for(auto neighbour : adjList[source]) {
            if(!visited[neighbour]) {
                DFS(neighbour);
            }
        }
        return;
    }
};

bool canVisitAllRooms(vector<vector<int>> rooms) {
    
    int n = rooms.size();
    Graph g = Graph(n,rooms);
    g.DFS(0);
    for(int i=0; i<n; i++) {
        if(!g.visited[i]){
            return false;
        }
    }
    
    return true;
    
}