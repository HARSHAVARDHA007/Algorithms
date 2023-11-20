#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:
        int nodes;
        int* rank;
        int* parent;
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
        // Make all the nodes in the path attach directly to the leader of the group
        int leader = find(parent[x]);
        parent[x] = leader;
        return leader;
    }
    bool union_set(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if( p1 == p2) {
            return false;
        }
        // Attach Smaller tree as the child of the Bigger Tree
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
