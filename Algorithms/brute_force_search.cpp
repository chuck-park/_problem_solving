#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int N, arr[1000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", arr+i);

    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j) result = max(result, arr[i] + arr[j]);
    printf("\n%d\n", result);
}