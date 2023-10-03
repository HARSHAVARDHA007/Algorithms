#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  string city;
  list<Node *> nbrs;
  Node(string name)
  {
    city = name;
  }
};

class Graph
{
public:
  map<string, Node *> m;
  Graph(vector<string> cities)
  {
    for (auto city : cities)
    {
      m[city] = new Node(city);
    }
  }

  void addEdge(string x, string y, bool undir = false)
  {
    m[x]->nbrs.push_back(m[y]);
    if (undir)
    {
      m[y]->nbrs.push_back(m[x]);
    }
  }

  void printGraph()
  {
    // All nodes are in map
    for (auto cityPair : m)
    {
      string city = cityPair.first;
      cout << city << " --> ";
      for (auto neighbour : cityPair.second->nbrs)
      {
        cout << neighbour->city << ",";
      }
      cout << endl;
    }
  }
};

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  vector<string> cities;
  int vertices, edges;
  cin >> vertices >> edges;
  for (int i = 0; i < vertices; i++)
  {
    string city;
    cin >> city;
    cities.push_back(city);
  }
  Graph graph = Graph(cities);
  // Take edges Input and add edges
  for (int i = 0; i < edges; i++)
  {
    string city1, city2;
    cin >> city1 >> city2;
    graph.addEdge(city1, city2);
  }
  graph.printGraph();
  return 0;
}