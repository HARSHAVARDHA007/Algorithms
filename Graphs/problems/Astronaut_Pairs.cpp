/*
The member states of the UN are planning to send people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

Example

n = 4

astronauts = [1,2] [2,3]

There are 4 astronauts numbered 0 through 3. Astonauts grouped by country are [0] and [1,2,3]. There are 3 pairs to choose from [0,1], [0,2] and [0,3].



Input

Input contains the number N : denoting number of astronauts and and list L denoting the pairs of astronauts from the same country.

N = 5
vector<pair<int,int> > astronauts = {{0,1}, {2,3} , {0,4}};
Output

6

There are 6 ways to choose a pair (0,2) (0,3) (1,2) (1,3) (4,2) and (4,3) as astronauts (0,1,4) belong to country 1 and (2,3) belong to another.

*/

#include<bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int n;
        vector<int> *adjList;
        bool* visited;
    Graph(int n) {
        this->n = n;
        adjList = new vector<int>[n];
        visited = new bool[n]{false};
    }
    ~Graph() {
        delete[] adjList;
        delete[] visited;
    }
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    int DFS(int start) {
        visited[start]= true;
        int count = 1;
        for(auto neighbour : adjList[start]) {
            if(!visited[neighbour]) {
                count+= DFS(neighbour);
            }
        }
        return count;
    }
};

int count_pairs(int N, vector<pair<int,int> > astronauts){
    
    vector<int> countries;
    Graph g = Graph(N);
    for(auto p : astronauts) {
        g.addEdge(p.first,p.second);
        
    }
    for(int i=0; i<N;i++) {
        if(!g.visited[i]) {
            int connected_component = g.DFS(i);
            countries.push_back(connected_component);
        }
    }
    // calculate the answer
    int answer=0;
    for(int i =0; i<countries.size(); i++) {
        for( int j= i+1; j<countries.size(); j++) {
            answer= answer + countries[i]*countries[j];
        }
    }
    return answer;
}