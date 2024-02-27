#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

bool subsetSumRepeating(int index, vector<int> &nums, int target)
{
  // Base case
  if (index == nums.size())
  {
    return (target == 0);
  }

  // DP case
  if (dp[index][target] != -1)
    return dp[index][target];
  // Progression
  // case include multiple times
  int ans = false;
  if (target >= nums[index])
  {
    ans = ans | subsetSumRepeating(index, nums, target - nums[index]);
  }
  // case don't include
  ans = ans | subsetSumRepeating(index + 1, nums, target);

  return dp[index][target] = ans;
}

int main()
{
  int n, sum;
  cin >> n >> sum;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  dp.resize(n, vector<int>(sum + 1, -1));
  cout << subsetSumRepeating(0, nums, sum) << endl;
  return 0;
}