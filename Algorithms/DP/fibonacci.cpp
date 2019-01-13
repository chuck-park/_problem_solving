// fibonacci implemented with recursive, memoization

#include <cstdio>
#include <vector>
using namespace std;

vector<int> dp;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibonacci(n-2) + fibonacci(n-1);
    return dp[n];
}

int main() {

    int N;
    scanf("%d", &N);
    dp.resize(N+1, -1);
    printf("%d", fibonacci(N));

    return 0;
}