// 유기농 배추

#include <iostream>
#include <vector>

using namespace std;

int T;
int M, N, K; // 배추밭 col, row, 배추가 심어진 위치의 개수
int answer;
int x, y;
int map[50][50];
int dir[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}}; // 동서남북

void dfs(int x, int y) {
    map[x][y] = 0;

    for(int i=0; i<4; i++) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];

        if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;
        if(map[nextX][nextY] != 1) continue;

        dfs(nextX, nextY);
    }
}

int main() {

    cin >> T;

    for(int i=0; i<T; i++) {
        cin >> M >> N >> K;
        answer = 0;

        // map setting with 0
        for(int i=0; i<N; i++) { // row
            for(int j=0; j<M; j++) { // col
                map[i][j] = 0;
            }
        }

        // cabbage setting with 1
        for(int i=0; i<K; i++) {
            cin >> y >> x;
            map[x][y] = 1;
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] == 1) {
                    answer++;
                    dfs(i, j);
                }
            }
        }
//        // print all
//        for(int i=0; i<N; i++) {
//            cout << "\n";
//            for(int j=0; j<M; j++) {
//                cout << map[i][j] << " ";
//            }
//        }
//        cout << "\n";

        cout << answer << "\n";
    }
}