#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d",&T);
	while(T--){
		int R;
		string S;
		cin>>R>>S;
		for(int i=0;i<S.size();i++)
			for(int j=0;j<R;j++)
				printf("%c",S[i]);
		printf("\n");
	}
	return 0;
}