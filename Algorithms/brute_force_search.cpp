#include <cstdio>
#include <algorithm>
using namespace std;

// 단순 전역 탐색(O(N^2))
// int main() {
//     int N, arr[1000];
//     scanf("%d", &N);
//     for (int i = 0; i < N; i++) 
//         scanf("%d", arr+i);

//     int result = 0;
//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//             if (i != j) result = max(result, arr[i] + arr[j]);
//     printf("\n%d\n", result);
// }

// 정렬 후 탐색(O(nlogn)
int main() {
    int N, arr[1000];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
        scanf("%d", arr+i);
    sort(arr, arr+N);
    printf("%d\n", arr[N-1] + arr[N-2]);
}