/*

https://leetcode.com/problems/longest-cycle-in-a-graph/

*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  unordered_map<int, int> mp;
  int count;
  int ans = -1;
  void dfs(vector<int> &edges, int curr, int par, vector<int> &visited)
  {
    // This is visited still present in the call stack
    visited[curr] = 1;
    // neighbour of current
    int neighbour = edges[curr];
    if (neighbour != -1)
    {
      if (visited[neighbour] == 0)
      {
        // send the DFS call
        count++;
        dfs(edges, neighbour, curr, visited);
      }
      else if (visited[neighbour] == 1)
      {
        // still in the call stack
        // this accounts for the cycle
        mp[neighbour] = count;
      }
    }
    // when returning back from the dfs call check for the length of the cycle
    if (mp.find(curr) != mp.end())
    {
      int len = mp[curr] - count + 1;
      ans = max(ans, len);
    }
    visited[curr] = 2;
    count--;
  }

  int longestCycle(vector<int> &edges)
  {
    int n = edges.size();
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        // no of elements in the stack
        count++;
        dfs(edges, i, -1, visited);
      }
    }
    return ans;
  }
};