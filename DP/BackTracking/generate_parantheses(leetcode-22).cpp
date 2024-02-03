#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(vector<string> &answer, string currStr, int n, int openCount, int closeCount)
    {
        // Base case
        if (openCount + closeCount == 2 * n)
        {
            answer.push_back(currStr);
            return;
        }

        // case-1 take '(' when opening count is less than n
        if (openCount < n)
        {
            currStr += '(';
            helper(answer, currStr, n, openCount + 1, closeCount);
            currStr.pop_back();
        }
        // case-2  we can take ')' when count of closing is less than opening
        if (closeCount < openCount)
        {
            currStr += ')';
            helper(answer, currStr, n, openCount, closeCount + 1);
            currStr.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {

        vector<string> answer;
        string currStr = "";
        helper(answer, currStr, n, 0, 0);
        return answer;
    }
};