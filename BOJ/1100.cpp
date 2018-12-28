#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	char c[8][9];
	for(int i=0;i<8;i++)
		scanf("%s", c[i]);
	int answer=0;
	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++)
			if ((i+j) % 2 == 0 && c[i][j] == 'F')//흰색
				answer++;
	printf("%d", answer);
}