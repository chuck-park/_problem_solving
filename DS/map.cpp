#include<iostream>
#include<map>
using namespace std;

/*
 * Map
 * 딕셔너리 자료구조이다. 원소 삽입과 삭제, 탐색 등의 연산은 O(logn)을 보장한다.
*/

int main() {
    map<int, int> mp; // int형 key, int형 데이터를 자정하는 딕셔너리 자료구조 생성

    // (4, 5) 원소 삽입
    mp.insert(make_pair(4, 5));
    // 또는
    mp[5] = 6;

    printf("%d\n", mp[5]);
    printf("%d\n", mp.find(4)->second);
    printf("%d\n", mp.count(4));
    printf("%d\n", mp.size());
    mp.erase(++mp.begin());
    printf("%d\n", mp[5]);
    mp.clear();

    return 0;
}