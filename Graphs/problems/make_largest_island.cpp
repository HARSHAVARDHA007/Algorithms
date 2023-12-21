/*

https://leetcode.com/problems/making-a-large-island/

*/
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000
class Solution {
public:
    int col_cnt[inf];
    int rows, cols;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    void colorGraph(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &visited, int color)
    {
        visited[x][y] = 1;
        grid[x][y] = color;
        col_cnt[color]++;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && !visited[nx][ny] && grid[nx][ny] == 1)
            {
                colorGraph(nx, ny, grid, visited, color);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        col_cnt[0] = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int currColor = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    colorGraph(i, j, grid, visited, currColor);
                    currColor++;
                }
            }
        }
        // Find current largest island
        int largestIsland = 0;
        for (int i = 1; i < currColor; i++)
        {
            largestIsland = max(largestIsland, col_cnt[i]);
        }
        // Iterate through the grid and try to replace each 0 with 1
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 0) {
                    int currAns = 1;
                    //Find the distinct colors in the neighbours
                    set<int> st;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols)
                        {
                            st.insert(grid[nx][ny]);
                        }
                    }
                    // now we have all distinct colors, find size of adjacent components
                    for(auto val : st) {
                        currAns = currAns + col_cnt[val];
                    }
                    largestIsland = max(largestIsland, currAns);
                }
            }
        }
        return largestIsland;
    }
};