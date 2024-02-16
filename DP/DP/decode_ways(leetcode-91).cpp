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

// BEst solution
class Solution_1 {
 public:
  int numDecodings(string s) {
    const int n = s.length();
    // dp[i] := the number of ways to decode s[i..n)
    vector<int> dp(n + 1);
    dp[n] = 1;  // ""
    dp[n - 1] = isValid(s[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      if (isValid(s[i]))
        dp[i] += dp[i + 1];
      if (isValid(s[i], s[i + 1]))
        dp[i] += dp[i + 2];
    }

    return dp[0];
  }

 private:
  bool isValid(char c) {
    return c != '0';
  }

  bool isValid(char c1, char c2) {
    return c1 == '1' || c1 == '2' && c2 < '7';
  }
};