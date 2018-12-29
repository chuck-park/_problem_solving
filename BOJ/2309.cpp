#include <cstdio>
#include <algorithm>
using namespace std;

#define N 9

int main() {
	int d[N];
	int sum = 0;
	
	// 입력
	for (int i = 0; i < N; i++) {
		scanf("%d", d+i);
		sum += d[i];
	}
	
	// 계산
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (sum - d[i] - d[j] == 100) {
				d[i] = -1;
				d[j] = -1;
				break;
			}
		}
		if (d[i] == -1) // 여기가 3시간 날리게 만든 놓친 부분이었따...
			break;
	}

	sort(d, d+N);
	for (int i = 2; i < N; i++) {
		printf("%d\n", d[i]);
	}
	
	return 0;
}