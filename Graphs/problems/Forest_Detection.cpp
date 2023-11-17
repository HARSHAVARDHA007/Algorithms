/*
You are given a list of lists edges representing an undirected graph. Each list contains (u, v) which means there is an undirected edge between nodes u and v. Return whether the graph is a collection of trees.

Constraints

n ≤ 100,000 where n is the length of edges

0 <= u, v <=100,000



Example:

Input

edges = [
    [0, 1],
    [0, 2],
    [3, 4],
    [4, 5]
]
Output

true
Explanation

The first two edges form one tree and the last two edges form another tree.

*/
#include<bits/stdc++.h>
using namespace std;

class DSU {
  int parent[100000];
  public:
    DSU() {
        memset(parent,-1,sizeof(parent));
    }
    
    int find(int x) {
        if(parent[x] == -1) {
            return x;
        }
        return find(parent[x]);
    }
    bool union_set(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if( s1 != s2) {
            s1 <= s2 ? parent[s2] = s1 : parent[s1] = s2;
            return true;
        }
        return false;
    }
};

bool solve(vector<vector<int>> edges) {
    DSU d = DSU();
    for(auto edge : edges) {
        if(! d.union_set(edge[0],edge[1])) return false;
    }
    return true;
}