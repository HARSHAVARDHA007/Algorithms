#include<bits/stdc++.h>
using namespace std;
class DISJOINTSET {
    int parent[10] = {-1};
    public:
    DISJOINTSET() {
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
        if(s1 != s2) {
            s1 <= s2 ? parent[s2] = s1 : parent[s1] = s2;
            return true;
        }
        return false;
    }
};
vector<bool> DSU(vector<vector<int>>queries)
{
    DISJOINTSET d = DISJOINTSET();
    vector<bool> ans;
    for(auto query : queries) {
        int q = query[0];
        int x = query[1];
        int y = query[2];
        if(q == 1) {
            d.union_set(x,y);
        }
        if(q == 2) {
            int p1 = d.find(x);
            int p2 = d.find(y);
            p1 == p2 ? ans.push_back(true) : ans.push_back(false);
        }
    }
    return ans;
}