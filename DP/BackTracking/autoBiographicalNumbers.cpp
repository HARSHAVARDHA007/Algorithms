#include <bits/stdc++.h>
using namespace std;

bool autoBiographicalNumbers(int digits, int number)
{
  int arr[10] = {0};
  int copy = number;
  while(number) {
    int digit = number%10;
    arr[digit]++;
    number = number/10;
  }
  int generated_number = 0;
  int index = 0;
  for(int i=digits-1; i>=0; i--) {
    generated_number+= arr[index] * pow(10,i);
    index++;
  }
  if(generated_number == copy) return true;
  return false;
}

int main()
{
  int digits;
  cin >> digits;
  vector<int> answer;
  int start = pow(10, (digits - 1));
  int end = pow(10, digits) - 1;
  for (int i = start; i <= end; i++)
  {
    if (autoBiographicalNumbers(digits, i))
    {
      answer.push_back(i);
    }
  }
  for (auto ele : answer)
  {
    cout << ele << endl;
  }
  return 0;
}