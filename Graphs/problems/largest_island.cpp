/*
problem link : https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1

*/

#include<bits/stdc++.h>
using namespace std;
class Graph {
    public:
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    int connected = 0;
    int rows, columns;
    vector<vector<int>> visited;
    vector<vector<int>> grid;
    Graph(int n, int m, vector<vector<int>> grid) {
        visited.resize(n);
        for(int i=0; i<n; i++) {
            visited[i].resize(m);
        }
        rows = n;
        columns = m;
        this->grid = grid;
    }
    
    void DFS(int x, int y) {
        visited[x][y] = 1;
        for(int i=0; i<8; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x >=0 && new_x < rows && new_y >=0 && new_y < columns && !visited[new_x][new_y] && grid[new_x][new_y] == 1 ) {
                connected++;
                DFS(new_x, new_y);
            }
        }
    }
    
};

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size(), ans = 0;
        Graph g = Graph(n,m,grid);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!g.visited[i][j] && g.grid[i][j]==1) {
                    g.connected = 1;
                    g.DFS(i,j);
                    ans = max(ans,g.connected);
                }
            }
        }
        return ans;
    }
};