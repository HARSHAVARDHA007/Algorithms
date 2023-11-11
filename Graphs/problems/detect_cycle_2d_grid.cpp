/*
https://leetcode.com/problems/detect-cycles-in-2d-grid/description/
*/
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool helper(int x, int y, vector<vector<char>>&grid,vector<vector<int>>&visited, int pre_x, int pre_y,int length) {
    cout << "helper" << "i: " << x << "j:" << y << endl; 
    visited[x][y] = 1;
    length++;
    
    for(int i=0; i<4;i++) {
        int curr_x = x+dx[i],curr_y = y+dy[i];
        if(curr_x >=0 && curr_x < grid.size() && curr_y >=0 && curr_y < grid[0].size() && grid[x][y] == grid[curr_x][curr_y]) {
            if(!visited[curr_x][curr_y]) {
                bool sub_ans = helper(curr_x,curr_y,grid,visited,x,y,length+1);
                if(sub_ans) {
                    return true;
                }
            } else if(curr_x != pre_x || curr_y != pre_y && length >= 4) {
                return true;
            } 
        
        }
    }
    length--;
    return false;
}

bool containsCycle(vector<vector<char>> grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    for(auto line : grid) {
        for(auto ele : line) {
            cout <<ele << " ";
        }
        cout<<endl;
    }
    cout << rows <<cols <<endl;
    vector<vector<int>> visited(rows, vector<int>(cols,0));
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            cout << i << " " << j << endl;
            if(visited[i][j] == 0) {
                bool sub_cycle = helper(i,j,grid,visited,-1,-1,0);
                if(sub_cycle) return true;
            }
        }
    }
    return false;
    
}