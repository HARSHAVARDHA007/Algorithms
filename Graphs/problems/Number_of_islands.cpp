#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int n, m;

    void floodFill(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&  grid[nx][ny] == '1')
            {
                floodFill(grid, nx, ny);
            }
        }
    }

    int numIslands(vector<vector<char>> grid)
    {
        n = grid.size();
        m = grid[0].size();
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    answer++;
                    floodFill(grid, i, j);
                }
            }
        }
        return answer;
    }
};