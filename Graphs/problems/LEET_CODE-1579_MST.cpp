class DSU {
    public:
        int nodes;
        int* parent;
        int* rank;
        int count;
    DSU(int nodes) {
        this->nodes = nodes;
        parent = new int[nodes];
        rank = new int[nodes];
        count = 1;
        for(int i=0; i<nodes; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    ~DSU() {
        delete[] parent;
        delete[] rank;
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
        if( p1 != p2) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n+1);
        DSU bob(n+1);
        int removed_edges = 0;
        // Sort the edges based on the type 3 has to come first
        sort(edges.begin(), edges.end(), greater<vector<int>>());
        for(auto edge : edges) {
            if(edge[0] == 3) {
                bool taken_alice = alice.union_set(edge[1],edge[2]);
                bool taken_bob = bob.union_set(edge[1],edge[2]);
                if(!taken_alice && !taken_bob) {
                    removed_edges++;
                }
            }
            else if(edge[0] == 2) {
                bool taken_alice = alice.union_set(edge[1], edge[2]);
                if(!taken_alice) {
                    removed_edges++;
                }
            }
            else if(edge[0] == 1) {
                bool taken_bob = bob.union_set(edge[1],edge[2]);
                if(!taken_bob) {
                    removed_edges++;
                }
            }
        }
        if(alice.count == n && bob.count == n) {
            return removed_edges;
        }
        return -1;
        
    }
};