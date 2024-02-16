/*
Zonal Computing Olympiad 2014, 30 Nov 2013

In ICO School, all students have to participate regularly in SUPW. There is a different SUPW activity each day, and each activity has its own duration. The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.


Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. The school's rules say that no student can go three days in a row without any SUPW duty.


Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.

10
3 2 1 1 2 3 1 3 2 1


-> output = 4

8
3 2 3 2 3 5 1 3

-> output = 5
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // your code goes here
  int n;
  cin >> n;
  vector<int> duties;
  vector<int> dp(n + 1, 0);
  int ans = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    duties.push_back(val);
    if (i < 3)
    {
      dp[i] = val;
    }
  }
  for (int i = 3; i < n; i++)
  {
    dp[i] = duties[i] + min(dp[i - 1], min(dp[i - 2], dp[i - 3]));
  }
  ans = min({dp[n - 1], dp[n - 2], dp[n - 3]});
  cout << ans;
  return 0;
}