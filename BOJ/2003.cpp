#include <cstdio>
using namespace std;

int main() {
    int N, M, arr[10000];
    int sum = 0, result = 0, s = 0, e = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    	scanf("%d", arr+i);
    
    while(s < N) {
    	if (sum >= M) 
    		sum -= arr[s++];
    	else if(e == N) 
    		break;
    	else 
    		sum += arr[e++];
    		
    	if (sum == M) 
    		result++;
    }
    printf("%d", result);
    return 0;
}