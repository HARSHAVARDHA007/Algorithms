/*
https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

*/

#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:
        int nodes;
        int* rank;
        int* parent;
        int extra_edges = 0;
    DSU(int nodes) {
        this-> nodes = nodes;
        rank = new int[nodes]{1};
        parent = new int[nodes];
        for(int i=0; i<nodes; i++) {
            rank[i] = 1;
            parent[i] = -1;
        }
    }
    ~DSU() {
        delete[] rank;
        delete[] parent;
    }
    
    int find(int x) {
        if(parent[x] == -1) {
            return x;
        }
        int leader = find(parent[x]);
        parent[x] = leader;
        return leader;
    }
    bool union_set(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if( p1 == p2) {
            extra_edges++;
            return false;
        }
        if(rank[p1] < rank[p2]) {
            parent[p1] = p2;
            rank[p2]+= rank[p1];
        } else {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        return true;
    }
};

int makeConnected(int n, vector<vector<int>> connections) {
    DSU d = DSU(n);
    int unconnected = -1; // one parent will be leader
    for(auto connection : connections) {
        d.union_set(connection[0],connection[1]);
    }
    for(int i=0; i<n; i++) {
        if(d.parent[i] == -1 ) {
            unconnected++;
        }
    }
    return d.extra_edges >= unconnected ? unconnected : -1;
    
}