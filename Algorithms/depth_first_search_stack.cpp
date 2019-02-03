#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph {
public:
    int N;
    vector<vector<int>> adj;
    vector<bool> visited;

    Graph(): N(0){}
    Graph(int n): N(n) {
        adj.resize(N);
        visited.resize(N);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortList() {
        for(int i=0; i<N; i++)
            reverse(adj[i].begin(), adj[i].end());
    }

    void dfs() {
        fill(visited.begin(), visited.end(), false);
        stack<int> s;
        s.push(0);
        visited[0] = true;

        while(!s.empty()) {
            int curr = s.top();
            s.pop();
            cout << curr << " is visited " << endl;

            for(int next: adj[curr]) {
                if(!visited[next]) {
                    s.push(next);
                    visited[next] = true;
                }
            }
        }
    }
};

int main() {
    Graph G(9);
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 5);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(2, 6);
    G.addEdge(2, 8);
    G.addEdge(6, 7);
    G.addEdge(6, 8);
    G.sortList();
    G.dfs();
}