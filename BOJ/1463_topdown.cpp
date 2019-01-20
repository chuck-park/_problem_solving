#include <cstdio>
#include <algorithm>
using namespace std;
int const MAX = 1000001;

int dp[MAX];

int f(int n) {
    if (n == 1) return 0; // base case
    if (dp[n] != -1) return dp[n]; // memoization

    int result = f(n-1) + 1;
    if (n%3 == 0) result = min(result, f(n/3) + 1);
    if (n%2 == 0) result = min(result, f(n/2) + 1);
    dp[n] = result;
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    fill(dp, dp+MAX, -1);
    printf("%d", f(N));
}