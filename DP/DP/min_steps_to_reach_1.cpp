#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  int dp[n+1];
  dp[1] = 0;
  for(int i=2;i<=n;i++) {
    int ans1=INT_MAX, ans2= INT_MAX, ans3 = INT_MAX;
    if(i%3==0) ans1 = dp[i/3];
    if(i%2==0) ans2 = dp[i/2];
    ans3 = dp[i-1];
    dp[i] = min({ans1, ans2, ans3})+1;
    cout << dp[i] << " ";
  }
  cout <<endl;
}