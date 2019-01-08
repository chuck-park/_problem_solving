#include <cstdio>

int main()
{
    int N, num, answer;
    int cal = 0; // 계산한 결과값
    scanf("%d", &N);

    for(int i = 1; i < N; i++) {
		num = i;
        cal = num;

		// 계산
        while (num != 0) {
            cal += num % 10; // cal에 각 자리수 digit number 더해주기
            num /= 10; // 자리수 변경
        }
        
        // cal이 N과 일치하면 i값이 정답
        if (cal == N) {
        	answer = i;
            printf("%d\n", answer);
            return 0;
        }
    }
    printf("0\n"); // 백준 테스트 케이스 통과를 위해서는 마지막에 개행을 해줘야함
    return 0;
}
