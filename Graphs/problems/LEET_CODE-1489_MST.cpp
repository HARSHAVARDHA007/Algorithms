/*
https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/

*/
bool comp(vector<int> x, vector<int> y) {
    return x[2] < y[2];
}
class DSU {
    public:
        int n;
        int* parent;
        int* rank;
        // to keep track of total nodes in the connected component
        int count;
    DSU(int n) {
        this->n = n;
        parent = new int[n];
        rank = new int[n];
        count = 1;
        for(int i=0; i<n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    ~DSU() {
        delete[] parent;
        delete[] rank;
    }
    int find(int x) {
        if(parent[x] == -1 ) {
            return x;
        }
        int leader = find(parent[x]);
        parent[x] = leader;
        return leader;
    }
    bool union_set(int x, int y) {
        int p1 = find(x);
        int p2 = find(y);
        if(p1 != p2) {
            count++;
            if(rank[p1] < rank[p2]) {
                parent[p1] = p2;
                rank[p2] += rank[p1];
            } else {
                parent[p2] = p1;
                rank[p1] += rank[p2];
            }
            return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int x = edges.size();
        for(int i=0; i<x; i++) {
            // Append index of the edge to the end of the edge to keep track of index after sorting
            edges[i].push_back(i);
        }
        // sort edges based upon the weight
        sort(edges.begin(), edges.end(), comp);
        // find the original weight of MST 
        DSU du(n);
        int mstWeight = 0;
        for(auto edge : edges) {
            if(du.union_set(edge[0],edge[1])) {
                mstWeight+=edge[2];
            }
        }
        // find the critical egdes
        vector<int> critical, psuedo_critical;
        for(int i=0; i<x; i++) {
            DSU d(n);
            int currWeight =0;
            // remove current edge and find the mst
            int index = edges[i][3];
            for(auto edge : edges) {
                if(edge[3] != index && d.union_set(edge[0],edge[1])) {
                    currWeight+=edge[2];
                }
            }
            // If your new MST weight is greater or cannot form a MST without this edge makes it critical edge
            if(d.count != n || currWeight > mstWeight) {
                critical.push_back(index);
                continue;
            }
            // If the edge is not critical and We get the same weight MST using curr edge then that edge will be an
            // psuedo critical edge
            // find the MST by specifically adding curr edge
            DSU d_pc(n);
            // Add current edge into MST
            currWeight =edges[i][2];
            d_pc.union_set(edges[i][0],edges[i][1]);
            for(auto edge : edges) {
                if(edge[3] != index && d_pc.union_set(edge[0],edge[1])) {
                    currWeight+=edge[2];
                }
            }
            if(d_pc.count == n && currWeight == mstWeight) {
                psuedo_critical.push_back(index);
            }
        }
        return {critical, psuedo_critical};
    }
};