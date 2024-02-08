#include<bits/stdc++.h>
using namespace std;

// Memorization in this question has no use as these are all unique sub problems

vector<vector<int>>DP;
int cnt;

int noConsequetiveOnes(int n, int i, bool previousOne) {
  // Base case
  if(i == n+1) {
    cnt++;
    return 1;
  };
  int subProblem = 0;
  // recursive case
  // placing 0
  subProblem += noConsequetiveOnes(n, i+1, false); 
  // placing 1
  if(!previousOne) {
    subProblem += noConsequetiveOnes(n, i+1, true);
  }

  return subProblem;

}

int noConsequetiveOnes_DP(int n, int i, bool previousOne) {
  // Base case 
  if(i == n+1) {
    cnt++;
    return 1;
  };
  int subProblem = 0;
  // recursive case
  // placing 0
  if(DP[i][0] == -1) {
    subProblem += noConsequetiveOnes(n, i+1, false);
    DP[i][0] = subProblem;
  } else {
    subProblem += DP[i][0];
  }

  if(!previousOne) {
    if(DP[i][1] == -1) {
      DP[i][1] = noConsequetiveOnes(n, i+1, true);
      subProblem +=DP[i][1];
    }
    else {
      subProblem += DP[i][1];
    }
  }

  return subProblem;
}


int main() {
  int n;
  cin >>n;
  DP.resize(n+1,vector<int>(2,-1));
  cnt = 0;
  // Number of ways to fill a array of n with 0,1 where no  two consecutive elements are 1's.
  cout << noConsequetiveOnes(n,1,false)<<endl;
  cout << cnt << endl;
  cnt =0;
  cout << noConsequetiveOnes_DP(n,1,false) << endl;
  cout << cnt << endl;
  return 0;
}