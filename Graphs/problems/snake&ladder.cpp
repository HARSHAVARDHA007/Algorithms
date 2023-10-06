#include<bits/stdc++.h>
using namespace std;

class Board {
    public:
    int n;
    list<int>* next_steps;
    Board(int N) {
        n = N;
        next_steps = new list<int>[N+1];
    }
    
    ~Board() {
        delete[] next_steps;
    }
    
    void add_edge(int source , int destination) {
        next_steps[source].push_back(destination);
    }
    
    void printBoard() {
        for( int i=0; i<n; i++) {
            cout << i << " -> ";
            for(auto neighbour : next_steps[i]) {
                cout<< neighbour << " -> ";
            }
            cout<< endl;
        }
    }
    
    int bfs(int source , int destination) {
        bool* visited = new bool[n+1]{false};
        queue<pair<int,int>> q;
        visited[source] = true;
        q.push(make_pair(source,0));
        while(!q.empty()) {
            auto curr_node = q.front();
            q.pop();
            if(curr_node.first == destination) {
                delete[] visited;
                return curr_node.second - 1;
            }
            for( auto neighbour : next_steps[curr_node.first]) {
                // Take each neighbour and add it to the queue
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    q.push(make_pair(neighbour, curr_node.second + 1));
                }
            }
            
        }
        return -1;
    }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    Board b = Board(n);
    for( auto snake : snakes) {
        b.add_edge(snake.first , snake.second);
    }
    for(auto ladder : ladders) {
        b.add_edge(ladder.first , ladder.second);
    }
    // Add possible edges for remaning nodes except for ladders and snakes
    for(int i=1; i<=n; i++) {
        if(!b.next_steps[i].size()){
            for( int j=1; j<=6; j++) {
                if(i+j <= n) {
                    b.add_edge(i, i+j);
                }
            }
        }
    }
    int ans = b.bfs(1, n);
    return ans;
    
}
