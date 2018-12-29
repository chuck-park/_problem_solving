#include <cstdio>
using namespace std;

int max(int a, int b) {
	if(a > b) return a;
	return b;
}

int main() {
    int N, arr[100001];
    int sumArr[100001]; 
    int result = 0;
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    	scanf("%d", arr+i);
 
	sumArr[0] = arr[0];
	result = arr[0];
    for(int i = 1; i < N; i++) {
    	sumArr[i] = max(sumArr[i - 1] + arr[i], arr[i]);
    	result = max(result, sumArr[i]);
    }
    printf("%d", result);
    return 0;
}