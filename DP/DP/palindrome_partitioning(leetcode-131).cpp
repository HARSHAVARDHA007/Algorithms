#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<string>> ans;
  bool is_palindrome(string s)
  {
    int l = 0, r = s.length() - 1;
    while (l < r)
    {
      if (s[l] != s[r])
        return false;
      l++;
      r--;
    }
    return true;
  }
  void solve(int currIndex, string s, vector<string> &currAns)
  {
    //  Base case
    if (currIndex >= s.length())
    {
      ans.push_back(currAns);
      return;
    }

    // progression
    for (int i = 1; i <= s.length() - currIndex; i++)
    {
      string subStr = s.substr(currIndex, i);
      if (is_palindrome(subStr))
      {
        currAns.push_back(subStr);
        solve(currIndex + i, s, currAns);
        currAns.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s)
  {
    for (int i = 1; i <= s.length(); i++)
    {
      string subStr = s.substr(0, i);
      if (is_palindrome(subStr))
      {
        vector<string> curr_ans;
        curr_ans.push_back(subStr);
        solve(i, s, curr_ans);
      }
    }
    return ans;
  }
};