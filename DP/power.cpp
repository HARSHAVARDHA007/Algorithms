#include<bits/stdc++.h>
using namespace std;

// generally power function takes o(n) time to calculate
// if we consider a^n = a^n-1 * a

// But we can do that in log(n) time if we consider
// a^n = a^n/2 * a^n/2

int fastPower(int a, int n) {

  if(n == 0) return 1;
  int subProblem = fastPower(a, n/2);
  // if n is even then  (a^(n/2))*(a^(n/2)) will give the answer
  // if n is odd then (a^(n/2))*(a^(n/2))*a will give the answer
  return n%2 == 0 ? subProblem*subProblem : subProblem*subProblem*a;

}