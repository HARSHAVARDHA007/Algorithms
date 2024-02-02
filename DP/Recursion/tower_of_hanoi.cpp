#include<bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, char from, char helper, char to) {
  if(n==0) return;

  towerOfHanoi(n-1, from, helper, to);
  cout << "Move disk 1 from " << from << " to " << to << endl;
  towerOfHanoi(n-1, helper, to, from);
}

int main() {
  int n;
  cin >>n;
  towerOfHanoi(n, 'A', 'B', 'C');
}