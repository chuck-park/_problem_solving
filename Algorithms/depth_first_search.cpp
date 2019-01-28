/*
 * 그래프(graph): 정점과 간선의 집합
 *
 * 정점(vertex): 값을 가지고 있는 한 점, Node라고도 부름
 * 간선(edge): 두 정점을 이어주는 선, 방향 유무, 가중치 유에 따라 다양한 그래프 형태 존재
 *
 * 무방향 그래프(undirected graph): 어느 방향으로든 이동할 수 있다
 *   인접(adjacent): 어떤 정점 A에서 간선 하나를 거쳐서 정점 B로 이동할 수 있
 * 방향 그래프(directed graph): 화살표 방항으로만 이동할 수 있다
 *   in degree: 나가는 간선의 수
 *   out degree: 들어오는 간선의 수
 *   cycle: 따라가다보면 다시 원점으로 돌아오는 경우
 *
 * 가중치 그래프(weighted grapth): 간선들에 가중치(비용(weight), 거리(distance),
 *   대역폭(bandwidth))가 있는 그래프
 *
 * multi graph: 똑같은 정점 쌍(A, B) 사이에 간선이 여러 개일 수 있는 그래프
 *
 * 연결 요소(component): 컴포넌트 하나 안에 속한 정점은 모두 이어져 있으며, 다른 컴포넌트 끼리는 이어져 있지 않음
 *   컴포넌트는 항상 최대의 크기여야 함
 *
 * 연결 그래프(connected graph)는 그래프의 컴포넌트가 단 하나인 경우. 모든 정점이 연결되어있는 경우
 *
 * 깊이 우선 탐색(Depth-Frist Search): 한 우물만 깊게 파다가 막히면 그제서야 돌아가서 다른 우물을 파는 성향
 *   dfs를 한 번 하면 다 끝나더라도 시작점이 속한 컴포넌트의 정점들만 다 방문하고, 나머지는 방문하지 못함
 *   따라서 모든 정점을 방문하려면 각 컴포넌트에 속한 정점들 중 하나씩은 방문 시도를 해주어야함
 *   구현할 때는 반복문을 돌면서 방문하지 않은 정점을 볼 때마다 dfs를 시작주는 것
 *   이때 방문을 시도하는 횟수가 컴포넌트의 개수가 됨
 * DFS 시간복잡도: O(V+E)
 * 만약 인접리스트가 없고 인접 행렬만 있다면: O(v^2)
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Graph {
public:
    int N; // 정점의 개수
    vector<vector<int>> adj; // 인접 리스트, 각 정점마다 인접한 정점들을 보존하는 리스트
    vector<bool> visited; // 방문 여부를 저장하는 배열

    // 생성자
    Graph(): N(0){}
    Graph(int n): N(n){
        adj.resize(N);
        visited.resize(N);
    }

    // 간선 추가 함수(무향 그래프이므로 양쪽 방향으로 추가)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 번호가 작은 정점부터 방문하기 위한 함수
    void sortList() {
        for(int i=0; i<N; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int dfsAll() {
        int components = 0;
        fill(visited.begin(), visited.end(), false); // 방문 여부 리스트를 false로 초기화

        for(int i=0; i<N; i++) {
            if(!visited[i]) {
                cout << "-- new DFS begins --" << "\n";
                int nodes = dfs(i); // 0부터 dfs 시작(오버로딩 된 dfs로 재귀함수 시작)
                components++;
                cout << "size: " << nodes << "\n";
            }
        }
        return components;
    }

private:
    // 오버로딩 된 dfs로 재귀함수
    // 재귀함수도 스택 메모리 공간에 쌓아올려지는 구조이므로 방문하면 스택에 그 정점이 쌓이고, 가장 위의 노드를 꺼내 방문
    // 더 이상 방문할 곳이 없으면 스택에서 정점을 빼고 바로 아래 정점 함수로 복귀
    int dfs(int curr) {
        int nodes = 1;
        visited[curr] = true;
        cout << "node " << curr << " visited" << "\n";
        for(int next: adj[curr])
            if(!visited[next]) nodes += dfs(next); // 아직 방문한적 없는 노드를 순차적으로 dfs
        return nodes;
    }
};

int main() {
    Graph G(10);
    G.addEdge(0, 1);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(4, 6);
    G.addEdge(5, 7);
    G.addEdge(5, 8);
    G.addEdge(7, 8);
    G.sortList();
    int components = G.dfsAll();
    cout << "The number of component is " << components << "\n";
}