#include <iostream>
#include <set>
using namespace std;

/*
 * set
 * 균형잡힌 이진트리이다. 원소 삽입과 삭제, 탐색 등의 연산은 O(log(n))을 보장한다.
 */

int main() {
    set<int> s;

    s.insert(5);

    // find는 해당 값을 가지는 원소의 주소값을 리턴, end는 마지막 주소를 리턴
    // 5의 값을 가지는 원소를 찾으면 1 아니면 0 리턴
    if(s.find(5) != s.end())
        printf("존재합니다.\n");
    else
        printf("없습니다.\n");

    printf("%d\n", s.size());
    s.clear();
    s.erase(++s.begin());
    return 0;
}