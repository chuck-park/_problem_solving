// fibonacci implemented with recursive, memoization

#include <cstdio>
#include <vector>
using namespace std;

vector<int> dp;

// recursive
int fibonacci_1(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibonacci_1(n-2) + fibonacci_1(n-1);
    return dp[n];
}

// loop
int fibonacci_2(int n) {
    vector<int> dp2(n+1, 0);
    dp2[1] = 1;
    if (n == 0) return dp2[0];
    if (n == 1) return dp2[1];
    for (int i=2; i<n+1; i++) {
        dp2[i] = dp2[i-2] + dp2[i-1];
    }
    return dp2[n];
}

int main() {

    int N;
    scanf("%d", &N);
    dp.resize(N+1, -1);
    printf("%d", fibonacci_2(N));

    return 0;
}