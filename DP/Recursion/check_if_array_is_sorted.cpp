#include <bits/stdc++.h>
using namespace std;
bool checkSort(int *arr, int n, int curr_index)
{
  // Base case
  if (n == 0 || curr_index == n - 1)
    return true;

  if (arr[curr_index] <= arr[curr_index + 1])
  {
    return checkSort(arr, n, curr_index + 1);
  }
  else
  {
    return false;
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  if (checkSort(arr, n, 0))
  {
    cout << "Yes";
  }
  else
    cout << "NO";
  return 0;
}