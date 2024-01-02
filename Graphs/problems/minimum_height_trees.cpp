#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int n;
    vector<int> *adjList;
    vector<int> degree;
    vector<bool> visited;
    Graph(int n)
    {
        this->n = n;
        adjList = new vector<int>[n];
        degree.resize(n);
        visited.assign(n, false);
    }
    ~Graph()
    {
        delete[] adjList;
    }
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
};

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 0)
            return {};
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};
        Graph g = Graph(n);
        for (auto edge : edges)
        {
            g.addEdge(edge[0], edge[1]);
        }
        // add all the leaves into queue
        queue<int> q;
        vector<int> res;
        int count = n;
        for (int i = 0; i < n; i++)
        {
            if (g.degree[i] == 1)
            {
                g.degree[i]--;
                q.push(i);
            }
        }
        while (count)
        {
            if (count <= 2)
            {
                return res;
            }
            for (auto ele : res)
            {
                q.push(ele);
            }
            res.clear();
            // relax all nodes at each level
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                count--;
                for (auto neighbour : g.adjList[curr])
                {
                    g.degree[neighbour]--;
                    if (g.degree[neighbour] == 1)
                    {
                        res.push_back(neighbour);
                    }
                }
            }
        }
        return res;
    }
};