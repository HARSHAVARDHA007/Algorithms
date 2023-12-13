#include<bits/stdc++.h>
using namespace std;
class Graph {
  public:
    int n;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> dp;
  Graph(int n, vector<vector<int>> matrix) {
    this->n = n;
    adjMatrix = matrix;
    // dp[2^N][n]
    dp.resize(1<<n, vector<int>(n,-1));
  }
  int TSP(int visited, int city) {
    // Base case, checking if all the bits in the visited are equal to 1
    if(visited == (1<<n) -1) {
      // we return distance from last city to source
      return adjMatrix[city][0];
    }
    if(dp[visited][city] != -1) {
      return dp[visited][city];
    }
    // Explore all possible combinations
    int currCost = INT_MAX;
    for(int nextCity=0; nextCity<n; nextCity++) {
      //If the bit corresponing to nextCity is not set in visited make a recursive call
      if((visited & (1<<nextCity))==0) {
        // Set the nextCity bit as 1 and make recursive call
        int subCost = adjMatrix[city][nextCity] + TSP(visited | (1<<nextCity), nextCity);
        // Return minimum of including or excluding nextCity
        currCost = min(subCost, currCost);
      }
    }
    dp[visited][city] = currCost;
    return currCost;
  }
};