/*

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.



Sample Test Case :



Example 1:



Input:

edges = {{1,2},{1,3},{2,3}}

Output:

{2,3}



Example 2:



Input:

edges = {{1,2},{2,3},{3,4},{1,4},{1,5}}

Output:

{1,4}



Constraints:

n == edges.length

3 <= n <= 1000

edges[i].length == 2

1 <= ai < bi <= edges.length

ai != bi

There are no repeated edges.

The given graph is connected.

Expected Time Complexity: O( n+m ), where m is the number of edges

*/



#include<bits/stdc++.h>
using namespace std;

class DSU {
    int parent[1000];
    public:
        DSU() {
            memset(parent,-1,sizeof(parent));
        }
        int find(int x) {
            if(parent[x] == -1 ) return x;
            return find(parent[x]);
        }
        bool union_set(int x, int y) {
            int s1 = find(x);
            int s2 = find(y);
            if(s1 != s2) {
                s1 <= s2 ? parent[s2] = s1 : parent[s1] = s2;
                return true;
            }
            return false;
        }
};

vector<int> findUselessConnection(vector<vector<int>> edges) {
        vector<int> ans;
        int last_x , last_y;
        DSU d = DSU();
        for(auto edge : edges) {
            // If union_set fails for an edge that means it is the edge thats makes graph into a cycle.
            if(!d.union_set(edge[0],edge[1])) {
                last_x = edge[0];
                last_y = edge[1];
            }
        }
        ans.push_back(last_x);
        ans.push_back(last_y);
        return ans;
}