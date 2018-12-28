#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int TestCase;
	scanf("%d", &TestCase);

	while(TestCase--) {
		int R, S;
		scanf("%d %s", &R, &S);
		printf("%s\n", S);
	}
	return 0;
}