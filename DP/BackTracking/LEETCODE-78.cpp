#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& answer,vector<int>& nums, vector<int>& subset, int index, int n ) {
        if(index == n) {
            answer.push_back(subset);
            return;
        }
        // insert the current element
        subset.push_back(nums[index]);
        helper(answer, nums,subset, index+1,n);

        // undo the work and use another option
        subset.pop_back();
        helper(answer, nums,subset, index+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> subset;
        int n = nums.size();
        helper(answer,nums,subset,0,n);
        return answer;
        
    }
};