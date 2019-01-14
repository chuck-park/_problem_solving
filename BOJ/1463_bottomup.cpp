#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1000001;

int main() {
    int N, dp[MAX];
    scanf("%d", &N);

    fill(dp, dp+MAX, 1000000000);
    dp[1] = 0;
    for (int i=1; i<N; i++) {
        dp[i+1] = min(dp[i+1], dp[i]+1);
        if(i*2 < MAX) dp[i*2] = min(dp[i*2], dp[i]+1);
        if(i*3 < MAX) dp[i*3] = min(dp[i*3], dp[i]+1);
    }

    printf("%d", dp[N]);
}