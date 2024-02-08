#include <bits/stdc++.h>
using namespace std;

vector<int> DP;

int setBits(int n)
{
  if (n == 1 || n == 2)
    return 1;

  // recursive case
  if (DP[n / 2] == -1)
  {
    DP[n / 2] == setBits(n / 2);
  }
  return n % 2 == 1 ? DP[n / 2] + 1 : DP[n / 2];
}

int main()
{
  int n;
  cin >> n;
  DP.resize(n + 1, -1);
  for (int i = 1; i <= n; i++)
  {
    DP[i] = setBits(i);
    cout << i << " " << DP[i] << endl;
  }

  return 1;
}