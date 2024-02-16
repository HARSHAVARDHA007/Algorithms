#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int numDecodings(string s)
  {
    int len = s.length();
    vector<int> dp(len + 1, 0);
    if (s[len - 1] == '0')
      dp[len - 1] = 0;
    else
      dp[len - 1] = 1;
    if (len == 1)
      return dp[0];
    int x = stoi(s.substr(len - 2, 2));
    if (s[len - 2] == '0' || (s[len - 1] == '0' && x > 26))
      dp[len - 2] = 0;
    else if ((s[len - 1] == '0' && x < 26) || (s[len - 1] != '0' && x > 26))
      dp[len - 2] = 1;
    else
      dp[len - 2] = 2;
    for (int i = len - 3; i >= 0; i--)
    {
      if (s[i] == '0')
      {
        dp[i] = 0;
        continue;
      }
      else
      {
        dp[i] += dp[i + 1];
      }
      if (stoi(s.substr(i, 2)) >= 10 && stoi(s.substr(i, 2)) <= 26)
      {
        dp[i] += dp[i + 2];
      }
    }
    return dp[0];
  }
};

int main()
{
  cout << Solution().numDecodings("1201234");
  return 0;
}