#include<bits/stdc++.h>
using namespace std;

int Rod_cutting(vector<int>&cost, int n) {
  // table to store the results of subproblems
  vector<int> dp(n+1,0);
  // len=1 max profit is cost[0]
  dp[1]= cost[0];
  for(int i=2; i<=n; i++) {
    int max_val = 0;
    for(int j=0; j<=i/2; j++) {
      max_val = max(max_val, dp[j]+ cost[i-j-1]);
      cout << "i: "<<i<<"j: "<<j<<"max_val: "<<max_val<<endl;
    }
    dp[i] = max_val;
  }
  return dp[n];
}


int main() {
  int n;
  cin >> n;
  vector<int>cost(n);
  for(int  i = 0; i < n; ++i) {
    cin >> cost[i];
  }
  cout << "Minimum cost: "<<Rod_cutting(cost,n) <<endl;
  return 0;


}