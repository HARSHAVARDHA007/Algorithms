//problem link : https://leetcode.com/problems/word-ladder/description/
#include<bits/stdc++.h>
using namespace std;
class Graph {
    public:
    unordered_map<string,int>mp;
    list<string>* adjList;
    bool* visited;
    Graph(vector<string>words) {
        for(int i=1; i<=words.size();i++) {
            mp[words[i-1]] = i;
        }
        adjList = new list<string>[words.size()+1];
        visited = new bool[words.size()+1]{false};
    }
    
    void addEdge(string word_1 , string word_2) {
        adjList[mp[word_1]].push_back(word_2);
        adjList[mp[word_2]].push_back(word_1);
    }
    
    int BFS(string source, string destination) {
        queue<pair<int,int>>q;
        q.push(make_pair(mp[source],0));
        visited[mp[source]] = true;
        while(!q.empty()) {
            auto curr_node = q.front();
            q.pop();
            if(curr_node.first == mp[destination]) {
                return curr_node.second + 1;
            }
            for(auto neighbour : adjList[curr_node.first]) {
                if(!visited[mp[neighbour]]) {
                    visited[mp[neighbour]] = true;
                    q.push(make_pair(mp[neighbour], curr_node.second + 1));
                }
            }
        }
        return 0;
    }
};
class Solution {
public:

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //check if beginWord and endWord are inside the wordList
        int b_pre = 0;
        for(auto word : wordList) {
            if(word == beginWord) {
                b_pre = 1;
            }
        }
        if(!b_pre) {
            wordList.push_back(beginWord);
        }
        
        // Create the Graph
        Graph g = Graph(wordList);
        for(int i =0; i<wordList.size(); i++) {
            for(int j = i+1; j<wordList.size(); j++) {
                // if between 2 words only 1 alphabet is different add edge between them
                int count =0;
                for(int z=0; z<wordList[i].size(); z++) {
                    if(wordList[i][z] != wordList[j][z]) {
                        count++;
                    }
                }
                if(count == 1) {
                    g.addEdge(wordList[i],wordList[j]);
                }
            }
        }
        return g.BFS(beginWord,endWord);
            
    }
};