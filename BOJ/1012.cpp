#include <iostream>
#include <vector>
using namespace std;

#define MAX 51
int M, N, K;
int farm[MAX][MAX];

// 동서남북
int dirR[4]{0, 0, 1, -1};
int dirC[4]{1, -1, 0, 0};

void dfs(int r, int c) {
    farm[r][c] = 0; // 이미 방문한 곳은 0으로 변경해서 중복 방문 방지

    for(int i=0; i<4; i++) {
        int nextR = r + dirR[i];
        int nextC = c + dirC[i];

        // 예외처리
        if(nextR < 0 || nextR > N || nextC < 0 || nextC > M) continue;
        if(farm[nextR][nextC] == 0) continue;
        dfs(nextR, nextC);
    }
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int warm = 0;
        cin >> M >> N >> K;

        for(int i=0; i<K; i++) {
            int r, c;
            cin >> c >> r;
            farm[r][c] = 1;
        }

        for(int i=0; i<N; i++) {
            for(int j = 0; j < M; j++) {
                if(farm[i][j] != 0) {
                    // print all
//                    for (int i = 0; i < N; i++) {
//                        for (int j = 0; j < M; j++) {
//                            cout << farm[i][j] << " ";
//                        }
//                        cout << "\n";
//                    }
//                    cout << "\n";
                    warm++;
                    dfs(i, j);
                }
            }
        }
        cout << warm << "\n";
    }
}