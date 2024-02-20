#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
  vector<vector<int>> dp;
  int isSubsetSum(vector<int> &nums, int index, int sum)
  {

    // Base case
    if (index == nums.size())
    {
      // this means no elements are left so sum has to be 0 if this has to be true
      return (sum == 0);
    }

    if (dp[index][sum] != -1)
      return dp[index][sum];
    bool ans = false;
    // include the current number
    if (sum >= nums[index])
    {
      // To avoid sum to go -ve
      ans = ans | isSubsetSum(nums, index + 1, sum - nums[index]);
    }
    // exclude the current number
    ans = ans | isSubsetSum(nums, index + 1, sum);
    return dp[index][sum] = ans;
  }

  bool canPartition(vector<int> &nums)
  {
    int n = nums.size();
    int total_sum = 0;
    for (auto ele : nums)
    {
      total_sum += ele;
    }
    if (total_sum % 2 != 0)
      return false;
    total_sum = total_sum / 2;
    dp.resize(n, vector<int>(total_sum + 1, -1));
    // Check if there exsists a sub set with sum equal to the total_sum
    return isSubsetSum(nums, 0, total_sum);
  }
};
