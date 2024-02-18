#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  // int n;
  // vector<int> dp;
  // int helper(vector<int>& nums, int i) {
  //     if(i >= n) return 0;
  //     if(dp[i] != -1) return dp[i];
  //     return dp[i] = max(nums[i] + helper(nums,i+2), helper(nums, i+1));
  // }
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);
    for (int i = 2; i < n; i++)
    {
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[n - 1];
    // return helper(nums,0);
  }
};