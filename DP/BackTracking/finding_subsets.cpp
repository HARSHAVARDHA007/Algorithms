#include <bits/stdc++.h>
using namespace std;

void find_subsets(string source, string answer, int index)
{
  // Base case
  if (index == source.length())
  {
    // print the o/p
    cout << answer << endl;
    return;
  }

  // considering adding the curr char to the answer
  answer = answer + source[index];
  find_subsets(source, answer, index + 1);

  //  not considering adding the curr char to the answer
  answer.pop_back();
  find_subsets(source, answer, index + 1);
}

int main()
{
  string s;
  cin >> s;
  int n = s.length();
  find_subsets(s,"",0);
}