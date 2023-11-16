/*
https://leetcode.com/problems/all-paths-from-source-to-target/description/

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int target;
    void helper(int source, vector<vector<int>>&graph, vector<int>& currPath, vector<vector<int>>& ans) {
        currPath.push_back(source);
        if(source == target) {
            vector<int> sub_ans;
            for(auto ele : currPath) {
                sub_ans.push_back(ele);
            }
            ans.push_back(sub_ans);
        }
        for(auto neighbour : graph[source]) {
            helper(neighbour,graph,currPath,ans);
        }
        currPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        vector<int> path;
        vector<vector<int>> ans;
        helper(0,graph,path,ans);
        return ans;
        
    }
};