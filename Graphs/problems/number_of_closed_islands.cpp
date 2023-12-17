#include<bits/stdc++.h>
using namespace std;
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void flood_fill(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited) {
  visited[x][y] =1;
  if(grid[x][y] == 2) {
    grid[x][y] = -1;
  }
  for(int i=0; i<4; i++) {
    int newX = x + dx[i];
    int newY = y + dy[i];
    if(newX>=0 && newX < n && newY >=0 && newY < m && grid[newX][newY] == 2 && !visited[newX][newY]) {
      flood_fill(grid, newX, newY, visited);
    }
  }
}

int closedIsland(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      // First row, first col, last row, last col are useless with 0
      if((i==0 || j==0 || i == n-1 || j == m-1 ) && grid[i][j] == 0) {
        grid[i][j] = -1;
      } else {
        int flag = 0;
        for(int k=0; k<4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if(grid[x][y] == -1) {
            flag = 1;
            break;
          }
        }
        // If any of the surroundings is not good then mark as -1.
        if(flag) {
          grid[i][j] = -1;
          vector<vector<int>> visited(n, vector<int>(m,0));
          // if a new -1 is introduced then have to make previous 2 as -1 as well
          flood_fill(grid, i,j,visited);
        }
      }
    }
  }

    
}