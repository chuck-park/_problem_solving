#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N, myMax = 0;

int countMax(int i, int j) {
	if (i < j) return j;
	return i;
}

int cal(vector<vector<char>> v, int i, int j) {
	int count = 1;
	
	// swap vertically
	// printf("v[%d][%d] <-> v[%d][%d]: %c <-> %c\n", i, j, i, j+1, v[i][j], v[i][j+1]);
	char temp = v[i][j];
	v[i][j] = v[i][j+1];
	v[i][j+1] = temp;
	
	// count vertically
	// printf("count vertically\n");
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			// printf("v[%d][%d] == v[%d][%d]: %c, %c\n", i, j, i, j+1, v[i][j], v[i][j+1]);
			if (v[i][j] == v[i][j+1]) {
				count++;
				// printf("count: %d\n", count);
			} else {
				myMax = countMax(myMax, count);
				count = 1;
			}
		}
	}
	
	// count horizontally
	// printf("count horizontally\n");
	for (int i = 0; i < N; i++) {
		count = 1; 
		for (int j = 0; j < N; j++) {
			// printf("v[%d][%d] == v[%d][%d]: %c, %c\n", j, i, j+1, i, v[j][i], v[j+1][i]);
			if (v[j][i] == v[j+1][i]) {
				count++;
				// printf("count: %d\n", count);
			} else {
				myMax = countMax(myMax, count);
				count = 1;
			}
		}
	}
	
	// swap horizontally
	// printf("v[%d][%d] <-> v[%d][%d]: %c <-> %c\n", i, j, i, j+1, v[i][j], v[i][j+1]);
	temp = v[j][i];
	v[j][i] = v[j+1][i];
	v[j+1][i] = temp;
	
	// count vertically
	// printf("count vertically\n");
	for (int i = 0; i < N; i++) {
		count = 1;
		for (int j = 0; j < N; j++) {
			// printf("v[%d][%d] == v[%d][%d]: %c, %c\n", i, j, i, j+1, v[i][j], v[i][j+1]);
			if (v[i][j] == v[i][j+1]) {
				count++;
				// printf("count: %d\n", count);
			} else {
				myMax = countMax(myMax, count);
				count = 1;
			}
		}
	}
	
	// count horizontally
	// printf("count horizontally\n");
	for (int i = 0; i < N; i++) {
		count = 1; 
		for (int j = 0; j < N; j++) {
			// printf("v[%d][%d] == v[%d][%d]: %c, %c\n", j, i, j+1, i, v[j][i], v[j+1][i]);
			if (v[j][i] == v[j+1][i]) {
				count++;
				// printf("count: %d\n", count);
			} else {
				myMax = countMax(myMax, count);
				count = 1;
			}
		}
	}
	
	return myMax;
}

int main() {
	int result;
	cin >> N;
	vector<vector<char>> v(N+1, vector<char>(N+1));
	
	// 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}
	
	// 계산
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			cal(v, i, j);
		}
	}
	
	// printf("result\n");
	printf("%d\n", myMax);
    
    return 0;
}
