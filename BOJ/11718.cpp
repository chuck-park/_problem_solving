#include <cstdio>
#include <string>
using namespace std;
 
int main() {
    char c;
 
    // while은 true(1), false(0)로 실행 체크
    // ~eof == ~-1 == ~0xFFFFFFFF == 0x00000000 == 0
    while(~scanf("%c", &c)) {
        printf("%c", c);
    }
}
