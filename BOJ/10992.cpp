#include <iostream>
#include <cstdio>
using namespace std;

int main() {

    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N-i-1; j++) {
            printf(" ");
        }

        // 첫번째 줄인 경우
        if(i == 0) {
            printf("*\n");
        }
        // 맨 마지막 줄인 경우
        else if(i == N-1) {
            for(int j=0; j<N*2-1; j++) {
                printf("*");
            }
        }
        // 첫번째와 마지막 줄 이외의 경우
        else {
            printf("*");
            for(int k=0; k<i*2-1; k++) {
                printf(" ");
            }
            printf("*\n");
        }
    }
}